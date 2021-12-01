#include "LinkedList.h"
#include "peliculas.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief Abre el archivo solicitado para luego poder parsearlo
 *
 * \param path char* Archivo de texto que querramos abrir
 * \param pListaPelis LinkedList* Lista de Peliculas
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pListaPelis);
/** \brief Crea un archivo de texto
 *
 * \param path char* Nombre del archivo de texto a crear
 * \param pListaPelis LinkedList* Lista de Peliculas a guardar
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int controller_saveAsText(char* path , LinkedList* pListaPelis);
/** \brief Muestro listado de las peliculas de una LinkedList
 *
 * \param pListaPelis LinkedList* Puntero a una LinkedList
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */

int controller_listarPelis(LinkedList* pListaPelis);
/** \brief Muestro los datos de UNA pelicula
 *
 * \param pPais eMovie* Puntero a una Pelicula
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int controller_listarPeli(eMovie* unaPeli);

