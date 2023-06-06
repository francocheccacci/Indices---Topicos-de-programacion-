#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "tipos.h"
#define TAM_VEC 12

///NUESTRAS
int muestra_alumnos(const char *path);
int mostrarAluOrd(const char *path, t_indice *ind, int cant_registros);
int compara_alumnos_idx(void *a, void *b);
int buscarAlumno( const char *pat, t_indice * ind, int cant_registros, long dni);
int agregarAlumno(const char *pat,t_indice * ind,int cant_registros, t_alumno nuevoAlumno);
#endif // FUNCIONES_H_INCLUDED

