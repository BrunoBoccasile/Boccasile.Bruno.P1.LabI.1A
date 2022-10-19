#include "trabajos.h"
#include "servicios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscarLibreTrabajo(eTrabajo trabajo[],int tam)
{
    int indice=-1;

    for(int i=0 ; i<tam ; i++)
    {
        if(trabajo[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaTrabajo(eTrabajo lista[], int tam, eServicio servicios[], eMascota mascotas[], eTipo tipos[], eColor colores[], int tamC, int tamB, int* pId)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(lista != NULL & tam > 0)
    {
        system("cls");
        printf("Alta Trabajo\n");
        indice = buscarLibreTrabajo(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxTrabajo.id = *pId;
            (*pId)++;

            mostrarMascotas(mascotas, tam, tipos, colores, tamB);

            printf("Ingrese id de la mascota: ");
            scanf("%d", &auxTrabajo.idMascota);


            while(validarIdMascota(auxTrabajo.idMascota, mascotas, tam) == 0)
            {
                printf("Ingrese un id de mascota valido: ");
                scanf("%d", &auxTrabajo.idMascota);
            }

            mostrarServicios(servicios, tamC);

            printf("Ingrese id del servicio: ");
            scanf("%d", &auxTrabajo.idServicio);

            while(validarIdServicio(auxTrabajo.idServicio, servicios, tam) == 0)
            {
                printf("Ingrese un id de servicio valido: ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            /*printf("\nIngrese dia: ");
            scanf("%d", eTrabajo.eFecha->dia);
            printf("\nIngrese mes: ");
            scanf("%d", eTrabajo.eFecha->dmes);
            printf("\nIngrese anio: ");
            scanf("%d", eTrabajo.eFecha->danio);*/




            auxTrabajo.isEmpty = 0;

            lista[indice] = auxTrabajo;
        }




        todoOk = 1;
    }
    return todoOk;
}
