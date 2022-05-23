#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tipo.h"
#include "input.h"

eTipo buscarTipo(eTipo tipo[],int tamTipo,int id)
{
	eTipo auxTipo;

	if(tipo != NULL && tamTipo > -1 && id > -1)
	{
		for(int i = 0; i<tamTipo;i++)
		{
			if(tipo[i].id == id)
			{
				auxTipo = tipo[i];
			}
		}
	}
	return auxTipo;
}
int mostrarTipo(eTipo list[], int tam)
{
    int ret = -1;
    if(list!=NULL && tam > 0)
    {
        printf(" ID      |    DESCRIPCION      |\n");
        for(int i = 0; i < tam; i++)
        {
            printf("  %d  |    %15s   |  \n",
                   list[i].id,
                   list[i].descripcion);
        }
        ret = 0;
    }
    return ret;
}
