#ifndef EXPORTS_DOT_H
#define EXPORTS_DOT_H

// CONSTANTES
#define MAX_NAME 64
// #define MAX_REG_NUM 4
#define MAX_EMAIL 64
#define MAX_ADMISSION 10
#define DB_FILE "database"

// ESTRUTURAS
typedef struct {
  unsigned int id;
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char admission[MAX_ADMISSION];
  float salary;
}emp;

// FUNÇÕES
int menu(void);     // 0
int cadastro(void); // 1

#endif