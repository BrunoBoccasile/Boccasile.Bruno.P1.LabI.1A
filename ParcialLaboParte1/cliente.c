#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int cargarNombreClientes(eCliente clientes[], int tam, int idClientes, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if(clientes != NULL && tam > 0 && nombre != NULL)
    {
        todoOk = 1;
        for(int i = 0; i<tam ; i++)
        {
            if(clientes[i].id == idClientes)
            {
                strcpy(nombre, clientes[i].nombre);
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

int validarIdClientes(int id, eCliente clientes[], int tam)
{
    int retorno = 0;

    for(int i=0 ; i<tam ; i++)
    {
        if(id == clientes[i].id)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int mostrarClientes(eCliente clientes[], int tam)
{
    int todoOk = 0;
    system("cls");
    if(clientes != NULL && tam > 0)
    {
        printf("Lista Clientes\n\n");
        printf("ID   |   Nombre            |  Sexo \n");
        printf("-----|---------------------|---------- \n");
        for(int i=0 ; i<tam ; i++)
        {
            printf("%-4d | %-20s| %c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
        }
        printf("\n");
        todoOk = 1;
    }


    return todoOk;
}
