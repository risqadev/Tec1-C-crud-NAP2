#include <stdio.h>
#include "exports.h"

int menu(void) {
  char select = 'n';

  do {
    printf("\nSelecione o módulo:\n"
            "1 - Cadastrar\n"
            "2 - Listar\n"
            "3 - Excluir\n"
            "4 - Alterar\n"
            "0 - Sair\n> ");
    scanf(" %c", &select);
    clearBuf();

    switch (select) {
      case '0' :
        break;
      case '1' :
        printf("\n# 1 - Módulo Cadastro\n");
        cadastro();
        break;
      case '2' :
        printf("\n# 2 - Módulo Listar\n");
        listar();
        break;
      case '3' :
        printf("\n# 3 - Módulo Excluir\n");
        excluir();
        break;
      case '4' :
        printf("\n# 4 - Módulo Alterar\n");
        alterar();
        break;
    }
  } while (select != '0');

  printf("Saindo.\n");

  return 0;
}