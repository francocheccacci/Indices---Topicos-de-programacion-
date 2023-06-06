#include <stdio.h>
#include "biblioteca.h"
#include "funciones.h"

int muestra_alumnos(const char *path)
{
    t_alumno alumno;

    FILE *arch = fopen(path, "rb");

    if (!arch){
        printf("Error de lectura de Archivo\n");
        return ERROR;
    }

    printf("DNI   \tAPELLIDO y NOMBRE \tFECHA_NACIMIENTO\n");

    fread(&alumno, sizeof(t_alumno), 1, arch);
    while(!feof(arch)){
        printf("%ld, %-20s %2d/%2d/%4d\n", alumno.dni, alumno.apyn, alumno.fecha_nac.dia, alumno.fecha_nac.mes, alumno.fecha_nac.anio);
        fread(&alumno, sizeof(t_alumno), 1, arch);
    }
    fclose(arch);

    return OK;
}

/******************************************************************************/
int compara_alumnos_idx(void *a, void *b)
{
    t_indice *idx1 = (t_indice *)a;
    t_indice *idx2 = (t_indice *)b;

    return idx1->dni - idx2->dni;
}
/******************************************************************************/

int mostrarAluOrd(const char *path, t_indice *ind,int cant_registros){


    FILE *arch = fopen(path, "rb");
    if (!arch) {
        printf("Error de lectura del archivo\n");
        return -1;
    }

    t_alumno alumno;
    for (int i = 0; i < cant_registros; i++) {
        // Buscar la posición del alumno en el archivo utilizando el índice

        fseek(arch, ind[i].pos * sizeof(t_alumno), SEEK_SET);
        fread(&alumno, sizeof(t_alumno), 1, arch);

        // Mostrar los datos del alumno
       printf("DNI: %ld, Apellido y nombre: %s\n", alumno.dni, alumno.apyn);
    }


    fclose(arch);

    return 0;
}
/******************************************************************************/

int buscarAlumno( const char *path, t_indice * ind, int cant_registros, long dni){

    FILE *arch = fopen(path, "rb");
    if (!arch) {
        printf("Error de lectura del archivo\n");
        return -1;
    }
    int encontro = 0;
    t_alumno alumno;

    for (int i = 0; i < cant_registros; i++) {
        // Buscar la posición del alumno en el archivo utilizando el índice
        if( ind[i].dni == dni && encontro != 1){
            fseek(arch, ind[i].pos * sizeof(t_alumno), SEEK_SET);
            fread(&alumno, sizeof(t_alumno), 1, arch);
            encontro = 1;
            // Mostrar los datos del alumno
            printf("DNI: %ld, Apellido y nombre: %s\n", alumno.dni, alumno.apyn);
            break;
        }

    }

    if (encontro != 1){
        printf("DNI no encontrado. \n");
    }

    return 0;
}

