#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct{
    int id;
    char nombre[21];
    char sexo;
    int isEmpty;
}typedef eCliente;

eCliente buscarCliente(eCliente vecCliente[],int tam,int id);

#endif // CLIENTE_H_INCLUDED
