#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[50];
    char genero[30];
    int duracion;
}ePelicula;

#endif // PELICULAS_H_INCLUDED

ePelicula* pelicula_new();
