#ifndef EXPORTS_DOT_H
#define EXPORTS_DOT_H

// CONSTANTES
#define MAX_NAME 100
#define MAX_EMAIL 100
#define MAX_ADMISSION 10
#define DB_FILENAME "DATABASE.txt"
#define COUNTS_FILENAME "COUNTS.txt"
#define TEMP_FILENAME "TEMP.txt"

// ESTRUTURA
typedef struct {
  unsigned int id;
  float salary;
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char admission[MAX_ADMISSION];
}emp;

// VARIÁVEIS
unsigned int nRg, lastId;

// FUNÇÕES
int menu(void);                     // 0_menu.c
int cadastro(void);                 // 1_cadastro.c
int listar(void);                   // 2_listar.c
int excluir(void);                  // 3_excluir.c
int alterar(void);                  // 4_alterar.c
int dbCheck(void);                  // functions.c
int rwCounts (void);                // functions.c
_Bool searchByName (const char *s); // functions.c
void clearBuf(void);                // functions.c
int rwDb(void);                     // functions.c

#endif