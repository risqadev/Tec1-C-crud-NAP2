#include <stdio.h>
#include "exports.h"

int listar(void) {
  emp current; // cria a variável current, do tipo estruturado emp, para guardar as informações do registro que está sendo inserido

  // abre o arquivo no modo de leitura
  FILE *db;
  db = fopen(DB_FILENAME, "r");
  if(db == NULL) {
    printf("Problema na abertura do arquivo.\n");
    return -1;
  }

  // percorre o arquivo listando os registros na saída
  for (int i = 0; i < nRg; i++) {
		fscanf(db, "%u    %f    %s    %s    %[^\n]", &current.id, &current.salary, current.email, current.admission, current.name);
    printf("\nMatrícula nº %u\n"
          "Nome: %s\n"
          "E-mail: %s\n"
          "Data de admissão: %s\n"
          "Salário: %.2f\n"
          , current.id, current.name, current.email, current.admission, current.salary);
	}

  // fecha o arquivo
  fclose(db);

  return 0;
}