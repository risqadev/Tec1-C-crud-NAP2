#include <stdio.h>
#include <string.h>
#include "exports.h"

FILE *db;
FILE *counts;

void clearBuf(void) {
  char c;
  while((c = getchar()) != '\n' && c != EOF);
}

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

int dbRead(void) {
  db = fopen(DB_FILENAME, "r");
  counts = fopen(COUNTS_FILENAME, "r");

  if(db == NULL || counts == NULL) {
    filesCreate();
  }

  fscanf(counts, "%u %u", &nRg, &lastId);

  // printf("%u %u", nRg, lastId);

  fclose(db);
  fclose(counts);

  return 0;
}

int rwCounts (void) {
  counts = fopen(COUNTS_FILENAME, "r+");

  if(db == NULL || counts == NULL) {
    printf("filecheck: Problema na criação do arquivo.\n");
    return -1;
  }

  // printf("%u %u", nRg, lastId);

  ++nRg;
  ++lastId;

  // printf("%u %u", nRg, lastId);

  fprintf(counts, "%u %u", nRg, lastId);

  fclose(counts);

  return 0;
}

_Bool searchByName (const char *s) {
  db = fopen(DB_FILENAME, "r");
  emp curr;

  // printf("%s", s);

  for (int i = 0; i < nRg; i++) {
		fscanf(db, "%u    %f    %s    %s    %[^\n]", &curr.id, &curr.salary, curr.email, curr.admission, curr.name);
    if(strcmp(s, curr.name) == 0) {
      printf("\nNome já existe.\n");
      fclose(db);
      return 1;
    }
	}

  fclose(db);

  return 0;
}