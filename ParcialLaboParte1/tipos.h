#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPOS_H_INCLUDED

int cargarDescripcionTipos(eTipo tipos[], int tam, int idTipos, char descripcion[]);

int mostrarTipos(eTipo tipos[], int tam);

//0 si no existe el id, 1 si existe el id

int validarIdTipo(int id, eTipo tipos[], int tam);
