#ifndef EXPORTS_DOT_H
#define EXPORTS_DOT_H

// CONSTANTES
#define MAX_NAME 100
// #define MAX_REG_NUM 4
#define MAX_EMAIL 100
#define MAX_ADMISSION 10
#define DB_FILENAME "DATABASE.txt"
#define COUNTS_FILENAME "COUNTS.txt"

// ESTRUTURAS
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
int menu(void);     // 0
int cadastro(void); // 1
int listar(void);   // 2
int dbRead(void);   // functions.c
int rwCounts (void); // functions.c
_Bool searchByName (const char *s); // functions.c
void clearBuf(void); // functions.c

#endif