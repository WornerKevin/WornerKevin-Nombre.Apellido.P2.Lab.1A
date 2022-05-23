#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct{
    int id;
    char nombreColor[21];

}typedef eColor;

/** \brief Busca por id los colores cargados
 *
 * \param color
 * \param tam
 * \param id
 * \return -1 Error. el Auxiliar de la estructura si es Ok.
 */
eColor buscarColor(eColor color[],int tam,int id);
int mostrarColor(eColor list[], int tam);

#endif // COLOR_H_INCLUDED
