#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exports.h"

int cadastro(void) {
  char save = 'n';
  FILE *db;
  emp employee;

  db = fopen(DB_FILENAME, "a+");

  employee.id = lastId+1;

  printf("NOME:  ");
  scanf(" %[^\n]", employee.name);
  clearBuf();

  printf("EMAIL:  ");
  scanf("%s", employee.email);
  clearBuf();

  printf("DATA DE ADMISSÃO (dd/mm/aaaa):  ");
  scanf("%s", employee.admission);
  clearBuf();

  printf("SALÁRIO:  ");
  scanf("%f", &employee.salary);
  clearBuf();

  printf("\nCADASTRO:\n"
        "Matrícula: %u\n"
        "Nome: %s\n"
        "E-mail: %s\n"
        "Data de admissão: %s\n"
        "Salário: R$ %.2f\n",
        employee.id, employee.name, employee.email, employee.admission, employee.salary);

  if (searchByName(employee.name)) {
    printf("\nATENÇÃO! Este nome já existe!\n");
  } else {
    printf("\nGravar? (s/N):  ");
    scanf("%[^\n]c", &save);
    clearBuf();
  }
  

  if (save == 's' || save == 'S') {
    fprintf(db, "%u    %.2f    %s    %s    %s\n",
            employee.id, employee.salary, employee.email, employee.admission, employee.name);
    printf("Registro gravado com sucesso.\n");
    rwCounts();
  }

  fclose(db);

  return 0;
}