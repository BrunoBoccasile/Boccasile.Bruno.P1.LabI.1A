#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"


char menu()
{
    char opcion;
    system("cls");
    printf("   ABM VETERINARIA\n\n");
    printf("A- Alta mascota\n");
    printf("B- Modificar mascota\n");
    printf("C- Baja mascota\n");
    printf("D- Listar mascotas\n");
    printf("E- Listar tipos\n");
    printf("F- Listar colores\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("X- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);

    return opcion;
}

int inicializarMascotas(eMascota mascota[], int tam)
{
    int todoOk = 0;

    if(mascota != NULL && tam > 0)
    {
        for(int i=0 ; i<tam ; i++)
        {
            mascota[i].isEmpty = 1;
        }
        todoOk = 1;
    }


    return todoOk;
}

int buscarLibre(eMascota mascota[],int tam)
{
    int indice=-1;

    for(int i=0 ; i<tam ; i++)
    {
        if(mascota[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], int tamB, int* pId)
{
    int todoOk = 0;
    int indice;
    eMascota auxMascota;

    if(lista != NULL & tam > 0)
    {
        system("cls");
        printf("Alta mascota\n");
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxMascota.id = *pId;
            (*pId)++;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxMascota.nombre);


            printf("Ingrese edad: ");
            scanf("%d", &auxMascota.edad);

            printf("Esta vacunado?: ");
            fflush(stdin);
            scanf("%c", &auxMascota.vacunado);

            mostrarTipos(tipos, tamB);
            printf("Ingrese id del tipo: ");

            scanf("%d", &auxMascota.idTipo);

            while(validarIdTipo(auxMascota.idTipo, tipos, tamB) == 0)
            {
                printf("Ingrese un id valido: ");
                scanf("%d", &auxMascota.idTipo);
            }

            mostrarColores(colores, tamB);
            printf("Ingrese id del color: ");

            scanf("%d", &auxMascota.idColor);

            while(validarIdColor(auxMascota.idColor, colores, tamB) == 0)
            {
                printf("Ingrese un id valido: ");
                scanf("%d", &auxMascota.idColor);
            }

            auxMascota.isEmpty = 0;

            lista[indice] = auxMascota;
        }




        todoOk = 1;
    }
    return todoOk;
}

int mostrarMascota(eMascota mascota, eTipo tipos[], eColor colores[], int tam)
{
    char descTipos[20];
    char descColor[20];



    if(cargarDescripcionTipos(tipos, tam, mascota.idTipo, descTipos) == 1 && cargarDescripcionColores(colores, tam, mascota.idColor, descColor) == 1)
    {
        printf("%-4d|%-10s|%2d  |%c       |%-10s|%-10s\n",
               mascota.id,
               mascota.nombre,
               mascota.edad,
               mascota.vacunado,
               descTipos,
               descColor
              );
    }


}

int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], eColor colores[], int tamB)
{

    int todoOk = 0;
    int bandera = 0;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("              Lista de mascotas\n\n");
        printf("Id  |Nombre    |Edad|Vacunado|Tipo      |Color\n");
        printf("----|----------|----|--------|----------|-------\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarMascota(lista[i], tipos, colores, tamB);
                bandera = 1;
            }

        }
        printf("------------------------------------------------\n");
        if(bandera == 0)
        {
            printf("No hay mascotas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarMascotaId(eMascota lista[], int tam, int id)
{
    int indice=-1;

    for(int i=0 ; i<tam ; i++)
    {
        if(!lista[i].isEmpty && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int bajaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], int tamB)
{
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("         Baja Mascota\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarMascotaId(lista, tam, id);
    if(indice == -1)
    {
        printf("El id: %d no esta registrado en el sistema\n");
    }
    else
    {
        mostrarMascota(lista[indice], tipos, colores, tamB);
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            lista[indice].isEmpty = 1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
}

int ordenarMascotas(eMascota lista[], eTipo tipo[], int tam)
{
    eMascota auxMascota;
     for(int i = 0; i<tam-1; i++)
        {
            for(int j = i+1; j<tam; j++)
            {
                if((strcmp(lista[i].nombre, lista[j].nombre) > 0 ) ||
                (strcmp(lista[i].nombre, lista[j].nombre) == 0 && (lista[i].idTipo > lista[j].idTipo)))
                {
                    auxMascota = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMascota;
                }
            }
        }
}

int modificarMascota(eMascota lista[], int tam, eTipo tipos[], eTipo colores[], int tamB)
{
    int indice;
    int id;
    char confirma;
    int auxTipo;
    char auxVacunado;

    system("cls");
    printf("         Modificar mascota\n\n");
        printf("Id  |Nombre    |Edad|Vacunado|Tipo      |Color\n");
        printf("----|----------|----|--------|----------|-------\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarMascota(lista[i], tipos, colores, tamB);
            }

        }
        printf("------------------------------------------------\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarMascotaId(lista, tam, id);
    if(indice == -1)
    {
        printf("El id: %d no esta registrado en el sistema\n");
    }
    else
    {
        mostrarMascota(lista[indice], tipos, colores, tamB);
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            switch(menuModificacion())
            {
            case 1:
                mostrarTipos(tipos, tamB);
                printf("Ingrese nuevo tipo (ID): ");
                scanf("%d", &auxTipo);
                lista[indice].idTipo = auxTipo;
                break;
            case 2:
                printf("Ingrese nuevo estado de vacunacion (s) o (n): ");
                fflush(stdin);
                scanf("%c", &auxVacunado);
                lista[indice].vacunado = auxVacunado;
                break;
            case 3:
                printf("Saliendo\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
        }
        else
        {
            printf("Se ha cancelado la modificacion\n");
        }
    }
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

int validarIdMascota(int id, eMascota mascota[], int tam)
{
    int retorno = 0;

    for(int i=0 ; i<tam ; i++)
    {
        if(id == mascota[i].id)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}
