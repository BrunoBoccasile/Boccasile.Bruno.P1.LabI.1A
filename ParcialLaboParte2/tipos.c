#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cargarDescripcionTipos(eTipo tipos[], int tam, int idTipos, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if(tipos != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i = 0; i<tam ; i++)
        {
            if(tipos[i].id == idTipos)
            {
                strcpy(descripcion, tipos[i].descripcion);
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

int mostrarTipos(eTipo tipos[], int tam)
{
    int todoOk = 0;
    system("cls");
    if(tipos != NULL && tam > 0)
    {
        printf("Lista Tipos\n\n");
        printf("ID   | Descripcion\n");
        printf("-----|------------ \n");
        for(int i=0 ; i<tam ; i++)
        {
            printf("%-4d | %-20s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n");
        todoOk = 1;
    }


    return todoOk;
}

int validarIdTipo(int id, eTipo tipos[], int tam)
{
    int retorno = 0;

    for(int i=0 ; i<tam ; i++)
    {
        if(id == tipos[i].id)
        {
            if(id != 0)
            {
               retorno = 1;
            }

            break;
        }
    }
    return retorno;
}
