#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "peliculas.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pListaPelis)
{
    int todoOk = 0;
    FILE* f = fopen(path, "r");

    if(f == NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n\n");
    }
    else
    {
        parser_PeliFromText(f, pListaPelis);
        todoOk=1;
    }

    fclose(f);

    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pListaPelis)
{
    int auxId;
	char auxTitulo[128];
	char auxGenero[128];
	float auxRating;

    int todoOk = 0;

    eMovie* auxPeli;

    FILE* f;

    if(path!=NULL && pListaPelis!=NULL)
	{
		f = fopen(path,"w");
		if(f != NULL && ll_len(pListaPelis) >0)
        {
            fprintf(f,"id_peli,titulo,genero,rating\n");

            for(int i= 0; i<ll_len(pListaPelis); i++)
            {
                auxPeli = ll_get(pListaPelis, i);

                if(auxPeli != NULL && get_Id(auxPeli, &auxId)
                                     && get_Titulo(auxPeli, auxTitulo)
                                     && get_Genero(auxPeli, auxGenero)
                                     && get_Rating(auxPeli, &auxRating))
                {
                    fprintf(f, "%d,%s,%s,%.1f\n", auxId, auxTitulo, auxGenero, auxRating);
                    todoOk=1;
                    //break;
                }
                else
                {
                    ll_pop(pListaPelis, i);
                    printf("\nNo se pudo guardar el archivo");
                }
            }
        }
        else
        {
            printf("No se pudo abrir el archivo");
        }
    }

    fclose(f);

    return todoOk;
}
int controller_listarPelis(LinkedList* pListaPelis)
{
    int todoOk = 0;
    int tam;
    eMovie* auxPeli = NULL;
    if(pListaPelis != NULL)
    {
        tam = ll_len(pListaPelis);
        printf("  Id     Titulo                                   Genero                Rating\n");
        printf("------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            auxPeli = (eMovie*) ll_get(pListaPelis,i);
            if(auxPeli != NULL)
            {
                controller_listarPeli(auxPeli);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int controller_listarPeli(eMovie* unaPeli)
{
    int todoOk = 0;
    int id;
    char titulo[128];
    char genero[128];
    float rating;

    if(unaPeli != NULL &&
            get_Id(unaPeli,&id) &&
            get_Titulo(unaPeli,titulo) &&
            get_Genero(unaPeli,genero) &&
            get_Rating(unaPeli,&rating))
    {
        printf(" %3d     %-40s %-11s           %.1f\n",
               id,
               titulo,
               genero,
               rating);
        todoOk = 1;
    }
    return todoOk;
}
