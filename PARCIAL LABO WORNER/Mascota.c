#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mascota.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Color.h"
#include "Cliente.h"
#include "input.h"

#include "Fecha.h"

#include "Validaciones.h"
static int  id = 0;

int initMascota(eMascota* list, int tam,eTrabajo* vec, eCliente* vecCliente, int tamCliente, int tamT)
{
    int ret = -1;
    if(list != NULL && tam > 0)
    {
		for(int i=0; i<tam; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
		for(int i = 0; i < tamT; i++)
        {
            vec[i].id = -1;
            vec[i].isEmpty = 1;
        }
        for(int i = 0; i < tamCliente; i++)
        {
            vecCliente[i].id = -1;
            vecCliente[i].isEmpty = 1;
        }
        ret = 0;
    }
    return ret;
}
int obtenerID()
{
	return id += 1;
}
int buscarLibreMascota(eMascota list[],int tam)
{
	int ret= -1;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam ;i++)
		{
			if(list[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
eMascota buscarMascotaId(eMascota list[],int tam,int id)
{
    eMascota auxMascota;

	if(list != NULL && tam > 0 && id > -1)
	{
		for(int i = 0; i< tam;i++)
		{
			if(list[i].id == id)
			{
				auxMascota= list[i];
			}
		}
	}
	return auxMascota;
}
int buscarMascota(eMascota list[],int tam, int id)
{
	int ret= -1;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam ;i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int addMascota(eMascota* list, eTrabajo* vec,int tamMasc,int* id,int idTipo,int idColor,char nombre[],int edad,char vacunado,int idServicio,int dia,int mes,int anio, char nombreCliente[], char sexo, int* idCliente, eCliente* cliente)
{
    int ret = -1;
    int i;
    if(list != NULL && id != NULL && tamMasc > 0)
    {
        i =buscarLibreMascota(list,tamMasc);
        if(i != -1)
        {
            list[i].id = *id;
            cliente[i].id = *idCliente;
            list[i].idTipo = idTipo;
            list[i].idColor = idColor;
            list[i].edad = edad;
            list[i].vacunado = vacunado;
            strcpy(list[i].nombre, nombre);
            vec[i].id = obtenerID();
            vec[i].idServicio = idServicio;
            vec[i].idMascota = *id;
            vec[i].fecha.dia = dia;
            vec[i].fecha.mes = mes;
            vec[i].fecha.anio = anio;
            strcpy(cliente[i].nombre, nombreCliente);
            cliente[i].sexo = sexo;

            cliente[i].isEmpty = 0;
            vec[i].isEmpty = 0;
            list[i].isEmpty = 0;
            ret = 0;
        }

    }
    return ret;
}
int AltaMascota(eMascota* list, int tamMasc, int* id, eTrabajo* vec, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicio[], int tamServ, eCliente* cliente, int tamCliente, int* idCliente)
{
    int ret = -1;

    int idTipo;
    int idColor;
    char vacunado;
    char nombre[21];
    int edad;

    int idServicio;
    int dia;
    int mes;
    int anio;

    char nombreCliente[20];
    char sexo;

    if(list != NULL && tamMasc> 0)
    {
        printf("\nID = %d\n", *id);
        getString(nombreCliente, "\nIngrese el nombre del cliente: ", "\nError. Ingrese un nombre valido: ", 20);
        getCharacter(&sexo, "\nIngrese sexo (m/f) : ");
        getString(nombre, "\nIngrese el nombre de la mascota: ", "\nError. Vuelva a ingresar el nombre: ", 20);
        mostrarTipo(tipo, tamTipo);
        getInteger(&idTipo,"\nIngrese el tipo: ","\nError. Vuelva a ingresar el tipo: ", 1000, 1004);
        mostrarColor(color, tamColor);
        getInteger(&idColor, "\nIngrese el color: ","\nError. Vuelva a ingresar el color: ", 5000, 5004);
        getCharacter(&vacunado, "\nIngrese si esta vacunado(s o n): ");
        validacionVacuna(&vacunado);
        getInteger(&edad, "\nIngrese la edad: ", "\nError. Vuelva a ingresar una edad valida", 1, 50);
        mostrarServicios(servicio, tamServ);
        getInteger(&idServicio, "\nIngrese el servicio: ","\nError. Vuelva a ingresar el servicio: ", 20000, 20002);
        pedirFecha(&dia, &mes, &anio);
        addMascota(list, vec, tamMasc, id, idTipo, idColor, nombre,edad, vacunado, idServicio, dia, mes, anio, nombreCliente, sexo, idCliente, cliente);
        *id = *id + 1;
        *idCliente = *idCliente + 1;
        printf("\nSe creo Exitosamente.\n");
        ret = 0;
    }
    return ret;
}

int printMascota(eMascota list, int tam,eTrabajo vec,int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ, eCliente cliente[], int tamCliente)
{
	eTipo auxTipo;
	eColor auxColor;
	eServicio auxServicio;
	eCliente auxCliente;
	if(vecTipo != NULL && vecColor != NULL && vecServ != NULL)
    {
		auxTipo = buscarTipo(vecTipo, tamTipo, list.idTipo);
		auxColor = buscarColor(vecColor,tamColor, list.idColor);
		auxServicio = buscarServicio( vecServ, tamServ, vec.idServicio);
        auxCliente = buscarCliente(cliente, tamCliente, list.idCliente);
        printf("%2d  \t|%10s\t|   %10s   |   %9s  |  %2d  |  %c    | %02d/%02d/%02d |  %10s | %15s\n",
                list.id,
                list.nombre,
                auxTipo.descripcion,
                auxColor.nombreColor,
                list.edad,
                list.vacunado,
                vec.fecha.dia, vec.fecha.mes, vec.fecha.anio,
                auxServicio.descripcion,
                auxCliente.nombre);
    }

	return 0;
}
int listarMascotas(eMascota list[],int tam, eTrabajo vec[],int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("ID\t|   Nombre \t|   Tipo    \t |   Color \t|  Edad  |   Vacunado |    Fecha   |  Servicio  | Nombre Cliente |\n");
        printf("--------|---------------|----------------|--------------|---------------|---------------|----------------|------------|\n");
        for(int i=0; i < tam; i++)
        {
            if( list[i].isEmpty == 0)
            {
               printMascota(list[i], tam ,vec[i],tamT,vecTipo,tamTipo,vecColor,tamColor,vecServ,tamServ, cliente, tamCliente);
            }
        }
        printf("\n\n");

        ret = 0;
    }
    return ret;
}
int removeMascota(eMascota* list, int tam, int id)
{
    int ret = -1;

    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].id == id)
            {
                list[i].isEmpty = 1;
                ret = 0;
                break;
            }
        }
    }

    return ret;
}
int EliminarMascota(eMascota* list, int tam)
{
    int ret = -1;
    int id;
    int i = -1;
    if(list != NULL && tam > 0)
    {
        printf("\nIngrese el ID de la Mascota que desea eliminar: ");
        scanf("%d", &id);
        i = removeMascota(list, tam, id);
        if(i == 0)
        {
            printf("\nMascota eliminada correctamente.");
            ret = 0;
        }
            else
            {
                printf("ERROR. El ID ingresado no existe.");
            }



    }
    return ret;
}
int modificarMascotas(eMascota* list,int tam, eTrabajo* vec,int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ, eCliente cliente[], int tamCliente)
{
    eMascota mascotaModificada;
    //eTrabajo trabajoModificado;
    int ret = -1;
    int id;
    int opcion;
    int i = -1;

    if(list != NULL && tam > 0)
    {
        listarMascotas(list, tam, vec, tamT,vecTipo, tamTipo, vecColor, tamColor, vecServ, tamServ, cliente, tamCliente);
        printf("\nIngrese el numero de ID de la Mascota: ");
        scanf("%d", &id);
        i = buscarMascota(list, tam, id);
        if(i != -1)
        {
            mascotaModificada = list[i];
            printf("\nID = %d\n", id);
            getInteger(&opcion, "\nMODIFICAR:\n1-Tipo\n2-Vacunado\n3-Atras\nIngrese la opcion: ",
                       "\nError, ingrese una opcion valida: ", 1,3);
            switch(opcion)
            {
                case 1:
                    mostrarTipo(vecTipo, tamTipo);
                    getInteger(&mascotaModificada.idTipo,"\nIngrese el tipo: ",
                   "\nError. Vuelva a ingresar el tipo: ", 1000, 1004);
                break;
                case 2:
                    getCharacter(&mascotaModificada.vacunado, "\nIngrese si esta vacunado(s o n): ");
                    break;
                case 3:
                    system("pause");
                    break;
            }
            if(opcion != 3)
            {
                list[i] = mascotaModificada;
                //vec[i] = trabajoModificado;
                printf("\nSe modifico Exitosamente.\n");
                ret = 0;
            }

        }
        else
        {
            printf("\nError. El ID ingresado no existe.\n");
        }
    }
        return ret;
}

int sortMascotas(eMascota* list, int tam, eTrabajo* vec)
{
    int ret = -1;
    eMascota aux;
    eTrabajo auxTrabajo;
    int j;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i = 0; i < tam -1; i++)
        {
            for(j = i+1; j < tam; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    if((list[i].idTipo == list[j].idTipo && strcmp(list[i].nombre, list[j].nombre)== 1 )|| list[i].idTipo > list[j].idTipo)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                        auxTrabajo = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxTrabajo;
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
int listarTipoMascota(eTipo list[],int tam, eMascota vec[], int tamM)
{
	int ret = -1;
	eTipo auxTipo;

	if(list != NULL && tam > 0 && tamM > 0 && vec != NULL)
	{
		printf("ID     |     TIPO");
		for(int i=0;i<tamM;i++)
		{

			if(vec[i].isEmpty == 0)
			{
				auxTipo = buscarTipo(list, tam, vec[i].idTipo);
				printf("\n %2d   | %20s\n",
				vec[i].idTipo,
				auxTipo.descripcion);

			}
		}
		ret= 0;
	}

	return ret;
}

int listarColorMascota(eColor list[],int tam, eMascota vec[], int tamM)
{
	int ret = -1;
	eColor auxColor;

	if(list != NULL && tam > 0 && tamM > 0 && vec != NULL)
	{
		printf("ID     |     TIPO");
		for(int i=0;i<tamM;i++)
		{

			if(vec[i].isEmpty == 0)
			{
				auxColor = buscarColor(list, tam, vec[i].idColor);
				printf("\n %2d   | %20s\n",
				vec[i].idColor,
				auxColor.nombreColor);

			}
		}
		ret= 0;
	}

	return ret;
}
int listarServicioMascota(eServicio list[],int tam, eTrabajo vec[], eMascota vecM[], int tamT)
{
	int ret = -1;
	eServicio auxServicio;

	if(list != NULL && tam > 0 && tamT > 0 && vec != NULL)
	{
		printf("ID       |           TIPO           |     PRECIO    |\n");
		for(int i=0;i<tamT;i++)
		{

			if(vec[i].isEmpty == 0)
			{
				auxServicio = buscarServicio(list, tam, vec[i].idServicio);
				printf(" %2d   |   %20s   |     %.2f    |\n",
				vec[i].idServicio,
				auxServicio.descripcion,
				auxServicio.precio);

			}
		}
		ret= 0;
	}

	return ret;
}
int listarTrabajo(eTrabajo vec[], int tamT, eMascota list[], int tamMascota, eServicio vecServ[], int tam)
{
    int ret = -1;
    eServicio aux;
    eMascota auxMascota;
	if(vec != NULL && list != NULL && tam > 0 && tamT > 0 )
	{
		printf("ID    |         MASCOTA          |     SERVICIO          |   PRECIO    |    FECHA   |\n");
		printf("------|--------------------------|-----------------------|-------------|------------|\n");
		for(int i = 0; i < tamT; i++)
		{

			if(vec[i].isEmpty == 0 && vec[i].id > -1)
			{
                aux = buscarServicio(vecServ, tam, vec[i].idServicio);
                auxMascota = buscarMascotaId(list, tamMascota, vec[i].idMascota);
				printf(" %2d   |   %20s   |  %20s |  %.2f     |%02d/%02d/%02d  |\n",
				auxMascota.id,
				auxMascota.nombre,
				aux.descripcion,
				aux.precio,
				vec[i].fecha.dia,
				vec[i].fecha.mes,
				vec[i].fecha.anio);
			}
		}
		ret= 0;
	}

	return ret;
}
int altaTrabajo(eMascota* list, int tam, eTrabajo* trabajo, int tamTrabajo, eTipo* tipo,int tamTipo, eColor* color, int tamColor, eServicio* servicio, int tamServ, eCliente* cliente, int tamCliente)
{
    int ret = -1;
    int idMascota;
    int idServicio;
    int i = -1;
    int auxiliar;
    if(list != NULL && trabajo != NULL && tipo != NULL && color != NULL && servicio != NULL)
    {
        listarMascotas(list, tam, trabajo, tamTrabajo, tipo, tamTipo, color, tamColor, servicio, tamServ, cliente, tamCliente);
        printf("\nElija una mascota: ");
        scanf("%d", &idMascota);
        i = buscarMascota(list, tam, idMascota);
        if(i != -1)
        {
            mostrarServicios(servicio, tamServ);
            getInteger(&idServicio, "\nElija un servicio: ", "Error. Ingrese un servicio valido: ", 20000, 20002);
            auxiliar = buscarLibreTrabajo(trabajo, tamTrabajo);
            if(auxiliar > -1)
            {
                trabajo[auxiliar].idServicio = idServicio;
                trabajo[auxiliar].idMascota = idMascota;
                trabajo[auxiliar].id = obtenerID();
                trabajo[auxiliar].fecha.dia = trabajo[i].fecha.dia;
                trabajo[auxiliar].fecha.mes = trabajo[i].fecha.mes;
                trabajo[auxiliar].fecha.anio = trabajo[i].fecha.anio;
                trabajo[auxiliar].isEmpty = 0;
                ret = 0;
            }
            else
            {
                printf("\nNo se pueden cargar mas trabajos");
            }

        }
            else
            {
                printf("\nEl ID ingresado no existe\n");
            }

    }

    return ret;
}
int buscarLibreTrabajo(eTrabajo list[],int tam)
{
	int ret= -1;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam ;i++)
		{
			if(list[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

/*SEGUNDA PARTE*/
int mostrarMascotasColor(eColor color[], int tamColor, eMascota list[], int tam)
{
    int ret = -1;
    int idColor;
    eColor auxColor;
    int flag = 0;
    if(color != NULL && list != NULL)
    {
        mostrarColor(color, tamColor);
        getInteger(&idColor, "\nIngrese el color: ",
                   "\nError. Ingrese un color valido: ", 5000, 5004);
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idColor == idColor)
            {
                if(flag == 0)
                {
                   printf("|  ID  |     NOMBRE         |      COLOR         |\n");
                }
                auxColor = buscarColor(color, tamColor, list[i].idColor);
                printf("|  %2d  |   %15s  |  %15s   |\n",
                      list[i].id,
                      list[i].nombre,
                      auxColor.nombreColor);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay mascotas con ese color\n");
        }
        ret = 0;
    }

    return ret;
}

int trabajosMascotas(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    int id;
    int index;
    eServicio auxServicio;
    if(trabajo != NULL && tamT > 0 && list != NULL && tamMasc > 0)
    {
        listarMascotas(list, tamMasc, trabajo, tamT,tipo,tamTipo,color,tamColor,serv, tamServ, cliente, tamCliente);
        printf("Ingrese el ID de una mascota: ");
        scanf("%d", &id);
        index = buscarMascota(list, tamMasc, id);
        if(index != -1)
        {
            printf("\n|  ID |       NOMBRE       |       TRABAJOS          |   PRECIO   |\n");
            for(int i = 0; i < tamT; i++)
            {

                if(trabajo[i].idMascota == index && trabajo[i].isEmpty == 0)
                {
                    auxServicio = buscarServicio(serv, tamServ, trabajo[i].idServicio);
                    printf("| %2d  |%15s     |   %20s  |   %.2f   |\n",
                           list[index].id,
                           list[index].nombre,
                           auxServicio.descripcion,
                           auxServicio.precio);
                }
            }
            ret = 0;
        }
        else
        {
           printf("\nEl ID ingresado no existe\n");
        }
    }
    return ret;
}
int informePromedioVacunados(eMascota* list,int tam)
{
    int ret = -1;
    int contadorMascotas = 0;
    int contador=0;
    float calculo;
    float promedio;
    if(list!=NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contador++;
               if(list[i].vacunado == 's' || list[i].vacunado == 'S')
               {
                    contadorMascotas++;
               }
            }
        }
        calculo = (float)contadorMascotas / contador;
        promedio = (float)calculo * 100;
        printf("\nEl promedio de mascotas vacunadas sobre el total es: %%%.0f \n", promedio);
    }
    return ret;
}
int mascotasMenorEdad(eMascota list[], int tam, eTrabajo vec[], int tamT, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    int edad = 0;
    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(list[i].isEmpty == 0)
            {
               if(edad == 0)
               {
                   edad = list[i].edad;
               }
               if(list[i].edad <= edad)
               {
                    edad = list[i].edad;
               }
            }
        }
        printf("ID\t|   Nombre \t|   Tipo    \t |   Color \t|  Edad  |   Vacunado |    Fecha   |  Servicio  | Nombre Cliente |\n");
        printf("--------|---------------|----------------|--------------|---------------|---------------|----------------|------------|\n");
        for(int i = 0; i< tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].edad == edad)
            {
               printMascota(list[i],tam, vec[i], tamT,tipo, tamTipo, color, tamColor, serv, tamServ, cliente, tamCliente);
            }
        }
        ret = 0;
    }
    return ret;
}
int listarMascotasTipo(eMascota list[], int tam, eTrabajo vec[], int tamT, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    int flag = 0;
    int flagPerro = 0;
    int flagRoedor = 0;
    int flagGato = 0;
    int flagPez = 0;
    if(list!=NULL && vec != NULL && tipo != NULL && color != NULL && serv != NULL && cliente != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idTipo == 1000)
            {
                if(flag == 0)
                {
                    printf("\nTIPO AVE: \n");
                }
                printMascota(list[i], tam ,vec[i], tamT, tipo, tamTipo, color, tamColor, serv, tamServ, cliente, tamCliente);
                flag++;
            }
        }
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idTipo == 1001)
            {
                if(flagPerro == 0)
                {
                    printf("\nTIPO PERRO: \n");
                }
                printMascota(list[i], tam ,vec[i], tamT, tipo, tamTipo, color, tamColor, serv, tamServ, cliente, tamCliente);
                flagPerro++;
            }
        }
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idTipo == 1002)
            {
                if(flagRoedor == 0)
                {
                    printf("\nTIPO ROEDOR: \n");
                }
                printMascota(list[i], tam ,vec[i], tamT, tipo, tamTipo, color, tamColor, serv, tamServ, cliente, tamCliente);
                flagRoedor++;
            }
        }
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idTipo == 1003)
            {
                if(flagGato == 0)
                {
                    printf("\nTIPO GATO: \n");
                }
                printMascota(list[i], tam ,vec[i], tamT, tipo, tamTipo, color, tamColor, serv, tamServ, cliente, tamCliente);
                flagGato++;
            }
        }
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idTipo == 1004)
            {
                if(flagPez == 0)
                {
                    printf("\nTIPO PEZ: \n");
                }
                printMascota(list[i], tam ,vec[i], tamT, tipo, tamTipo, color, tamColor, serv, tamServ, cliente, tamCliente);
                flagPez++;
            }
        }
        ret = 0;
    }
    return ret;
}

int mascotasColorTipo(eMascota list[], int tam, eTipo tipo[], int tamTipo, eColor color[], int tamColor)
{
    int ret = -1;
    int tipoElegido;
    int colorElegido;
    int contador = 0;
    if(list!=NULL && tam > 0 && tipo != NULL && color !=NULL)
    {
        mostrarTipo(tipo, tamTipo);
        getInteger(&tipoElegido, "\nIngrese el tipo: ", "\nError. Ingrese un tipo valido: ", 1000, 1004);
        mostrarColor(color, tamColor);
        getInteger(&colorElegido, "\nIngrese el color: ", "\nError. Ingrese un color valido: ", 5000, 5004);
        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idTipo == tipoElegido && list[i].idColor == colorElegido)
            {
                contador++;
            }
        }
        if(contador > 0)
        {
            printf("\nHay %2d mascotas con ese tipo y ese color\n", contador);
        }
        else
        {
          printf("\nNo se encontro ninguna mascota con ese tipo y ese color\n");
        }

        ret = 0;
    }
    return ret;
}

int mostrarColorConMasCantidad(eColor color[], int tamColor, eMascota list[], int tam)
{
    int ret = -1;
    int contadorNegro = 0;
    int contadorBlanco = 0;
    int contadorRojo = 0;
    int contadorGris = 0;
    int contadorAzul = 0;
    if(color != NULL && list!=NULL)
    {
       for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 0 && list[i].idColor == 5000)
            {
                contadorNegro++;
            }
            if(list[i].isEmpty == 0 && list[i].idColor == 5001)
            {
                contadorBlanco++;
            }
            if(list[i].isEmpty == 0 && list[i].idColor == 5002)
            {
                contadorRojo++;
            }
            if(list[i].isEmpty == 0 && list[i].idColor == 5003)
            {
                contadorGris++;
            }
            if(list[i].isEmpty == 0 && list[i].idColor == 5004)
            {
                contadorAzul++;
            }
        }
        if(contadorBlanco >= contadorAzul && contadorBlanco >= contadorNegro && contadorBlanco >= contadorGris && contadorBlanco >= contadorRojo)
        {
               printf("\nEl color Blanco tiene el maximo numero de mascotas\n");
        }
        if(contadorAzul>= contadorBlanco&& contadorAzul>= contadorNegro && contadorAzul>= contadorGris && contadorAzul>= contadorRojo)
        {
               printf("\nEl color Azul tiene el maximo numero de mascotas\n");
        }
        if(contadorNegro>= contadorBlanco&& contadorNegro>= contadorAzul&& contadorNegro>= contadorGris && contadorNegro>= contadorRojo)
        {
               printf("\nEl color Negro tiene el maximo numero de mascotas\n");
        }
        if(contadorGris>= contadorBlanco&& contadorGris>= contadorAzul&& contadorGris>= contadorNegro&& contadorGris>= contadorRojo)
        {
               printf("\nEl color Gris tiene el maximo numero de mascotas\n");
        }
        if(contadorRojo>= contadorBlanco&& contadorRojo>= contadorAzul&& contadorRojo>= contadorNegro&& contadorRojo>= contadorGris)
        {
               printf("\nEl color Rojo tiene el maximo numero de mascotas\n");
        }
        ret = 0;
    }

    return ret;
}
int mostrarTrabajosMascotaElegida(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    int id;
    int index;
    eServicio auxServicio;
    if(trabajo != NULL && tamT > 0 && list != NULL && tamMasc > 0)
    {
        listarMascotas(list, tamMasc, trabajo, tamT,tipo,tamTipo,color,tamColor,serv, tamServ, cliente, tamCliente);
        printf("Ingrese el ID de una mascota: ");
        scanf("%d", &id);
        index = buscarMascota(list, tamMasc, id);
        if(index != -1)
        {
            printf("\n|  ID |       NOMBRE       |       TRABAJOS          |   PRECIO   |\n");
            for(int i = 0; i < tamT; i++)
            {

                if(trabajo[i].idMascota == index && trabajo[i].isEmpty == 0)
                {
                    auxServicio = buscarServicio(serv, tamServ, trabajo[i].idServicio);
                    printf("| %2d  |%15s     |   %20s  |   %.2f   |\n",
                           list[index].id,
                           list[index].nombre,
                           auxServicio.descripcion,
                           auxServicio.precio);
                }
            }
            ret = 0;
        }
        else
        {
           printf("\nEl ID ingresado no existe\n");
        }
    }
    return ret;
}

int mostrarSumaDeImportes(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    int id;
    int index;
    eServicio auxServicio;
    float suma = 0;
    if(trabajo != NULL && tamT > 0 && list != NULL && tamMasc > 0)
    {
        listarMascotas(list, tamMasc, trabajo, tamT,tipo,tamTipo,color,tamColor,serv, tamServ, cliente, tamCliente);
        printf("Ingrese el ID de una mascota: ");
        scanf("%d", &id);
        index = buscarMascota(list, tamMasc, id);
        if(index != -1)
        {
            for(int i = 0; i < tamT; i++)
            {

                if(trabajo[i].idMascota == index && trabajo[i].isEmpty == 0)
                {
                    auxServicio = buscarServicio(serv, tamServ, trabajo[i].idServicio);
                    suma = suma + auxServicio.precio;
                }
            }
            printf("\nLa suma de importes de servicios de esta mascota es: %.2f", suma);
            ret = 0;
        }
        else
        {
           printf("\nEl ID ingresado no existe\n");
        }
    }
    return ret;
}
void mostrarServicioAMascotas(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int id;
    int flag = 0;
    if(trabajo != NULL && tamT > 0 && list != NULL && tamMasc > 0)
    {
        mostrarServicios(serv, tamServ);
        getInteger(&id, "\nIngrese el ID del servicio: ", "Error. Ingrese un ID de servicio valido: ", 20000,20002);
            for(int i = 0; i < tamMasc; i++)
            {

                if(trabajo[i].idServicio == id && trabajo[i].isEmpty == 0)
                {
                    printMascota(list[i], tamMasc, trabajo[i], tamT, tipo, tamTipo, color, tamColor, serv, tamServ,cliente, tamCliente);
                    flag++;
                }
            }
            if(flag == 0)
            {
                printf("\nNinguna mascota se le realizo ese servicio\n");
            }

        }
}

int mostrarServiciosPorFecha(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente)
{
    int ret = -1;
    eServicio auxServicio;
    int dia;
    int mes;
    int anio;
    int flag = 0;
    if(trabajo != NULL && list != NULL && tipo!= NULL && color != NULL && serv != NULL && cliente != NULL)
    {
        pedirFecha(&dia, &mes, &anio);
        for(int i = 0; i < tamT; i++)
        {
           if(trabajo[i].isEmpty == 0 && trabajo[i].fecha.dia == dia && trabajo[i].fecha.mes == mes && trabajo[i].fecha.anio == anio)
           {
               if(flag == 0)
               {
                  printf("ID       |           TIPO           |     PRECIO    |     FECHA    |\n");
                  flag++;
               }
               auxServicio = buscarServicio(serv, tamServ, trabajo[i].idServicio);
                  printf("  %2d    |    %20s  |  %.2f  |  %02d/%02d/%02d |\n",
                         trabajo[i].id,
                         auxServicio.descripcion,
                         auxServicio.precio,
                         trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio);
           }
        }
        if(flag == 0)
        {
            printf("\nNo se realizo ningun servicio en esa fecha\n");
        }
    }
    return ret;
}

