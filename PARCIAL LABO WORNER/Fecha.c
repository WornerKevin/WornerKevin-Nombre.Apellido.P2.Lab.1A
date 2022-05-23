#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fecha.h"
#include "input.h"

int pedirFecha(int* dia, int* mes, int* anio)
{
    int ret = -1;
    int diaF;
    int mesF;
    int anioF;

    if(dia != NULL && mes != NULL && anio != NULL)
    {
        printf("\nIngrese fecha: ");
        scanf("%d/%d/%d", &diaF, &mesF, &anioF);
        while(diaF < 1 || diaF > 31 || mesF < 1 || mesF > 12 || anioF < 2000 || anioF > 2022)
        {
            printf("\nIngrese fecha valida: ");
            scanf("%d/%d/%d", &diaF, &mesF, &anioF);
        }
        *dia = diaF;
        *mes = mesF;
        *anio = anioF;
        ret = 0;
    }

    return ret;
}
