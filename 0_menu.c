#include <stdio.h>
#include "functions.h"

int menu(void) {
  char select = 'n';

  do {
    printf("\nInforme o programa a ser executado (1-8):\n"
            "1 - Cadastrar\n"
            "2 - Listar\n"
            "3 - Excluir\n"
            "4 - Alterar\n"
            "0 - Sair\n> ");
    scanf(" %c", &select);

    switch (select) {
      case '0' :
        break;
      case '1' :
        printf("\n# 1 - Módulo de Cadastro\n");
        cadastro();
        break;
      case '2' :
        printf("\n# 2 - Módulo Listar\n");
        // questao2();
        break;
      case '3' :
        printf("\n# 3 - Módulo Excluir\n");
        // registrar();
        break;
      case '4' :
        printf("\n# 4 - Módulo Alterar\n");
        // idades();
        break;
    }
  } while (select != '0');

  printf("Saindo.\n");

  return 0;
}