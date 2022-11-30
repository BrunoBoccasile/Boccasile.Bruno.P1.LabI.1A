#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "controller.h"
#include "peliculas.h"
#include "LinkedList.h"

int main()
{
    char salir = 'n';


    LinkedList* listaPeliculas = ll_newLinkedList();

    char bandera = 'n';
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");


    if(bandera != 's')
    {
        bandera = 's';
       if(controller_cargarPeliculas("movies.csv", listaPeliculas))
                {
                    printf("Peliculas cargadas exitosamente\n");
                }
                else
                {
                    printf("Ocurrio un error al cargar las peliculas\n");
                }

    }
    else{
        printf("Las peliculas ya han sido cargadas\n");
    }
            break;
        case 2:

            system("cls");
            if(!controller_listarPeliculas(listaPeliculas))
            {
                printf("Ocurrio un error al intentar listar las peliculas\n");

            }
            break;
        case 3:
            system("cls");


            break;
        case 4:
            system("cls");
            controller_guardarPeliculasTipo("peliculasPorGenero.csv", listaPeliculas);
            break;
        case 5:
            system("cls");

            break;
        case 6:
            system("cls");

            break;
        case 7:
            system("cls");
            if(confirmarSalida())
            {
                salir ='s';
            }
            break;
        default:
            printf("Opcion invalida\n");
            break;

        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}
