#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"



int validarString(char string[], int min, int max, char mensaje[])
{
    int todoOk = 0;

    if(string != NULL, mensaje != NULL)
    {

        while((strlen(string) > max || strlen(string) < min) || validarNumeroString(string))
        {

            printf(mensaje);
            fflush(stdin);
            gets(string);
        }

        todoOk = 1;
    }


    return todoOk;
}


int validarNumeroString(char string[])
{
    int tieneNumero = 0;
    int limite = strlen(string);

    if(string != NULL && limite > 0)
    {
        for(int i=0; i<limite; i++)
        {
            if(isdigit(string[i]))
            {

                tieneNumero = 1;
                break;
            }
        }
    }

    return tieneNumero;
}




void validarSiNo(char* respuesta)
{
    *respuesta = tolower(*respuesta);
    if(*respuesta != NULL)
    {
        while(*respuesta != 's' && *respuesta != 'n')
        {
            printf("Error, ingrese 's' o 'n': ");
            fflush(stdin);
            scanf("%c", respuesta);
            *respuesta = tolower(*respuesta);
        }
    }
}



void validarNumeroMaxMin(int* numero, int max, int min)
{

    while(getInt(numero) != 0)
    {
       printf("Error, ingrese un numero: ");

        scanf("%d", numero);
    }
    while(*numero > max || *numero < min)
    {
        printf("Error, ingrese un numero entre %d y %d: ", min, max);
        scanf("%d", numero);
        validarNumeroMaxMin(numero, max, min);

    }
}



int confirmarSalida()
{
    char confirmacion;
    int ret;
    printf("Confirma salida?\n");
    fflush(stdin);
    scanf("%c", &confirmacion);

    validarSiNo(&confirmacion);

    if(confirmacion == 's')
    {
        ret = 1;
    }
    else if(confirmacion == 'n')
    {
        ret = 0;
    }

    return ret;
}




int validarFecha(int dia, int mes, int anio, int anioActual)
{
    int ret=0;
    if(getInt(dia) == 0 || getInt(mes) == 0 || getInt(anio) == 0)
    {
        if(anio >= anioActual && anio < 9999)
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia >= 1 && dia <= 31)
            {
                ret = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia >= 1 && dia <= 30)
            {
                ret = 1;
            }
            break;
        case 2:
            if(anio%4 == 0)
            {
                if(dia >= 1 && dia <= 29)
                {
                    ret = 1;
                }
            }
            else
            {
                if(dia >= 1 && dia <= 28)
                {
                    ret = 1;
                }
            }
            break;
        }
    }

    }

    return ret;
}


int getInt(int *pResultado)
{
    int retorno = -1;
    char buffer[64];
    if (pResultado != NULL)
    {
        if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
        {
            pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}




int myGets(char *cadena, int longitud)
{
    if (cadena != NULL && longitud > 0
            && fgets(cadena, longitud, stdin) == cadena)
    {
        fflush(stdin);
        if (cadena[strlen(cadena) - 1] == '\n')
        {
            cadena[strlen(cadena) - 1] = '\0';
        }
        return 0;
    }
    return -1;
}


int esNumerica(char *cadena)
{
    int i = 0;
    int retorno = 1;
    if (cadena != NULL && strlen(cadena) > 0)
    {
        while (cadena[i] != '\0')
        {
            if (cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
