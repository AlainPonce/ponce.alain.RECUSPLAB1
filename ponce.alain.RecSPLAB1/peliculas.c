#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"

eMovie* peli_new()
{
    eMovie* newPeli = (eMovie*) malloc(sizeof(eMovie));
    if(newPeli != NULL)
    {
        newPeli->id_peli = 0;
        strcpy(newPeli->titulo, " ");
        strcpy(newPeli->genero, " ");
        newPeli->rating = 0;

    }
    return newPeli;
}

eMovie* peli_newParametros(int id, char* titulo, char* genero, int rating)
{
    eMovie* newPeli = peli_new();
    if(newPeli != NULL)
    {
        if( !(set_Id(newPeli,id) &&
                set_Titulo(newPeli,titulo) &&
                set_Genero(newPeli,genero) &&
                set_Rating(newPeli,rating)))
        {
            peli_delete(newPeli);
            newPeli = NULL;
        }
    }
    return newPeli;
}
int peli_delete(eMovie* this)
{
    int todoOk = 0;
    if(this != NULL)
    {
        free(this);
        todoOk = 1;
    }
    return todoOk;
}

int set_Id(eMovie* this, int id)
{
    int todoOk;
    if(this != NULL && id > 0)
    {
        this->id_peli = id;
        todoOk = 1;
    }
    return todoOk;
}

int set_Titulo(eMovie* this, char* titulo)
{
    int todoOk = 0;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }
    return todoOk;
}

int set_Genero(eMovie* this, char* genero)
{
    int todoOk = 0;
     if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        todoOk = 1;
    }
    return todoOk;
}

int set_Rating(eMovie* this, float rating)
{
    int todoOk = 0;
    if(this != NULL && rating >= 0)
    {
        this->rating = rating;
        todoOk = 1;
    }
    return todoOk;
}

int get_Id(eMovie* this, int* id)
{
    int todoOk;
    if(this != NULL && id != NULL)
    {
        *id = this->id_peli;
        todoOk = 1;
    }
    return todoOk;
}

int get_Titulo(eMovie* this, char* titulo)
{
    int todoOk = 0;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }
    return todoOk;
}

int get_Genero(eMovie* this, char* genero)
{
    int todoOk = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;
}

int get_Rating(eMovie* this, float* rating)
{
    int todoOk = 0;
    if(this != NULL && rating != NULL)
    {
        *rating = this->rating;
        todoOk = 1;
    }
    return todoOk;
}
void* peli_asignarRating(void* pPeli)
{
    float rating;
    eMovie* auxPeli = NULL;
    if(pPeli != NULL)
    {

        rating = rand() % (10 - 1 + 1) + 1;
        auxPeli = (eMovie*) pPeli;
        set_Rating(auxPeli,rating);

    }
    return auxPeli;
}
void* peli_asignarGeneros(void* pPeli)
{
    int valor;

    eMovie* auxPeli = NULL;
    if(pPeli != NULL)
    {
        valor = rand() % (4 - 1 + 1) + 1;
        auxPeli = (eMovie*) pPeli;
        switch(valor)
        {
            case 1:
                set_Genero(auxPeli,"Drama");
                break;
            case 2:
                set_Genero(auxPeli,"Comedia");
                break;
            case 3:
                set_Genero(auxPeli,"Accion");
                break;
            case 4:
                set_Genero(auxPeli,"Terror");
                break;
        }
    }
    return auxPeli;
}
int peli_filtroAccion(void* pPeli)
{
    int todoOk=0;
    char genero[128]={"Accion"};
    char genero2[128];

    strcpy(genero2,((eMovie*)pPeli)->genero);

    if(strcmp(genero2,genero)==0)
    {
        todoOk=1;
    }
    return todoOk;
}
int peli_filtroComedia(void* pPeli)
{
    int todoOk=0;
    char genero[128]={"Comedia"};
    char genero2[128];

    strcpy(genero2,((eMovie*)pPeli)->genero);

    if(strcmp(genero2,genero)==0)
    {
        todoOk=1;
    }
    return todoOk;
}
int peli_filtroDrama(void* pPeli)
{
    int todoOk=0;
    char genero[128]={"Drama"};
    char genero2[128];

    strcpy(genero2,((eMovie*)pPeli)->genero);

    if(strcmp(genero2,genero)==0)
    {
        todoOk=1;
    }
    return todoOk;
}
int peli_filtroTerror(void* pPeli)
{
    int todoOk=0;
    char genero[128]={"Terror"};
    char genero2[128];

    strcpy(genero2,((eMovie*)pPeli)->genero);

    if(strcmp(genero2,genero)==0)
    {
        todoOk=1;
    }
    return todoOk;
}
int peli_cmpRatings(void* peli1, void* peli2)
{
    int todoOk = 0;

    eMovie* auxPeli1 = NULL;
    eMovie* auxPeli2 = NULL;

    if(peli1 != NULL && peli2 != NULL)
    {
        auxPeli1 = (eMovie*) peli1;
        auxPeli2 = (eMovie*) peli2;

        if(auxPeli1->rating > auxPeli2->rating)
        {
            todoOk = 1;
        }
        else if(auxPeli1->rating < auxPeli2->rating)
        {
            todoOk = -1;
        }

    }
    return todoOk;
}

int peli_cmpGenero(void* peli1, void* peli2)
{
    int todoOk = 0;

    eMovie* auxPeli1 = NULL;
    eMovie* auxPeli2 = NULL;

    if(peli1 != NULL && peli2 != NULL)
    {
        auxPeli1 = (eMovie*) peli1;
        auxPeli2 = (eMovie*) peli2;

        if(strcmp(auxPeli1->genero, auxPeli2->genero)> 0)
        {
            todoOk = 1;
        }
        else if(strcmp(auxPeli1->genero, auxPeli2->genero) <0)
        {
            todoOk = -1;
        }

    }
    return todoOk;
}
