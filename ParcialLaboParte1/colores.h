#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLORES_H_INCLUDED

int cargarDescripcionColores(eColor colores[], int tam, int idColores, char descripcion[]);

int mostrarColores(eColor colores[], int tam);

//0 es invalido 1 es valido
int validarIdColor(int id, eColor colores[], int tam);
