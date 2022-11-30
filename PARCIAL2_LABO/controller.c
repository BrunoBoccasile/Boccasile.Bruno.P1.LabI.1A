#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "peliculas.h"

int controller_cargarPeliculas(char* path, LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;
    FILE* f;
    char id[50];
    char titulo[50];
    char genero[50];
    char duracion[50];


    int cant;

    if(path != NULL && pArrayListPeliculas != NULL)
    {
        f = fopen(path, "r");

        if(f != NULL)
        {

            ePelicula* auxPelicula = NULL;


            fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",
                   id,titulo,genero,duracion); //lectura fantasma


            do
            {
                cant =  fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",
                               id,titulo,genero,duracion);


                if(cant == 4)
                {
                    auxPelicula = newPeliculaParam(id,titulo,genero,duracion);
                    ll_add(pArrayListPeliculas, auxPelicula);
                }



            }
            while(!feof(f));



            fclose(f);
            todoOk = 1;
        }

    }


    return todoOk;
}

int controller_listarPeliculas(LinkedList* pArrayListPeliculas)
{
    int todoOk = 0;

    int id;
    char titulo[50];
    int duracion;
    char genero[30];

    ePelicula* pPelicula;


    if(pArrayListPeliculas != NULL)
    {

        printf("|ID   | TITULO                                            | GENERO                          | DURACION  |\n");


        for(int i=0 ; i<ll_len(pArrayListPeliculas) ; i++)
        {

            pPelicula = (ePelicula*) ll_get(pArrayListPeliculas, i);

            getId(pPelicula, &id);
            getTitulo(pPelicula, titulo);
            getDuracion(pPelicula, &duracion);
            getGenero(pPelicula, genero);

            printf("|%-3d  |%-50s |%-30s   | %-5d     |\n",
                   id, titulo, genero, duracion
                  );
        }





        todoOk = 1;
    }

    return todoOk;
}

int controller_guardarPeliculasTipo(char* path, LinkedList* pArrayListPelicula)
{
    int todoOk = 0;
    FILE* f;
    ePelicula* pPelicula;

    int idObtenido;
    char tituloObtenido[50];
    char generoObtenido[30];
    int duracionObtenida;

    char generoIngresado[30];


    printf("Ingrese el tipo de pelicula a filtrar: ");
    fflush(stdin);
    gets(generoIngresado);
    while( !(
                strcmp(generoIngresado, "adventure") == 0 ||
                strcmp(generoIngresado, "drama") == 0 ||
                strcmp(generoIngresado, "comedy") == 0 ||
                strcmp(generoIngresado, "romance") == 0 ||
                strcmp(generoIngresado, "documentary") == 0 ||
                strcmp(generoIngresado, "animation") == 0 ||
                strcmp(generoIngresado, "action") == 0 ||
                strcmp(generoIngresado, "horror") == 0 ||
                strcmp(generoIngresado, "musical") == 0 ||
                strcmp(generoIngresado, "western") == 0 ||
                strcmp(generoIngresado, "thriller") == 0  )
         )
    {
        printf("Error, ingrese un genero valido: ");
        fflush(stdin);
        gets(generoIngresado);
    }


    if(path != NULL && pArrayListPelicula != NULL)
    {
        f = fopen(path, "w");

        if(f != NULL)
        {
            fprintf(f,"id_peli,titulo,genero,duracion\n");

            for(int i=0 ; i<ll_len(pArrayListPelicula); i++)
            {
                pPelicula = (ePelicula*) ll_get(pArrayListPelicula, i);



                getId(pPelicula, &idObtenido);
                getTitulo(pPelicula, tituloObtenido);
                getGenero(pPelicula, generoObtenido);
                getDuracion(pPelicula, &duracionObtenida);

                for(int j=0 ; j<30 ; j++)
                {
                    generoObtenido[j] = tolower(generoObtenido[j]);
                    generoIngresado[j] = tolower(generoIngresado[j]);
                }

                if(strcmp(generoObtenido, generoIngresado) == 0)
                {


                    printf("entro");
                    fprintf(f, "%d,%s,%s,%d\n",
                            idObtenido, tituloObtenido, generoObtenido, duracionObtenida
                           );
                }
            }
            fclose(f);
        }

        todoOk = 1;
    }

    return todoOk;
}

