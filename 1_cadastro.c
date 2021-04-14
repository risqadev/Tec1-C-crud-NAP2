#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exports.h"

int cadastro(void) {
  char save = 'n';
  emp current;

  current.id = lastId+1;

  printf("Nome:  ");
  scanf(" %[^\n]", current.name);
  clearBuf();

  printf("E-mail:  ");
  scanf("%s", current.email);
  clearBuf();

  printf("Data de admissão (dd/mm/aaaa):  ");
  scanf("%s", current.admission);
  clearBuf();

  printf("Salário:  ");
  scanf("%f", &current.salary);
  clearBuf();

  printf("\nCADASTRO:\n"
        "Matrícula: %u\n"
        "Nome: %s\n"
        "E-mail: %s\n"
        "Data de admissão: %s\n"
        "Salário: R$ %.2f\n",
        current.id, current.name, current.email, current.admission, current.salary);

  if (searchByName(current.name)) {
    printf("\nATENÇÃO! Este funcionário já está cadastrado!\n");
  } else {
    printf("\nGravar? (s/N):  ");
    scanf("%[^\n]c", &save);
    clearBuf();
  }

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

    ++nRg;
    ++lastId;
    rwCounts();

    fclose(db);
  }

  return 0;
}