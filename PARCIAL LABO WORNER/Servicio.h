#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

struct{
    int id;
    char descripcion[26];
    float precio;

}typedef eServicio;




/** \brief Busca por id los Servicios cargados
 *
 * \param vecServ array de estructura
 * \param tam tamanio del array
 * \param id
 * \return -1 Error. el Auxiliar de la estructura si es Ok.
 */
eServicio buscarServicio(eServicio vecServ[],int tamServ,int id);



/** \brief Muestra los Servicios cargados
 *
 * \param list array de estructura
 * \param tam tamanio del array
 * \return -1 Error. el Auxiliar de la estructura si es Ok.
 */
int mostrarServicios(eServicio list[], int tam);
#endif // SERVICIO_H_INCLUDED
