#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exports.h"

int cadastro(void) {
  char save = 'n';
  emp current; // cria a variável current, do tipo estruturado emp, para guardar as informações do registro que está sendo inserido

  current.id = lastId+1;

   // pede a inserção do nome
  printf("Nome:  ");
  scanf(" %[^\n]", current.name);
  clearBuf();

  // pede a inserção do e-mail
  printf("E-mail:  ");
  scanf("%s", current.email);
  clearBuf();

  // pede a inserção da data de admissão
  printf("Data de admissão (dd/mm/aaaa):  ");
  scanf("%s", current.admission);
  clearBuf();

  // pede a inserção do salário
  printf("Salário:  ");
  scanf("%f", &current.salary);
  clearBuf();

  // exibe as informações inseridas
  printf("\nCADASTRO:\n"
        "Matrícula: %u\n"
        "Nome: %s\n"
        "E-mail: %s\n"
        "Data de admissão: %s\n"
        "Salário: R$ %.2f\n",
        current.id, current.name, current.email, current.admission, current.salary);

  // busca para ver se o nome já existe
  if (searchByName(current.name)) {
    // se existe
    printf("\nATENÇÃO! Este funcionário já está cadastrado!\n");
  } else {
    // se não existe, pede confirmação antes de gravar
    printf("\nGravar? (s/N):  ");
    scanf("%[^\n]c", &save);
    clearBuf();
  }

  // verifica se o usuário confirmou a gravação do registro
  if (save == 's' || save == 'S') {
    FILE *db;

    db = fopen(DB_FILENAME, "a+");
    
    if(db == NULL) {
      printf("Problema na abertura do arquivo.\n");
      return -1;
    }

    fprintf(db, "%u    %.2f    %s    %s    %s\n",
            current.id, current.salary, current.email, current.admission, current.name);

    printf("Registro gravado com sucesso.\n");

    ++nRg; // incrementa a variável que conta os registros
    ++lastId; // incrementa a variável que guarda o número a última matrícula atribuída (para autoincrementar a próxima)
    rwCounts(); // persiste os contadores acima

    // fecha o arquivo
    fclose(db);
  }

  return 0;
}