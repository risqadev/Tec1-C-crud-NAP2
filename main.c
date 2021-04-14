#include <stdio.h>
#include "exports.h"

int main(void) {

  printf("\n#####################################\n"
        "\nUniversidade Federal Rural da Amazônia\n"
        "Curso: Sistemas de Informação\n"
        "Disciplina: Técnicas de Programação I\n"
        "Professor: Edvar Oliveira\n"
        "Projeto avaliativo referente ao 2º NAP\n"
        "Desenvolvido em abril/2021\n"
        "\nAluno: Ricardo Santana Camacho  Mat.: 2020004628\n"
        "\n#####################################\n"
        "\nBem vindo ao sistema de recursos humanos!\n");

  dbCheck(); // verifica ou cria os arquivos para persistência
  
  menu(); // chama o menu
  
  return 0;
}