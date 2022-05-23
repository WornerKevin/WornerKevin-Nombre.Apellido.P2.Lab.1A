#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

eCliente buscarCliente(eCliente vecCliente[],int tam,int id)
{
    eCliente auxCliente;

	if(vecCliente != NULL && tam> -1 && id > -1)
	{
		for(int i = 0; i< tam;i++)
		{
			if(vecCliente[i].id == id)
			{
				auxCliente = vecCliente[i];
			}
		}
	}
	return auxCliente;
}
