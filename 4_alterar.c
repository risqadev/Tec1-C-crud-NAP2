#include <stdio.h>
#include <string.h>
#include "exports.h"

FILE *db, *temp;

int alterar(void) {
  // declara as variáveis
  unsigned int j=0;
  char save = 'n';
  emp current;
  emp change;

  // abre os arquivos
  temp = fopen(TEMP_FILENAME, "w");
  db = fopen(DB_FILENAME, "r");
  if(temp == NULL || db == NULL) {
    printf("filecheck: Problema na abertura ou criação dos arquivos.\n");
    return -1;
  }

  // solicita as entradas
  printf("Matrícula nº: ");
  scanf("%u", &change.id);
  clearBuf();

  printf("Novo nome:  ");
  scanf(" %[^\n]", change.name);
  clearBuf();

  printf("Novo e-mail:  ");
  scanf("%s", change.email);
  clearBuf();

  printf("Nova data de admissão (dd/mm/aaaa):  ");
  scanf("%s", change.admission);
  clearBuf();

  printf("Novo salário:  ");
  scanf("%f", &change.salary);
  clearBuf();

  // exibe as alterações para confirmação
  printf("\nALTERAÇÃO DE CADASTRO:\n"
        "Matrícula: %u\n"
        "Novo nome: %s\n"
        "Novo e-mail: %s\n"
        "Nova data de admissão: %s\n"
        "Novo salário: R$ %.2f\n",
        change.id, change.name, change.email, change.admission, change.salary);

  // solicita confirmação
  printf("\nGravar? (s/N):  ");
  scanf("%[^\n]c", &save);
  clearBuf();

  // checa a confirmação
  if (save == 's' || save == 'S') {
    // percorre o banco de dados em busca do registro pela matrícula
    for (int i = 0; i < nRg; i++) {
      fscanf(db, "%u    %f    %s    %s    %[^\n]", &current.id, &current.salary, current.email, current.admission, current.name);

      if(current.id == change.id) {
        // se a matrícula corresponde, escreve o registro alterado no arquivo temporário
        fprintf(temp, "%u    %.2f    %s    %s    %s\n",
          change.id, change.salary, change.email, change.admission, change.name);
        ++j;
      } else {
        // se a matrícula não corresponde o registro é escrito sem alteração no arquivo temporário
        fprintf(temp, "%u    %.2f    %s    %s    %s\n",
          current.id, current.salary, current.email, current.admission, current.name);
      }
    }
  }

  // fecha os arquivos
  fclose(temp);
  fclose(db);

  // exibe mensagem dependendo da situação
  if (save == 'n') {
    // se o usuário cancelou a alteração
    printf("Operação cancelada.\n");
  } else if (save == 's' && j == 0) {
    // se o registro não foi encontrado
    printf("Nenhum registro encontrado com essa matrícula.\n");
  } else {
    // se o registro foi encontado
    rwDb(); // reescreve o arquivo de persistência das informações
    printf("Registro encontrado e alterado.\n");
  }

  // remove o arquivo temporário
  remove(TEMP_FILENAME);

  return 0;
}