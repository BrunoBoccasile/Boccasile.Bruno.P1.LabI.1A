#include "colores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionColores(eColor colores[], int tam, int idColores, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(colores != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i = 0; i<tam ; i++)
        {
            if(colores[i].id == idColores)
            {
                strcpy(descripcion, colores[i].nombreColor);
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
            todoOk = -1;
        }
    }


    return todoOk;
}

int mostrarColores(eColor colores[], int tam)
{
    int todoOk = 0;
    system("cls");
    if(colores != NULL && tam > 0)
    {
        printf("Lista Colores\n\n");
        printf("ID   | Descripcion\n");
        printf("-----|------------ \n");
        for(int i=0 ; i<tam ; i++)
        {
            printf("%-4d | %-20s\n", colores[i].id, colores[i].nombreColor);
        }
        printf("\n");
        todoOk = 1;
    }


    return todoOk;
}

int validarIdColor(int id, eColor colores[], int tam)
{
    int retorno = 0;

    for(int i=0 ; i<tam ; i++)
    {
        if(id == colores[i].id)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}
