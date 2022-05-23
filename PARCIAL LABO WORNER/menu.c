#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"

int menu(char* respuesta)
{
	int ret = -1;
	char r;

	if(respuesta != NULL)
	{
		printf("\nA-ALTA MASCOTA\n");
		printf("B-MODIFICAR MASCOTA\n");
		printf("C-BAJA MASCOTA\n");
		printf("D-LISTAR MASCOTAS\n");
		printf("E-LISTAR TIPOS\n");
		printf("F-LISTAR COLOR\n");
		printf("G-LISTAR SERVICIO\n");
		printf("H-ALTA TRABAJO\n");
		printf("I-LISTAR TRABAJOS\n");
		printf("J-MOSTRAR COLORES SELECCIONADOS\n");
		printf("K-INFORMAR PROMEDIO DE VACUNADOS\n");
		printf("L-INFORMAR MASCOTAS DE MENOR EDAD\n");
		printf("M-LISTAR MASCOTAS SEPARADAS POR TIPO\n");
		printf("N-CONTAR MASCOTAS DE TIPO Y COLOR ELEGIDAS\n");
		printf("O-COLOR/ES CON MAS MASCOTAS\n");
		printf("P-MOSTRAR TRABAJOS EN MASCOTA ELEGIDA\n");
		printf("Q-MOSTRAR SUMA DE IMPORTES DE SERVICIOS EN MASCOTA ELEGIDA\n");
		printf("R-MOSTRAR MASCOTAS A LAS QUE SE LE REALIZO EL SERVICIO ELEGIDO\n");
		printf("T-MOSTRAR SERVICIOS EN FECHA ELEGIDA\n");
		printf("S-SALIR\n");
		printf("Ingrese una opcion: ");
		fflush(stdin);
		scanf("%c", &r);
		r = toupper(r);
		while(r != 'A' && r != 'B' && r != 'C' && r!='D' && r!='E' && r != 'F' && r != 'G' &&  r != 'H' && r != 'I' && r != 'J' && r != 'S' && r != 'K' && r != 'L' && r != 'M' && r!= 'N' && r!='O' && r != 'P' && r!= 'Q' && r != 'R' && r != 'T')
		{
			printf("Error, reingrese una opcion valida: ");
            fflush(stdin);
            scanf("%c", &r);
            r = toupper(r);
		}
        *respuesta = r;
		ret=0;
	}
	return ret;
}
