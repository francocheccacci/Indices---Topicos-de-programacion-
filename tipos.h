#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int dia, mes, anio;
}t_fecha;

typedef struct
{
    long dni;
    char apyn[30];
    t_fecha fecha_nac;
}t_alumno;

typedef struct
{
    long dni;
    int pos;
}t_indice;

#endif // TIPOS_H_INCLUDED

