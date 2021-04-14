#include <stdio.h>
#include <string.h>
#include "exports.h"

FILE *db, *temp;

int alterar(void) {
  unsigned int j=0;
  char save = 'n';
  emp current;
  emp change;

  temp = fopen(TEMP_FILENAME, "w");
  db = fopen(DB_FILENAME, "r");
  if(temp == NULL || db == NULL) {
    printf("filecheck: Problema na abertura ou criação dos arquivos.\n");
    return -1;
  }

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

  printf("\nALTERAÇÃO DE CADASTRO:\n"
        "Matrícula: %u\n"
        "Novo nome: %s\n"
        "Novo e-mail: %s\n"
        "Nova data de admissão: %s\n"
        "Novo salário: R$ %.2f\n",
        change.id, change.name, change.email, change.admission, change.salary);

  printf("\nGravar? (s/N):  ");
  scanf("%[^\n]c", &save);
  clearBuf();

  if (save == 's' || save == 'S') {
    for (int i = 0; i < nRg; i++) {
      fscanf(db, "%u    %f    %s    %s    %[^\n]", &current.id, &current.salary, current.email, current.admission, current.name);

      if(current.id == change.id) {
        fprintf(temp, "%u    %.2f    %s    %s    %s\n",
          change.id, change.salary, change.email, change.admission, change.name);
        ++j;
      } else {
        fprintf(temp, "%u    %.2f    %s    %s    %s\n",
          current.id, current.salary, current.email, current.admission, current.name);
      }
    }
  }

  fclose(temp);
  fclose(db);

  if (save == 'n') {
    printf("Operação cancelada.\n");
  } else if (save == 's' && j == 0) {
    printf("Nenhum registro encontrado com essa matrícula.\n");
  } else {
    rwDb();
    printf("Registro encontrado e alterado.\n");
  }

  remove(TEMP_FILENAME);

  return 0;
}