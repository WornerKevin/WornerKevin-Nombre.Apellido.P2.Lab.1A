#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct{
    int dia;
    int mes;
    int anio;

}typedef eFecha;


/** \brief Pide los datos para cargar la fecha y los valida
 *
 * \param dia Puntero a Dia
 * \param mes Puntero a Mes
 * \param anio Puntero a Anio
 * \return retorna -1 si ocurrio un error o 0 si se ejecuto Ok
 */
int pedirFecha(int* dia, int* mes, int* anio);

#endif // FECHA_H_INCLUDED
