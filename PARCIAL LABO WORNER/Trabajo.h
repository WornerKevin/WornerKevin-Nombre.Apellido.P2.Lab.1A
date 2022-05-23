#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "Fecha.h"
struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}typedef eTrabajo;

/** \brief Busca por id los Trabajos cargados
 *
 * \param vec array de estructura
 * \param tam tamanio del array
 * \param id
 * \return -1 Error. el Auxiliar de la estructura si es Ok.
 */
eTrabajo buscarTrabajo(eTrabajo vec[],int tamT,int id);

#endif // TRABAJO_H_INCLUDED
