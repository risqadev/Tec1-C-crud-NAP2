#include <stdio.h>
#include <string.h>
#include "exports.h"

FILE *db, *temp;

int excluir(void) {
  // declara as variáveis
  unsigned int id, j=0;
  emp current;

  // abre os arquivos que serão usados
  temp = fopen(TEMP_FILENAME, "w"); // arquivo temporário
  db = fopen(DB_FILENAME, "r");
  if(temp == NULL || db == NULL) {
    printf("filecheck: Problema na abertura ou criação dos arquivos.\n");
    return -1;
  }

  // solicita o número de matrícula do registro que será excluído
  printf("Informe o número de matrícula a ser excluído: ");
  scanf("%u", &id);
  clearBuf();

  // percorre o arquivo de dados buscando e excluindo o registro correspondente
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

  // fecha os arquivos abertos
  fclose(temp);
  fclose(db);

  // checa se houve algum registro excluído
  if (j == 0) {
    // se não houve registro exluído
    printf("Nenhum registro encontrado com essa matrícula.\n");
  } else {
    // se houve registro exluído
    rwDb();
    --nRg;
    rwCounts();
    printf("Registro encontrado e excluído.\n");
  }

  // remove o arquivo temporário criado
  remove(TEMP_FILENAME);

  return 0;
}