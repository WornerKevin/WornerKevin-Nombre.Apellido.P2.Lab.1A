#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Trabajo.h"
#include "Servicio.h"
#include "Mascota.h"
#include "Tipo.h"
#include "input.h"

eTrabajo buscarTrabajo(eTrabajo vec[],int tamT,int id)
{
	eTrabajo auxTrabajo;

	if(vec != NULL && tamT > -1 && id > -1)
	{
		for(int i = 0 ; i<tamT ; i++)
		{
			if(vec[i].id == id)
			{
				auxTrabajo = vec[i];
			}
		}
	}
	return auxTrabajo;
}

