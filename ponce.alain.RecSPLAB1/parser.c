#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "peliculas.h"
#include "parser.h"

int parser_PeliFromText(FILE* pFile , LinkedList* pListaPelis)
{
    int todoOk = 0;
    int cantidad = 0;
    char buffer[4][128];
    eMovie* auxPeli = NULL;

    if(pFile != NULL && pListaPelis != NULL)
    {
        ll_clear(pListaPelis);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cantidad == 4)
            {
                auxPeli = peli_newParametros(atoi(buffer[0]),buffer[1],buffer[2],atoi(buffer[3]));
                if(auxPeli != NULL)
                {
                    if( !ll_add(pListaPelis, auxPeli))
                    {
                        todoOk = 1;
                    }
                }
            }
        }
    }
    return todoOk;
}
