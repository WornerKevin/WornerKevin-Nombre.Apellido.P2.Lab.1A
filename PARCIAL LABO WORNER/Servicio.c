#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Servicio.h"

eServicio buscarServicio(eServicio vecServ[],int tamServ,int id)
{
    eServicio auxServicio;

	if(vecServ != NULL && tamServ > -1 && id > -1)
	{
		for(int i = 0; i< tamServ;i++)
		{
			if(vecServ[i].id == id)
			{
				auxServicio = vecServ[i];
			}
		}
	}
	return auxServicio;
}
int mostrarServicios(eServicio list[], int tam)
{
    int ret = -1;
    if(list!=NULL && tam > 0)
    {
        printf(" ID      |    DESCRIPCION       |    PRECIO   |  \n");
        for(int i = 0; i < tam; i++)
        {
            printf("  %d  |    %15s   |  %.2f     |  \n",
                   list[i].id,
                   list[i].descripcion,
                   list[i].precio);
        }
        ret = 0;
    }
    return ret;
}
