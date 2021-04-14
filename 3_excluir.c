#include <stdio.h>
#include <string.h>
#include "exports.h"

FILE *db, *temp;

int excluir(void) {
  unsigned int id, j=0;
  emp current;

  temp = fopen(TEMP_FILENAME, "w");
  db = fopen(DB_FILENAME, "r");
  if(temp == NULL || db == NULL) {
    printf("filecheck: Problema na abertura ou criação dos arquivos.\n");
    return -1;
  }

  printf("Informe o número de matrícula a ser excluído: ");
  scanf("%u", &id);
  clearBuf();

  for (int i = 0; i < nRg; i++) {
		fscanf(db, "%u    %f    %s    %s    %[^\n]",
          &current.id, &current.salary, current.email, current.admission, current.name);

    if(current.id == id) {
      ++j;
    } else {
      fprintf(temp, "%u    %.2f    %s    %s    %s\n",
          current.id, current.salary, current.email, current.admission, current.name);
    }
	}

  fclose(temp);
  fclose(db);

  if (j == 0) {
    printf("Nenhum registro encontrado com essa matrícula.\n");
  } else {
    rwDb();
    --nRg;
    rwCounts();
    printf("Registro encontrado e excluído.\n");
  }

  remove(TEMP_FILENAME);

  return 0;
}