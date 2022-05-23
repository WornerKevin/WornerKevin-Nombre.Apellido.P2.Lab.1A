#ifndef HARCODEO_H_INCLUDED
#define HARCODEO_H_INCLUDED
#include "Mascota.h"
#include "Trabajo.h"


/**
 * @brief Realiza el Hardcodeo
 *
 * @param list Array de estructura
 * @param tam Tamanio del array
 * @param vec Array de estructura
 * @param id Puntero a Id
 * @param contador Puntero a Contador
 * @return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int hardcode(eMascota* list, int tamList, eTrabajo* vec, int* id, int* contador, eCliente* cliente, int* idCliente);


#endif // HARCODEO_H_INCLUDED
