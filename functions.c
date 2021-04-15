#include <stdio.h>
#include <string.h>
#include "exports.h"

FILE *db, *counts, *temp;

// limpa o buffer de entrada
void clearBuf(void) {
  char c;
  while((c = getchar()) != '\n' && c != EOF);
}

// reescreve o arquivo de banco de dados com base no arquivo temporário
int rwDb() {
  db = fopen(DB_FILENAME, "w");
  temp = fopen(TEMP_FILENAME, "r");

  int c;
   while ((c = fgetc(temp)) != EOF)
       fputc(c, db);

  fclose(db);
  fclose(temp);

  return 0;
}

// cria os arquivos iniciais (counts e database) se eles não existirem
int filesCreate(void) {
  printf("filecheck: Criando arquivos.\n");

  db = fopen(DB_FILENAME, "w");
  counts = fopen(COUNTS_FILENAME, "w");

  if(db == NULL || counts == NULL) {
    printf("filecheck: Problema na criação do arquivo.\n");
    return -1;
  }

  fprintf(counts, "0 0");

  return 0;
}

// checa se os arquivos iniciais (counts e database) existem
int dbCheck(void) {
  db = fopen(DB_FILENAME, "r");
  counts = fopen(COUNTS_FILENAME, "r");

  if(db == NULL || counts == NULL) {
    filesCreate();
  }

  fscanf(counts, "%u %u", &nRg, &lastId);

  fclose(db);
  fclose(counts);

  return 0;
}

// reescreve o arquivo de contagens quando necessário
int rwCounts (void) {
  counts = fopen(COUNTS_FILENAME, "w");

  if(db == NULL || counts == NULL) {
    printf("filecheck: Problema na criação do arquivo.\n");
    return -1;
  }

  fprintf(counts, "%u %u", nRg, lastId);

  fclose(counts);

  return 0;
}

// verifica se um registro já existe pelo nome
_Bool searchByName (const char *s) {
  db = fopen(DB_FILENAME, "r");
  emp curr;

  for (int i = 0; i < nRg; i++) {
		fscanf(db, "%u    %f    %s    %s    %[^\n]", &curr.id, &curr.salary, curr.email, curr.admission, curr.name);
    if(strcmp(s, curr.name) == 0) {
      fclose(db);
      return 1;
    }
	}

  fclose(db);

  return 0;
}