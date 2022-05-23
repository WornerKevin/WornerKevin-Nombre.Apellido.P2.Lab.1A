#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include "Trabajo.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Color.h"
#include "Cliente.h"
struct{
    int id;
    char nombre[21];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int idCliente;
    int isEmpty;
}typedef eMascota;

/* FUNCIONES ABM*/


/** \brief Inicializa los arrays de las estructuras mascota y trabajo
 *
 * \param list Puntero al array de Mascotas
 * \param tam Tamanio del array
 * \param vec Puntero al array de trabajo
 * \param tamT  Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int initMascota(eMascota* list, int tam,eTrabajo* vec, eCliente* vecCliente, int tamCliente, int tamT);

/** \brief Realiza el ID autoincremental para la estructura Trabajo
 *
 * \return retorna el ID
 */
int obtenerID();

/** \brief Realiza una busqueda de una posicion del array mascota libre
 *
 * \param list array de Mascotas
 * \param tam Tamanio del array
 * \return retorna el index si es OK -1 si da Error
 *
 */
int buscarLibreMascota(eMascota list[],int tam);

/** \brief Busca por id las mascotas cargadas
 *
 * \param list
 * \param tam
 * \param id
 * \return -1 Error. el Auxiliar de la estructura si es Ok.
 */
eMascota buscarMascotaId(eMascota list[],int tam,int id);


/** \brief Busca una mascota que este cargada con el ID que se le pasa por parametro
 *
 * \param list Array de Mascotas
 * \param tam Tamanio del array
 * \param id
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int buscarMascota(eMascota list[],int tam, int id);

/** \brief Realiza la carga logica de la estrucura Mascota y Trabajo
 *
 * \param list Puntero al array de Mascotas
 * \param vec Puntero al array de trabajo
 * \param tamMasc  Tamanio del array
 * \param id Puntero a ID
 * \param idTipo
 * \param idColor
 * \param nombre
 * \param edad
 * \param vacunado
 * \param idServicio
 * \param dia
 * \param mes
 * \param anio
 * \return retorna el index si es OK -1 si da Error
 *
 */
int addMascota(eMascota* list, eTrabajo* vec,int tamMasc,int* id,int idTipo,int idColor,char nombre[],int edad,char vacunado,int idServicio,int dia,int mes,int anio, char nombreCliente[], char sexo, int* idCliente, eCliente* cliente);



/** \brief Realiza el pedido de datos para dar el alta
 *
 * \param list Puntero al array de Mascotas
 * \param tamMasc Tamanio del array
 * \param id Puntero a ID
 * \param vec Puntero al array de trabajo
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int AltaMascota(eMascota* list, int tamMasc, int* id, eTrabajo* vec, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicio[], int tamServ, eCliente* cliente, int tamCliente, int* idCliente);


/** \brief Elimina  de manera logica una mascota cargada
 *
 * \param list Puntero al array de Mascotas
 * \param tam Tamanio del array
 * \param id
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int removeMascota(eMascota* list, int tam, int id);


/** \brief Realiza el pedido de datos para eliminar una mascota
 *
 * \param list Puntero al array de Mascotas
 * \param tamM Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int EliminarMascota(eMascota* list, int tam);

/** \brief Realiza el pedido de datos para modificar una mascota
 *
 * \param list Puntero al array de Mascotas
 * \param tam Tamanio del array
 * \param vec Puntero al array de trabajo
 * \param tamT
 * \param vecTipo
 * \param tamTipo
 * \param vecColor
 * \param tamColor
 * \param vecServ
 * \param tamServ
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int modificarMascotas(eMascota* list,int tam, eTrabajo* vec,int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ, eCliente cliente[], int tamCliente);
/* FUNCIONES LISTAR */


/** \brief Realiza el ordenamiento del array de Mascotas
 *
 * \param list Puntero al array de eMascotas
 * \param tam Tamanio del array
 * \param vec Puntero al array de eTrabajo
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int sortMascotas(eMascota* list, int tam, eTrabajo* vec);


/** \brief Muestra una mascota cargada
 *
 * \param list estructura de Mascotas
 * \param tam Tamanio del array
 * \param vec estructura de Trabajo
 * \param tamT Tamanio del array
 * \param vecTipo array
 * \param tamTipo Tamanio del array
 * \param vecColor array
 * \param tamColor Tamanio del array
 * \param vecServ array
 * \param tamServ Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int printMascota(eMascota list, int tam,eTrabajo vec,int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ, eCliente cliente[], int tamCliente);


/** \brief Lista todas las mascotas cargadas
 *
 * \param list array de estructura de Mascotas
 * \param tam Tamanio del array
 * \param vec array de estructura de Trabajo
 * \param tamT Tamanio del array
 * \param vecTipo array
 * \param tamTipo Tamanio del array
 * \param vecColor array
 * \param tamColor Tamanio del array
 * \param vecServ array
 * \param tamServ Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int listarMascotas(eMascota list[],int tam, eTrabajo vec[],int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ, eCliente cliente[], int tamCliente);


/** \brief Lista los tipos de mascotas Cargados
 *
 * \param list array estructura de Tipo
 * \param tam Tamanio del array
 * \param vec estructura de Mascota
 * \param tamM Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int listarTipoMascota(eTipo list[],int tam, eMascota vec[], int tamM);


/** \brief Lista los colores de mascotas Cargados
 *
 * \param list array estructura de Color
 * \param tam Tamanio del array
 * \param vec estructura de Mascota
 * \param tamM Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int listarColorMascota(eColor list[],int tam, eMascota vec[], int tamM);

/** \brief Lista los Servicios de mascotas Cargados
 *
 * \param list array estructura de Servicio
 * \param tam Tamanio del array
 * \param vec array de estructura Trabajo
 * \param vecM array de estructura de Mascota
 * \param tamT Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int listarServicioMascota(eServicio list[],int tam, eTrabajo vec[], eMascota vecM[], int tamT);


/** \brief Lista los Trabajos Cargados
 *
 * \param vec array estructura de Trabajo
 * \param tamT Tamanio del array
 * \param List array de estructura Mascota
 * \param tamMascota Tamanio del array
 * \param vecServ array de estructura de Servicio
 * \param tam Tamanio del array
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int listarTrabajo(eTrabajo vec[], int tamT, eMascota list[],int tamMascota,  eServicio vecServ[], int tam);


/** \brief Realiza el Alta de Trabajos a partir de Mascotas ya cargadas
 *
 * \param list Puntero a estructura de Mascotas
 * \param tam Tamanio del array
 * \param vec Puntero a estructura de Trabajo
 * \param tamTrabajo Tamanio del array
 * \param tipo Estructura de Tipo
 * \param tamTipo Tamanio de la estructura tipo
 * \param Color Estructura Color
 * \param tamColor Tamanio de la estructura
 * \param servicio Estructura Servicio
 * \param tamServ Tamanio de la estructura
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 *
 */
int altaTrabajo(eMascota* list, int tam, eTrabajo* trabajo, int tamTrabajo, eTipo* tipo,int tamTipo, eColor* color, int tamColor, eServicio* servicio, int tamServ, eCliente* cliente, int tamCliente);


/** \brief Busca una posicion donde este libre Trabajo y no este cargado
 *
 * \param list Array de estructura Trabajo
 * \param  tam Tamanio del array
 * \return retorna el index si es OK -1 si da Error
 */
int buscarLibreTrabajo(eTrabajo list[],int tam);
int mostrarMascotasColor(eColor color[], int tamColor, eMascota list[], int tam);
int trabajosMascotas(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);
int informePromedioVacunados(eMascota* list,int tam);
int mascotasMenorEdad(eMascota list[], int tam, eTrabajo vec[], int tamT, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);
int listarMascotasTipo(eMascota list[], int tam, eTrabajo vec[], int tamT, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);
int mascotasColorTipo(eMascota list[], int tam, eTipo tipo[], int tamTipo, eColor color[], int tamColor);
int mostrarColorConMasCantidad(eColor color[], int tamColor, eMascota list[], int tam);
int mostrarTrabajosMascotaElegida(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);
int mostrarSumaDeImportes(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);
void mostrarServicioAMascotas(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);
int mostrarServiciosPorFecha(eTrabajo trabajo[], int tamT, eMascota list[], int tamMasc, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio serv[], int tamServ, eCliente cliente[], int tamCliente);

#endif // MASCOTA_H_INCLUDED
