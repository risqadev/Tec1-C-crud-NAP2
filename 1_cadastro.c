#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exports.h"

int cadastro(void) {
  char save = 'n';
  FILE *db;
  emp employee;

  db = fopen(DB_FILE, "a+");

  printf("Nº MATRÍCULA:  ");
  scanf("%u", &employee.id);

  printf("NOME:  ");
  scanf(" %[^\n]", employee.name);

  printf("EMAIL:  ");
  scanf("%s", employee.email);

  printf("SALÁRIO:  ");
  scanf("%f", &employee.salary);

  printf("DATA DE ADMISSÃO (dd/mm/aaaa):  ");
  scanf("%s", employee.admission);

  printf("\nCADASTRO:\n"
        "Matrícula: %d\n"
        "Nome: %s\n"
        "E-mail: %s\n"
        "Salário: R$ %.2f\n"
        "Data de admissão: %s\n",
        employee.id, employee.name, employee.email, employee.salary, employee.admission);
  
  printf("\nGravar? (s/N):  ");
  scanf(" %c", &save);

  if (save == 's' || save == 'S') {
    // printf("chamar função de gravação");
    fprint(employee, db);
  }

  fclose(db);

  return 0;
}