#include <stdio.h>
#include "exports.h"

FILE *db;

int listar(void) {
  db = fopen(DB_FILENAME, "r");
  emp curr;

  for (int i = 0; i < nRg; i++) {
		fscanf(db, "%u    %f    %s    %s    %[^\n]", &curr.id, &curr.salary, curr.email, curr.admission, curr.name);
    printf("\nMatrícula nº %u\n"
          "Nome: %s\n"
          "E-mail: %s\n"
          "Data de admissão: %s\n"
          "Salário: %.2f\n"
          , curr.id, curr.name, curr.email, curr.admission, curr.salary);
	}
  // clearBuf();

  fclose(db);

  return 0;
}