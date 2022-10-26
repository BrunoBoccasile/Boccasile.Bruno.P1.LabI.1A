#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascota.h"
#include "validaciones.h"




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
    printf("J- Informes complementarios\n");
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
            mascota[i].id = 0;
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



int altaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB, int* pId)
{
    char mensajeError[35] = {"Error, ingrese un nombre valido: "};
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

            validarString(auxMascota.nombre, 1, 20, mensajeError);

            printf("Ingrese edad: ");
            scanf("%d", &auxMascota.edad);

            validarNumeroMaxMin(&auxMascota.edad, 100, 0);

            printf("Esta vacunado?: ");
            fflush(stdin);
            scanf("%c", &auxMascota.vacunado);
            validarSiNo(&auxMascota.vacunado);
            fflush(stdin);

            mostrarTipos(tipos, tamB);
            printf("Ingrese id del tipo: ");

            scanf("%d", &auxMascota.idTipo);

            while(validarIdTipo(auxMascota.idTipo, tipos, tamB) == 0)
            {
                printf("Ingrese un id valido: ");
                fflush(stdin);
                scanf("%d", &auxMascota.idTipo);
            }

            mostrarColores(colores, tamB);
            printf("Ingrese id del color: ");

            scanf("%d", &auxMascota.idColor);

            while(validarIdColor(auxMascota.idColor, colores, tamB) == 0)
            {
                printf("Ingrese un id valido: ");
                fflush(stdin);
                scanf("%d", &auxMascota.idColor);
            }

            mostrarClientes(clientes, tamB);
            printf("Ingrese id del cliente: ");

            scanf("%d", &auxMascota.idCliente);

            while(validarIdClientes(auxMascota.idCliente, clientes, tamB) == 0)
            {
                printf("Ingrese un id valido: ");
                fflush(stdin);
                scanf("%d", &auxMascota.idCliente);
            }

            auxMascota.isEmpty = 0;

            lista[indice] = auxMascota;
        }




        todoOk = 1;
    }
    return todoOk;
}




int mostrarMascota(eMascota mascota, eTipo tipos[], eColor colores[], eCliente clientes[], int tam)
{
    int todoOk = 0;

    if(tipos != NULL && colores != NULL && tam > 0)
    {
        char descTipos[20];
        char descColor[20];
        char nombreCliente[20];


        if(cargarDescripcionTipos(tipos, tam, mascota.idTipo, descTipos) == 1 && cargarDescripcionColores(colores, tam, mascota.idColor, descColor) == 1 && cargarNombreClientes(clientes, tam, mascota.idCliente, nombreCliente) == 1)
        {

            printf("%-4d|%-20s|%-3d  |%c       |%-10s|%-10s|%-20s\n",
                   mascota.id,
                   mascota.nombre,
                   mascota.edad,
                   mascota.vacunado,
                   descTipos,
                   descColor,
                   nombreCliente
                  );
        }
        todoOk = 1;
    }

    return todoOk;
}




int mostrarMascotas(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB)
{

    int todoOk = 0;
    int bandera = 0;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("              Lista de mascotas\n\n");
        printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
        printf("----|--------------------|-----|--------|----------|----------|---------\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarMascota(lista[i], tipos, colores, clientes, tamB);
                bandera = 1;
            }

        }
        printf("----|--------------------|-----|--------|----------|----------|---------\n");
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




int bajaMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB, int* pBandera)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && tipos != NULL && colores != NULL && tamB > 0)
    {
        int indice;
        int id;
        char confirma;

        system("cls");
        printf("         Baja mascota\n\n");
        printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
        printf("----|--------------------|-----|--------|----------|----------|---------\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarMascota(lista[i], tipos, colores, clientes, tamB);
            }

        }
        printf("----|--------------------|-----|--------|----------|----------|---------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        validarNumeroMaxMin(&id, 9999, 1000);

        indice = buscarMascotaId(lista, tam, id);
        while(indice == -1)
        {
            printf("El id %d no esta registrado en el sistema, ingrese un id existente:\n", id);
            scanf("%d", &id);
            validarNumeroMaxMin(&id, 9999, 1000);
            indice = buscarMascotaId(lista, tam, id);
        }

        mostrarMascota(lista[indice], tipos, colores, clientes, tamB);
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        validarSiNo(&confirma);
        if(confirma == 's')
        {
            lista[indice].isEmpty = 1;
            for(int i=0; i<tam ; i++)
            {
                if(lista[i].isEmpty == 1)
                {
                    *pBandera = 0;
                    break;
                }

            }

            for(int i=0; i<tam ; i++)
            {
                if(lista[i].isEmpty == 0)
                {
                    *pBandera = 1;
                    break;
                }
            }

        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }

        todoOk = 1;
    }

    return todoOk;
}



int ordenarMascotas(eMascota lista[], eTipo tipo[], int tam)
{
    int todoOk = 0;

    if(lista != NULL && tipo != NULL && tam > 0)
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

        todoOk = 1;
    }

    return todoOk;
}



int modificarMascota(eMascota lista[], int tam, eTipo tipos[], eColor colores[], eCliente clientes[], int tamB)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && tipos != NULL && colores != NULL && tamB > 0)
    {
        char salida = 'n';
        int indice;
        int id;
        char confirma;
        int auxTipo;
        char auxVacunado;

        system("cls");
        printf("         Modificar mascota\n\n");
        printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
        printf("----|--------------------|-----|--------|----------|----------|---------\n");
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty == 0)
            {

                mostrarMascota(lista[i], tipos, colores, clientes, tamB);
            }

        }
        printf("----|--------------------|-----|--------|----------|----------|---------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        validarNumeroMaxMin(&id, 9999, 1000);

        indice = buscarMascotaId(lista, tam, id);
        while(indice == -1)
        {
            printf("El id %d no esta registrado en el sistema, ingrese un id existente:\n", id);
            scanf("%d", &id);
            validarNumeroMaxMin(&id, 9999, 1000);
            indice = buscarMascotaId(lista, tam, id);
        }

        mostrarMascota(lista[indice], tipos, colores, clientes, tamB);
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        validarSiNo(&confirma);
        if(confirma == 's')
        {
            do
            {
                switch(menuModificacion())
                {
                case 1:
                    mostrarTipos(tipos, tamB);
                    printf("Ingrese nuevo tipo (ID): ");
                    scanf("%d", &auxTipo);

                    while(validarIdTipo(auxTipo, tipos, tam) == 0)
                    {
                        printf("Ingrese un id valido: ");
                        fflush(stdin);
                        scanf("%d", &auxTipo);
                    }
                    lista[indice].idTipo = auxTipo;



                    break;
                case 2:
                    printf("Ingrese nuevo estado de vacunacion (s) o (n): ");
                    fflush(stdin);
                    scanf("%c", &auxVacunado);
                    validarSiNo(&auxVacunado);
                    lista[indice].vacunado = auxVacunado;
                    break;
                case 3:
                    if(confirmarSalida())
                    {
                        salida = 's';
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }

            }
            while(salida == 'n');

        }
        else
        {
            printf("Se ha cancelado la modificacion\n");
        }

        todoOk = 1;
    }

    return todoOk;
}



int menuModificacion()
{
    int opcion;

    system("cls");
    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    while(getInt(&opcion) != 0)
    {
        printf("Error, ingrese un numero: ");
        scanf("%d", &opcion);
    }

    return opcion;

}



int validarIdMascota(int id, eMascota mascota[], int tam)
{
    int retorno = 0;

    for(int i=0 ; i<tam ; i++)
    {
        if(id == mascota[i].id)
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




int cargarNombreMascotas(eMascota mascotas[], int tam, int idMascotas, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if(mascotas != NULL && tam > 0 && nombre != NULL)
    {
        todoOk = 1;
        for(int i = 0; i<tam ; i++)
        {
            if(mascotas[i].id == idMascotas)
            {
                strcpy(nombre, mascotas[i].nombre);
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

char menuInformesComplementarios()
{
    char opcion;
    system("cls");
    printf("   Informes complementarios\n");
    printf("A- Mostrar las mascotas del color seleccionado\n");
    printf("B- Informar porcentaje de mascotas vacunadas sobre el total de mascotas\n");
    printf("C- Informar la o las mascotas de menor edad\n");
    printf("D- Lista de las mascotas separadas por tipo\n");
    printf("E- Elegir un color y un tipo y contar cuantas mascotas hay de ese color y tipo\n");
    printf("F- Mostrar el o los colores con mas cantidad de mascotas\n");
    printf("X- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);

    return opcion;
}

int informesComplementarios(eColor colores[], eMascota mascota[], eTipo tipos[], eCliente clientes[], int tam, int tamB)
{
    int todoOk = 0;

    if(colores != NULL && mascota != NULL && tipos != NULL && clientes != NULL && tam > 0 && tamB > 0)
    {
        int salirInformes = 'n';
    int colorSeleccionado;
    int hayColor = 0;
    float porcentajeVacunados;
    int porcentajeContadorVacunados;
    int contadorVacunados = 0;
    int contadorNoVacunados = 0;
    int totalMascotas = 0;
    int MascotaMenorEdad;
    int flagMenorEdad = 0;
    eMascota mascotaAMostrar;
    eMascota auxMascota[tam];
    int flagAve = 0;
    int flagPerro = 0;
    int flagRoedor = 0;
    int flagGato = 0;
    int flagPez = 0;
    int idColor;
    int idTipo;
    int contadorMascotaColor = 0;
    int contadorMascotaTipo = 0;
    char descColor[20];
    char descTipo[20];
    int contadorNegro = 0;
    int contadorBlanco = 0;
    int contadorRojo = 0;
    int contadorGris = 0;
    int contadorAzul = 0;
    int contadoresColor[tamB];
    int colorMax;
    char colorMaxDesc[20];

    for(int i=0 ; i<tam ; i++)
    {
        if(mascota[i].id > 0)
        {
            totalMascotas++;
        }
    }

    do
    {
        switch(menuInformesComplementarios())
        {
        case 'a':
            system("cls");
            mostrarColores(colores, tamB);
            printf("Ingrese id de color a clasificar: ");
            scanf("%d", &colorSeleccionado);
            validarNumeroMaxMin(&colorSeleccionado, 1004, 1000);
            printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
            printf("----|--------------------|-----|--------|----------|----------|---------\n");
            for(int i=0 ; i<tam ; i++)
            {
                if(colorSeleccionado == mascota[i].idColor)
                {

                    hayColor = 1;
                }
            }
            if(hayColor == 1)
            {
                switch(colorSeleccionado)
                {
                case 1000:
                    for(int i = 0; i<tam ; i++)
                    {
                        if(mascota[i].idColor == colorSeleccionado)
                        {
                            mostrarMascota(mascota[i], tipos, colores, clientes, tam);
                        }
                    }
                    break;
                case 1001:
                    for(int i = 0; i<tam ; i++)
                    {
                        if(mascota[i].idColor ==  colorSeleccionado)
                        {
                            mostrarMascota(mascota[i], tipos, colores, clientes, tam);
                        }
                    }

                    break;
                case 1002:
                    for(int i = 0; i<tam ; i++)
                    {
                        if(mascota[i].idColor ==  colorSeleccionado)
                        {
                            mostrarMascota(mascota[i], tipos, colores, clientes, tam);
                        }
                    }
                    break;
                case 1003:
                    for(int i = 0; i<tam ; i++)
                    {
                        if(mascota[i].idColor ==  colorSeleccionado)
                        {
                            mostrarMascota(mascota[i], tipos, colores, clientes, tam);
                        }
                    }
                    break;
                case 1004:
                    for(int i = 0; i<tam ; i++)
                    {
                        if(mascota[i].idColor ==  colorSeleccionado)
                        {
                            mostrarMascota(mascota[i], tipos, colores, clientes, tam);
                        }
                    }
                    break;
                }
                printf("----|--------------------|-----|--------|----------|----------|---------\n");
                hayColor = 0;
            }
            else
            {
                printf("----|--------------------|-----|--------|----------|----------|---------\n");
                printf("No hay mascotas con el color seleccionado\n");
            }


            break;
        case 'b':
            system("cls");
            for(int i=0 ; i<tam ; i++)
            {
                if(mascota[i].vacunado == 's')
                {
                    contadorVacunados++;
                }

            }
            porcentajeContadorVacunados = contadorVacunados * 100;
            porcentajeVacunados = (float) porcentajeContadorVacunados / totalMascotas;
            printf("El porcentaje de mascotas vacunadas es de %.2f%c \n", porcentajeVacunados, 37);
            break;
        case 'c':
            system("cls");
            printf("                        Mascota/s de menor edad\n");
            printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
            printf("----|--------------------|-----|--------|----------|----------|---------\n");
            for(int i = 0; i<tam; i++)
            {
                if(flagMenorEdad == 0)
                {
                    MascotaMenorEdad = mascota[i].edad;
                    mascotaAMostrar = mascota[i];
                    flagMenorEdad = 1;
                }
                else
                {
                    if(mascota[i].edad < MascotaMenorEdad || mascota[i].edad == MascotaMenorEdad)
                    {

                        MascotaMenorEdad = mascota[i].edad;
                        mascotaAMostrar = mascota[i];
                    }
                }



            }
            mostrarMascota(mascotaAMostrar, tipos, colores, clientes, tam);
            printf("----|--------------------|-----|--------|----------|----------|---------\n");
            break;
        case 'd':
            system("cls");
            printf("                        Mascotas separadas por tipo\n");



            for(int i = 0; i<tam-1; i++)
            {
                for(int j = i+1; j<tam; j++)
                {
                    if(mascota[i].idTipo > mascota[j].idTipo || mascota[i].idTipo == mascota[j].idTipo)
                    {
                        auxMascota[i] = mascota[i];
                        mascota[i] = mascota[j];
                        mascota[j] = auxMascota[i];
                    }
                }
            }




            for(int i=0 ; i<tam ; i++)
            {

                switch(auxMascota[i].idTipo)
                {
                case 1000:
                    if(flagAve == 0)
                    {
                        printf("Aves: \n\n");

                        flagAve =1;
                    }

                    printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
                    printf("----|--------------------|-----|--------|----------|----------|---------\n");
                    mostrarMascota(auxMascota[i], tipos, colores, clientes, tam);
                    printf("----|--------------------|-----|--------|----------|----------|---------\n\n");
                    break;
                case 1001:
                    if(flagPerro == 0)
                    {
                        printf("Perros: \n\n");

                        flagPerro =1;
                    }
                    printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
                    printf("----|--------------------|-----|--------|----------|----------|---------\n");
                    mostrarMascota(auxMascota[i], tipos, colores, clientes, tam);
                    printf("----|--------------------|-----|--------|----------|----------|---------\n\n");
                    break;
                case 1002:
                    if(flagRoedor == 0)
                    {
                        printf("Roedores: \n\n");

                        flagRoedor =1;
                    }
                    printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
                    printf("----|--------------------|-----|--------|----------|----------|---------\n");
                    mostrarMascota(auxMascota[i], tipos, colores, clientes, tam);
                    printf("----|--------------------|-----|--------|----------|----------|---------\n\n");
                    break;
                case 1003:
                    if(flagGato == 0)
                    {
                        printf("Gatos: \n\n");

                        flagGato =1;
                    }
                    printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
                    printf("----|--------------------|-----|--------|----------|----------|---------\n");
                    mostrarMascota(auxMascota[i], tipos, colores, clientes, tam);
                    printf("----|--------------------|-----|--------|----------|----------|---------\n\n");
                    break;
                case 1004:
                    if(flagPez == 0)
                    {
                        printf("Peces: \n\n");

                        flagPez =1;
                    }
                    printf("Id  |Nombre              |Edad |Vacunado|Tipo      |Color     |Cliente \n");
                    printf("----|--------------------|-----|--------|----------|----------|---------\n");
                    mostrarMascota(auxMascota[i], tipos, colores, clientes, tam);
                    printf("----|--------------------|-----|--------|----------|----------|---------\n\n");
                    break;


                }

            }


            break;
        case 'e':
            system("cls");
            mostrarColores(colores, tamB);
            printf("Ingrese id del color: ");
            scanf("%d", &idColor);
            while(validarIdColor(idColor, tipos, tam) == 0)
            {
                printf("Ingrese un id valido: ");
                fflush(stdin);
                scanf("%d", &idColor);
            }

            mostrarTipos(tipos, tamB);
            printf("Ingrese id del tipo: ");
            scanf("%d", &idTipo);
            while(validarIdTipo(idTipo, tipos, tam) == 0)
            {
                printf("Ingrese un id valido: ");
                fflush(stdin);
                scanf("%d", &idTipo);
            }

            for(int i=0 ; i<tam ; i++)
            {
                if(idColor == mascota[i].idColor)
                {
                    contadorMascotaColor++;
                }

                if(idTipo == mascota[i].idTipo)
                {
                    contadorMascotaTipo++;
                }
            }
            system("cls");
            cargarDescripcionColores(colores, tamB, idColor, descColor);
            cargarDescripcionTipos(tipos, tamB, idTipo, descTipo);

            printf("Hay %d mascotas del color %s\n", contadorMascotaColor, descColor);
            printf("Hay %d mascotas del tipo %s\n", contadorMascotaTipo, descTipo);
            break;
        case 'f':
            system("cls");
            for(int i=0 ; i<tam ; i++)
            {
                switch(mascota[i].idColor)
                {
                case 1000:
                    contadorNegro++;
                    break;
                case 1001:
                    contadorBlanco++;
                    break;
                case 1002:
                    contadorRojo++;
                    break;
                case 1003:
                    contadorGris++;
                    break;
                case 1004:
                    contadorAzul++;
                    break;
                }
            }


                contadoresColor[0] = contadorNegro;
                contadoresColor[1] = contadorBlanco;
                contadoresColor[2] = contadorRojo;
                contadoresColor[3] = contadorGris;
                contadoresColor[4] = contadorAzul;

            for(int i=0 ; i<tamB ; i++)
            {
                if(i == 0)
                {
                    colorMax = contadoresColor[i];
                    strcpy(colorMaxDesc, "negro");
                }
                else if (contadoresColor[i] > colorMax)
                {
                    colorMax = contadoresColor[i];
                    switch(i)
                    {
                    case 1:
                        strcpy(colorMaxDesc, "blanco");
                        break;
                    case 2:
                        strcpy(colorMaxDesc, "rojo");
                        break;
                    case 3:
                        strcpy(colorMaxDesc, "gris");
                        break;
                    case 4:
                        strcpy(colorMaxDesc, "azul");
                        break;
                    }
                }
            }

            printf("El color con mas cantidad de mascotas es el %s y tiene %d mascotas\n", colorMaxDesc, colorMax);

            break;
        case 'x':
            if(confirmarSalida())
            {
                salirInformes = 's';
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salirInformes == 'n');

        todoOk =1;
    }
    return todoOk;

}
