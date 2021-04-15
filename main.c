#include <stdio.h>
#include "exports.h"

int main(void) {

  printf("\n#####################################\n"
        "Universidade Federal Rural da Amazônia\n"
        "Curso: Sistemas de Informação\n"
        "Disciplina: Técnicas de Programação I\n"
        "Professor: Edvar Oliveira\n"
        "Projeto avaliativo referente ao 2º NAP\n"
        "\nAlunos:\n"
        "Douglas Costa Cabral     Mat. nº 2019039433\n"
        "Geison da Silva Santos   Mat. nº 2020042137\n"
        "Ricardo Santana Camacho  Mat. nº 2020004628\n"
        "\nCódigo e deploy também disponível em:\nhttps://replit.com/@rscamacho/Tec1-SisRH-NAP2\n"
        "Desenvolvido em abril/2021\n"
        "#####################################\n"
        "\nBem vindo ao sistema de recursos humanos!\n");

  dbCheck(); // verifica ou cria os arquivos para persistência
  
  menu(); // chama o menu
  
  return 0;
}