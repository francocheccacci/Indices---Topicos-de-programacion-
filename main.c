#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "tipos.h"
#include "funciones.h"

#define ARCH_ALUMNOS "Archivos/alumnos.bin"

int main()
{
    int cant_registros;
    t_indice *indice;
    long dni;
    t_alumno nuevoAlumno;

    cant_registros = crea_archivo_alumnos(ARCH_ALUMNOS);
    indice = generar_indice(ARCH_ALUMNOS, cant_registros, compara_alumnos_idx);

    const char opciones [][LENGTH_MENU] = {"MIBAES",
                                        "Mostrar archivo Alumnos",
                                        "Mostrar Alumnos (ordenado)",
                                        "Buscar Alumno",
                                        "Alta Alumno",
                                        "Eliminar Alumno",
                                        "Salir"
                                        };

    char op;

    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'M':
                show(ARCH_ALUMNOS, muestra_alumnos);
                system("PAUSE");
                break;
            case 'I':
                mostrarAluOrd(ARCH_ALUMNOS, indice,cant_registros);
                system("PAUSE");
                break;
            case 'B':
                printf("Ingrese DNI:");
                scanf("%ld", &dni);
                buscarAlumno(ARCH_ALUMNOS, indice,cant_registros, dni);
                system("PAUSE");
                break;

            case 'A':
                printf("Ingrese Apellido y Nombre:");
                scanf("%s", nuevoAlumno.apyn);
                printf("Ingrese DNI:");
                scanf("%ld", &nuevoAlumno.dni);
                printf("Ingrese año: ");
                scanf("%d", &nuevoAlumno.fecha_nac.anio);
                printf("Ingrese mes: ");
                scanf("%d", &nuevoAlumno.fecha_nac.mes);
                printf("Ingrese dia: ");
                scanf("%d", &nuevoAlumno.fecha_nac.dia);

                agregarAlumno(ARCH_ALUMNOS, indice,cant_registros,nuevoAlumno);
                cant_registros++;
                t_indice *nuevoIndice = generar_indice(ARCH_ALUMNOS, cant_registros, compara_alumnos_idx);
                free(indice);
                indice = nuevoIndice;
                system("PAUSE");
                break;

            case 'E':
                system("PAUSE");
                break;
        }
    }while(op!='S');

    return 0;
}
