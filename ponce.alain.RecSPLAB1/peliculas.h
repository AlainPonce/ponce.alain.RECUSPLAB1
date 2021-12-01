#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[128];
    float rating;
} eMovie;

#endif // PELICULA_H_INCLUDED

/** \brief Creo un puntero sobre la estructura ePeli para crear nuevos datos
 *
 * \return ePeli* retorna un puntero a ePeli o NULL si hay error.
 *
 */
eMovie* peli_new();
/** \brief Creo un puntero sobre la estructura ePeli con los datos cargados anteriormente
 *
 * \param id int numero de id
 * \param titulo char* nombre de la pelicula
 * \param genero char* genero de la pelicula
 * \param duracion int duracion de la pelicula
 * \return ePais* retorna un puntero a ePais o NULL si hay error.
 *
 */
eMovie* peli_newParametros(int id, char* titulo, char* genero, int duracion);

/** \brief libera la memoria de un puntero a una estructura ePeli
 *
 * \param this ePeli* puntero a UNA pelicula
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int peli_delete(eMovie* this);
/** \brief Cargo el campo Id de una estructura ePeli
 *
 * \param this ePeli* puntero a una pelicula
 * \param id int numero de id de la pelicula
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int set_Id(eMovie* this, int id);
/** \brief carga el campo TITULO de una estructrura ePeli
 *
 * \param this ePeli* puntero a un pais
 * \param titulo char* nombre de la pelicula
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int set_Titulo(eMovie* this, char* nombre);
/** \brief carga el campo GENERO de una estructrura ePeli
 *
 * \param this ePeli* puntero a un pais
 * \param genero char* genero de la pelicula
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int set_Genero(eMovie* this, char* genero);
/** \brief Cargo el campo DURACION de una estructura ePeli
 *
 * \param this ePeli* puntero a una pelicula
 * \param duracion int duracion  de la pelicula
 * \return int retorna 1 si no hubo problemas o 0 si hay un error
 *
 */
int set_Rating(eMovie* this, float rating);
/** \brief toma el valor del campo ID de una estructura ePeli
 *
 * \param this ePeli* puntero a una pelicula
 * \param id int* puntero donde se guarda el numero de id
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int get_Id(eMovie* this, int* id);
/** \brief toma la cadena de caracteres del campo TITULO de una estructura ePeli
 *
 * \param this ePeli* puntero a un pais
 * \param char* titulo puntero donde se guarda el titulo
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int get_Titulo(eMovie* this, char* titulo);
/** \brief toma la cadena de caracteres del campo GENERO de una estructura ePeli
 *
 * \param this ePeli* puntero a un pais
 * \param char* genero puntero donde se guarda el titulo
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int get_Genero(eMovie* this, char* genero);
/** \brief toma el valor del campo DURACION de una estructura ePeli
 *
 * \param this ePeli* puntero a ua pelicula
 * \param id int* puntero donde se guarda el numero de la duracion
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int get_Rating(eMovie* this, float* rating);

/** \brief Asigna aleatoriamente segun los rangos otorgados Ratings a un puntero eMovie
 *
 * \param pPeli void* puntero a eMovie
 * \return void*
 *
 */
void* peli_asignarRating(void* pPeli);
/** \brief Asigna aleatoriamente segun los rangos otorgados un Genero a un puntero eMovie
 *
 * \param pPeli void* puntero a eMovie
 * \return void*
 *
 */
void* peli_asignarGeneros(void* pPeli);
/** \brief  comparan el genero de una eMovie pasada por puntero con otro genero hardcodeado
 *
 * \param pPeli void* puntero de eMovie que debe ser casteada para obtener su genero y comparar
 * \return int retornan 1 si los generos coinciden o 0 si no coinciden
 *
 */
int peli_filtroAccion(void* pPeli);
/** \brief  comparan el genero de una eMovie pasada por puntero con otro genero hardcodeado
 *
 * \param pPeli void* puntero de eMovie que debe ser casteada para obtener su genero y comparar
 * \return int retornan 1 si los generos coinciden o 0 si no coinciden
 *
 */
int peli_filtroComedia(void* pPeli);
/** \brief  comparan el genero de una eMovie pasada por puntero con otro genero hardcodeado
 *
 * \param pPeli void* puntero de eMovie que debe ser casteada para obtener su genero y comparar
 * \return int retornan 1 si los generos coinciden o 0 si no coinciden
 *
 */
int peli_filtroDrama(void* pPeli);
/** \brief  comparan el genero de una eMovie pasada por puntero con otro genero hardcodeado
 *
 * \param pPeli void* puntero de eMovie que debe ser casteada para obtener su genero y comparar
 * \return int retornan 1 si los generos coinciden o 0 si no coinciden
 *
 */
int peli_filtroTerror(void* pPeli);
/** \brief Ordena las peliculas segun su rating
 *
 * \param peli1 void* pelicula 1 a comparar
 * \param peli2 void* pelicula 2 a comparar
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 */
int peli_cmpRatings(void* peli1, void* peli2);
/** \brief Ordena las peliculas segun su genero
 *
 * \param peli1 void* pelicula 1 a comparar
 * \param peli2 void* pelicula 2 a comparar
* \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int peli_cmpGenero(void* peli1, void* peli2);
