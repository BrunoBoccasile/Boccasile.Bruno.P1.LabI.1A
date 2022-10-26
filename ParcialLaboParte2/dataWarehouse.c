#include "dataWarehouse.h"
#include <string.h>

char nombres[5][20]={"Toby",
                     "Roko",
                     "Luna",
                     "Simba",
                     "Lola"};

int edades[5] = {3, 4, 1, 9, 7};

char vacunado[5] = {'n', 's', 'n', 's', 's'};

int idTipos[5] = {1000, 1002, 1002, 1001, 1003};

int idColores[5] = {1003, 1001, 1000, 1000, 1004};

int idClientes[5] = {1000, 1001, 1002, 1003, 1004};


int hardcodearMascotas(eMascota lista[], int tam, int cant, int* pId, int* bandera)
{
    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i=0; i<cant ; i++)
        {
            lista[i].id = *pId;
            (*pId)++;

            strcpy(lista[i].nombre, nombres[i]);

            lista[i].edad = edades[i];

            lista[i].vacunado = vacunado[i];

             lista[i].idTipo = idTipos[i];

             lista[i].idColor = idColores[i];

             lista[i].idCliente = idClientes[i];

            lista[i].isEmpty = 0;

            contador++;
        }
    }

    *bandera = 1;
    return contador;
}
