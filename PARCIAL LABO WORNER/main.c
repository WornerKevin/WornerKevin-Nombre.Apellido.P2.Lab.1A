#include <stdio.h>
#include <stdlib.h>

#define TAMLIST 50
#define TAMT 500
#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMCLIENTE 200
#define TAMSERV 3

#include "menu.h"
#include "Tipo.h"
#include "Color.h"
#include "Servicio.h"
#include "Mascota.h"
#include "Trabajo.h"
#include "Harcodeo.h"

    eTipo tipos[TAMTIPO] = {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"}
        };

    eColor colores[TAMCOLOR] = {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}
        };

    eServicio servicios[TAMSERV] = {
        {20000, "Corte", 450},
        {20001, "Desparacitado", 800},
        {20002, "Castrado", 600}
        };


int main()
{
    eMascota mascotas[TAMLIST];
    eTrabajo trabajos[TAMT];
    eCliente clientes[TAMCLIENTE];
    char opcion;
    int id = 0;
    int idCliente = 0;
    int contadorMascotas = 0;
    initMascota(mascotas, TAMLIST, trabajos, clientes, TAMCLIENTE, TAMT); //INICIALIZO TODO EL ARRAY DE LA ESTRUCTURA MASCOTAS
    hardcode(mascotas, TAMLIST, trabajos, &id, &contadorMascotas, clientes, &idCliente);
    printf("\n\t***BIENVENIDO AL PROGRAMA***\n");
    do
    {

       menu(&opcion);
        switch(opcion)
        {
            case 'A':
                if(contadorMascotas < TAMLIST)
                {
                    AltaMascota(mascotas,TAMLIST,&id, trabajos, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE, &idCliente);
                    contadorMascotas++;
                    system("pause");
                }
                else
                {
                    printf("\nNo hay lugar\n");
                }
            break;
            case 'B':
                if(contadorMascotas > 0)
                {
                    modificarMascotas(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                }
                else
                {
                    printf("\nNo se cargaron mascotas.");
                }

            break;
            case 'C':
                if(contadorMascotas > 0)
                {
                    listarMascotas(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    EliminarMascota(mascotas, TAMLIST);
                    contadorMascotas--;
				}
				else
				{
					printf("No hay mascotas para eliminar\n");
				}
            break;
            case 'D':
                if(contadorMascotas > 0)
                {
                    sortMascotas(mascotas, TAMLIST, trabajos);
                    listarMascotas(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
            break;
            case 'E':
                if(contadorMascotas > 0)
                {
                    listarTipoMascota(tipos, TAMTIPO, mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
            case 'F':
                if(contadorMascotas > 0)
                {
                    listarColorMascota(colores, TAMCOLOR, mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'G':
                if(contadorMascotas > 0)
                {
                    listarServicioMascota(servicios, TAMSERV, trabajos, mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'H':
                if(contadorMascotas > 0)
                {
                    altaTrabajo(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'I':
                if(contadorMascotas > 0)
                {

                    listarTrabajo(trabajos, TAMT, mascotas, TAMLIST, servicios, TAMSERV);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'J':
                if(contadorMascotas > 0)
                {
                    mostrarMascotasColor(colores, TAMCOLOR, mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'K':
                if(contadorMascotas > 0)
                {
                    informePromedioVacunados(mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'L':
                if(contadorMascotas > 0)
                {
                    mascotasMenorEdad(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'M':
                if(contadorMascotas > 0)
                {
                    listarMascotasTipo(mascotas,TAMLIST,trabajos,TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'N':
                if(contadorMascotas > 0)
                {
                    mascotasColorTipo(mascotas, TAMLIST, tipos, TAMTIPO, colores, TAMCOLOR);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'O':
                if(contadorMascotas > 0)
                {
                    mostrarColorConMasCantidad(colores,TAMCOLOR, mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'P':
                if(contadorMascotas > 0)
                {
                    mostrarTrabajosMascotaElegida(trabajos,TAMT,mascotas,TAMLIST,tipos,TAMTIPO,colores,TAMCOLOR,servicios,TAMSERV,clientes,TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'Q':
                if(contadorMascotas > 0)
                {
                    mostrarSumaDeImportes(trabajos, TAMT, mascotas, TAMLIST, tipos,TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'R':
                if(contadorMascotas > 0)
                {
                    mostrarServicioAMascotas(trabajos, TAMT, mascotas, TAMLIST, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
                case 'T':
                if(contadorMascotas > 0)
                {
                    mostrarServiciosPorFecha(trabajos, TAMT, mascotas, TAMLIST, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV, clientes, TAMCLIENTE);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
        }
    }while(opcion != 'S');
    printf("\n\tSALISTE EXITOSAMENTE DEL PROGRAMA");
    return 0;
}
