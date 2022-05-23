#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


struct{
    int id;
    char descripcion[21];

}typedef eTipo;


/** \brief Busca por id los Tipos cargados
 *
 * \param tipo array de estructura
 * \param tam tamanio del array
 * \param id
 * \return -1 Error. el Auxiliar de la estructura si es Ok.
 */
eTipo buscarTipo(eTipo tipo[],int tamTipo,int id);

int mostrarTipo(eTipo list[], int tam);
#endif // TIPO_H_INCLUDED
