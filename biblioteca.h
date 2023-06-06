#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include "tipos.h"
#define LENGTH_MENU 32
#define OK 1
#define ERROR 0

void show(const char *path, int (*sh)(const char *));
void bubble_sort(void *vec, size_t nmemb, size_t tamanyo, int (*cmp)(void *, void *));
void selection_sort(void *vec, size_t nmemb, size_t tamanyo, int (*cmp)(void *, void *));
void interchange(void *a, void *b, size_t tamanyo);

char menu(const char m[][LENGTH_MENU], const char *tit);
char get_option(const char m[][LENGTH_MENU], const char *tit, const char *msj);

int crea_archivo_alumnos(const char *path_alus);
t_indice *generar_indice(const char *path_alus, int cant_registros, int (*cmp)(void *, void *));

#endif // BIBLIOTECA_H_INCLUDED
