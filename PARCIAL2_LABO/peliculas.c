#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"

int getId(ePelicula* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id_peli;

        todoOk = 1;
    }

    return todoOk;
}

int setId(ePelicula* this, int* id)
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id_peli = id;


        todoOk = 1;
    }

    return todoOk;
}

int getTitulo(ePelicula* this, char* titulo)
{
    int todoOk = 0;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }

    return todoOk;
}

int setTitulo(ePelicula* this, char* titulo)
{
    int todoOk = 0;
    if(this != NULL)
    {
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }

    return todoOk;
}

int getGenero(ePelicula* this, char* genero)
{
    int todoOk = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }

    return todoOk;
}

int setGenero(ePelicula* this, char* genero)
{
    int todoOk = 0;
    if(this != NULL)
    {
        strcpy(this->genero, genero);
        todoOk = 1;
    }

    return todoOk;
}


int getDuracion(ePelicula* this, int* duracion)
{
    int todoOk = 0;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;

        todoOk = 1;
    }

    return todoOk;
}

int setDuracion(ePelicula* this, int* duracion)
{
    int todoOk = 0;
    if(this != NULL && duracion >= 0)
    {
        this->duracion = duracion;
        todoOk = 1;
    }

    return todoOk;
}

ePelicula* newPeliculaParam(char* idStr,char* tituloStr,char* generoStr, char* duracionStr)
{
	ePelicula* nuevaPelicula = pelicula_new();

	    if(nuevaPelicula!= NULL)
	    {

		if(         !(
					setId(nuevaPelicula, atoi(idStr)) &&
					setTitulo(nuevaPelicula, tituloStr) &&
					setDuracion(nuevaPelicula, atoi(duracionStr)) &&
                    setGenero(nuevaPelicula, generoStr))
            )
	        {

	             free(nuevaPelicula);
	            nuevaPelicula = NULL;
	        }


	    }

	  return nuevaPelicula;
}

ePelicula* pelicula_new()
{
    ePelicula* nuevaPelicula = (ePelicula*) malloc(sizeof(ePelicula));
    if(nuevaPelicula != NULL)
    {
    	nuevaPelicula->id_peli = 0;
        strcpy(nuevaPelicula->titulo, "");
        nuevaPelicula->duracion = 0;
        strcpy(nuevaPelicula->genero, "");
    }
    return nuevaPelicula;

}
