#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "Validaciones.h"
int validacionVacuna(char* vacunado)
{
    int ret = -1;

    if(vacunado != NULL )
    {
        while(*vacunado != 's' && *vacunado != 'n')
        {
            getCharacter(vacunado, "\nError. ingrese una vacuna valida (s - n): ");
        }
        ret = 0;
    }
    return ret;
}
int validacionSexo(char* sexo)
{
    int ret = -1;
    if(sexo != NULL)
    {
        while(sexo != 'F' && sexo != 'f' && sexo != 'm' && sexo != 'M')
        {
            getCharacter(&sexo, "\nIngrese sexo (m/f) : ");
        }
        ret = 0;
    }
    return ret;
}
