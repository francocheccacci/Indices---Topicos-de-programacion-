#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "tipos.h"


/******************************************************************************/
void show(const char *path, int (*sh)(const char *))
{
    sh(path);
}

/******************************************************************************/
void bubble_sort(void *vec, size_t nmemb, size_t tamanyo, int (*cmp)(void *, void *))
{
    int i, j;

    for(i = 0; i < nmemb; i++)
        for(j = 0; j < nmemb - 1; j++)
            if(cmp(vec + j * tamanyo,  vec + (j + 1) * tamanyo) > 0)
                interchange(vec + j * tamanyo,  vec + (j + 1) * tamanyo, tamanyo);
}

/******************************************************************************/
void selection_sort(void *vec, size_t nmemb, size_t tamanyo, int (*cmp)(void *, void *))
{
    int i, j, pos_men;

    for(i = 0; i < nmemb - 1; i++){
       pos_men = i;

        for(j = i + 1; j < nmemb; j++)
            if(cmp(vec + pos_men * tamanyo, vec + j * tamanyo) > 0)
                pos_men = j;

        interchange(vec + i * tamanyo ,  vec + pos_men * tamanyo, tamanyo);
    }
}

/******************************************************************************/
void interchange(void *a, void *b, size_t tamanyo)
{
    char *aux = malloc(tamanyo);

    memcpy(aux, a, tamanyo);
    memcpy(a, b, tamanyo);
    memcpy(b, aux, tamanyo);

    free(aux);
}

/******************************************************************************/
char menu(const char m[][LENGTH_MENU], const char *tit)
{
    char op;
    op = get_option(m, tit, "Ingrese opcion: ");
    while(!strchr(m[0], op))
        op = get_option(m, tit, "Opcion erronea. Ingrese nuevamente: ");
    return op;
}

/******************************************************************************/
char get_option(const char m[][LENGTH_MENU], const char *tit, const char *msj)
{
    char op;
    int i;
    system("CLS");
    printf("\n\n %s \n", tit);
    for ( i=1 ; i <= strlen(m[0]) ; i++)
        printf("\n %c - %s", m[0][i-1], m[i]);
    printf("\n\n%s: ", msj);
    fflush(stdin);
    scanf("%c", &op);
    return toupper(op);
}

/******************************************************************************/
int crea_archivo_alumnos(const char *path_alus)
{
    int cant_registros;

    t_alumno alumnos[] = {
                            {16230902, "Boyd Chaney",    {21,11,1997}},
                            {16540430, "Brennan Lee",    {13,7,1996}},
                            {16200214, "Clark Scott",    {9,12,1996}},
                            {16870210, "Cole Coby",      {8,12,1994}},
                            {16660110, "Dale Isaac",     {1,9,1997}},
                            {16900207, "Gallegos Nash",  {15,8,1998}},
                            {16860403, "Gibbs Clinton",  {21,3,1995}},
                            {16231024, "Guerra Oliver",  {18,10,1995}},
                            {16940212, "Hunter Rajah",   {11,5,1996}},
                            {16621004, "Mcclain Ronan",  {5,7,1998}},
                            {16790215, "Sosa Zeph",      {30,1,1996}},
                            {16001129, "Wilkerson Berk", {12,10,1996}}
                        };

    FILE *arch = fopen(path_alus, "wb");

    if (!arch){
        printf("Error de creacion de Archivo de Alumnos\n");
        system("PAUSE");
        return ERROR;
    }

    fwrite(alumnos,sizeof(alumnos), 1, arch);
    fclose(arch);

    cant_registros = sizeof(alumnos)/sizeof(t_alumno);

    return cant_registros;
}

/******************************************************************************/
t_indice *generar_indice(const char *path_alus, int cant_registros, int (*cmp)(void *, void *))
{
    FILE *arch;
    t_alumno alumno;

    t_indice *indice;
    int i = 0;

    arch = fopen(path_alus, "rb");

    if (!arch){
        printf("Error de lectura de Archivo de Alumnos\n");
        system("PAUSE");
        return ERROR;
    }

    indice = (t_indice *)malloc(sizeof(t_indice) * cant_registros);

    if (!indice){
        printf("Error de reserva de memoria\n");
        system("PAUSE");
        exit (1);
    }


    fread(&alumno, sizeof(t_alumno), 1, arch);
    while(!feof(arch)){
        indice[i].dni = alumno.dni;
        indice[i].pos = i;
        i++;
        fread(&alumno, sizeof(t_alumno), 1, arch);
    }

    bubble_sort(indice, cant_registros, sizeof(t_indice), cmp);

    fclose(arch);

    return indice;
}
