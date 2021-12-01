#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
/** \brief Parsea los datos de los paises desde un archivo de texto
 *
 * \param pFile FILE* Archivo de texto a leer
 * \param pListaPelis LinkedList* Lista de Peliculas
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int parser_PeliFromText(FILE* pFile , LinkedList* pListaPelis);
