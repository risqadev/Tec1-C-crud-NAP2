#include <stdio.h>
#include "exports.h"

int main(void) {

  printf("################\n"
        "Universidade Federal Rural da Amazônia\n"
        "Disciplina: Técnicas de Programação I\n"
        "Projeto avaliativo referente ao 2º NAP\n"
        "Aluno: Ricardo Santana Camacho\n"
        "Desenvolvido em abril/2021\n"
        "################\n"
        "\nBem vindo ao sistema de recursos humanos!\n");

  dbRead();
  
  menu(); // chama o menu principal
  
  return 0;
}