#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.h"

eColor buscarColor(eColor color[],int tam,int id)
{
	eColor auxColor;

	if(color != NULL && tam > -1 && id > -1)
	{
		for(int i = 0; i<tam;i++)
		{
			if(color[i].id == id)
			{
				auxColor = color[i];
			}
		}
	}
	return auxColor;
}
int mostrarColor(eColor list[], int tam)
{
    int ret = -1;
    if(list!=NULL && tam > 0)
    {
        printf(" ID      |    NOMBRE COLOR      |\n");
        for(int i = 0; i < tam; i++)
        {
            printf("  %d  |    %15s   |  \n",
                   list[i].id,
                   list[i].nombreColor);
        }
        ret = 0;
    }
    return ret;
}
