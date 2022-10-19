#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED

int cargarDescripcionServicios(eServicio servicios[], int tam, int idServicios, char descripcion[]);

int mostrarServicios(eServicio servicios[], int tam);

//0 invalido 1 valido
int validarIdServicio(int id, eServicio servicios[], int tam);
