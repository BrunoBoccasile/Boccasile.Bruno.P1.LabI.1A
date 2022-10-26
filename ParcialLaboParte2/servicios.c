#include "servicios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionPrecioServicios(eServicio servicios[], int tam, int idServicios, char descripcion[], int* precio)
{
    int todoOk = 0;
    int flag = 1;
    if(servicios != NULL && tam > 0 && descripcion != NULL && precio > 0)
    {
        todoOk = 1;
        for(int i = 0; i<tam ; i++)
        {
            if(servicios[i].id == idServicios)
            {
                strcpy(descripcion, servicios[i].descripcion);
                *precio = servicios[i].precio;
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

int mostrarServicios(eServicio servicios[], int tam)
{
    int todoOk = 0;
    system("cls");
    if(servicios != NULL && tam > 0)
    {
        printf("Lista Servicios\n\n");
        printf("ID    | Descripcion              | Precio\n");
        printf("------|--------------------------|-------- \n");
        for(int i=0 ; i<tam ; i++)
        {
            printf("%-4d | %-25s| $%d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n");
        todoOk = 1;
    }


    return todoOk;
}

int validarIdServicio(int id, eServicio servicios[], int tam)
{
    int retorno = 0;

    for(int i=0 ; i<tam ; i++)
    {
        if(id == servicios[i].id)
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
