#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;


#endif // CLIENTE_H_INCLUDED

int cargarNombreClientes(eCliente clientes[], int tam, int idClientes, char nombre[]);
