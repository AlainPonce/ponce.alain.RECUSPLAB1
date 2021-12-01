#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "peliculas.h"

int menu();

int main()
{
    srand(time(NULL));
    char salir = 'n';
    char path [50];
    int opcion;

    int flagOrdenado = 0;

    LinkedList* listaPelis = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    LinkedList* listaGenero = NULL;
    LinkedList* listaOrdenada = NULL;

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                printf("Nombre del archivo principal: movies.csv\n\n");
                printf("Ingrese nombre del archivo para abrirlo: ");
                fflush(stdin);
                gets(path);
                if(controller_loadFromText(path, listaPelis))
                {
                    printf("\nArchivo cargado con exito!\n\n");
                }
                break;

            case 2:
                if(ll_isEmpty(listaPelis) == 0)
                {
                    system("cls");
                    controller_listarPelis(listaPelis);
                }
                else
                {
                    printf("\nNo se ha cargado ningun archivo!\n\n");
                }
                break;

            case 3:
                if(ll_isEmpty(listaPelis) == 0)
                {
                    listaMapeada = ll_map(listaPelis, peli_asignarRating);
                    if(listaMapeada != NULL)
                    {
                        printf("\nRatings asignados!\n\n");
                    }
                }
                else
                {
                    printf("\nNo se ha cargado ningun archivo!\n\n");
                }
                break;
            case 4:
                if(ll_isEmpty(listaPelis) == 0)
                {
                    listaGenero = ll_map(listaPelis, peli_asignarGeneros);
                    if(listaGenero != NULL)
                    {
                        printf("\nGeneros asignados!\n\n");
                    }
                }
                else
                {
                    printf("\nNo se ha cargado ningun archivo!\n\n");
                }
                break;

            case 5:
                if(ll_isEmpty(listaGenero) == 0)
                {
                    system("cls");
                    printf("Ingrese genero de peliculas que desea ver: \n\n 1. Accion\n 2. Comedia\n 3. Drama\n 4. Terror\n\n");
                    printf("Opcion: ");
                    scanf("%d", &opcion);
                    switch(opcion)
                    {
                        case 1:
                            listaGenero = ll_filter(listaPelis, peli_filtroAccion);
                            break;
                        case 2:
                            listaGenero = ll_filter(listaPelis, peli_filtroComedia);
                            break;
                        case 3:
                            listaGenero = ll_filter(listaPelis, peli_filtroDrama);
                            break;
                        case 4:
                            listaGenero = ll_filter(listaPelis, peli_filtroTerror);
                            break;
                    }
                    printf("\n           *** LISTA DE GENERO SELECCIONADO  ***\n\n");
                    controller_listarPelis(listaGenero);
                    if(controller_saveAsText("listaGenero.csv", listaGenero))
                    {
                        printf("\nSe guardo el archivo listaGenero.csv con exito!\n\n");
                    }
                }

                else
                {
                    printf("\nNo se han cargado ningun archivo o sus estadisticas!\n\n");
                }
                break;

            case 6:
                if(ll_isEmpty(listaGenero) == 0 && !ll_sort(listaPelis, peli_cmpRatings, 0))
                {
                    if(!ll_sort(listaPelis, peli_cmpGenero, 1)) //Ordena RATINGS y GENERO correctamente en Accion
                    {
                        system("cls");
                        printf("\n          *** LISTA DE PELIS ORDENADA GENERO / DURACION  ***\n");
                        printf("\n     *** (Funcionamiento correcto en ACCION. Luego x genero)  ***\n\n");
                        controller_listarPelis(listaPelis);
                        flagOrdenado = 1;
                    }
                }
                else
                {
                    printf("\nNo se han cargado ningun archivo o sus estadisticas!\n\n");
                }

                break;
            case 7:
                if(flagOrdenado && listaOrdenada == NULL)
                {
                    listaOrdenada = ll_clone(listaPelis);
                    controller_listarPelis(listaOrdenada);
                    printf("\nSe ha clonado la lista de Peliculas correctamente.\n\n");

                    if(controller_saveAsText("listaOrdenada.csv", listaOrdenada))
                    {
                        printf("Se guardo el archivo listaOrdenada.csv con exito!\n\n");
                    }

                }
                else
                {
                    printf("\nNo se ha podido clonar la lista de Peliculas: No se han ORDENADO anteriormente o hubo un error.\n\n");
                }

                break;

            case 8:
                printf("\nConfirma salida? (s/n): ");
                fflush(stdin);
                salir=getchar();
                if(salir != 'n' && salir != 's')
                {
                    printf("\nOpcion Invalida!\n\n");
                }
                break;

            default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }while(salir != 's');

    ll_deleteLinkedList(listaPelis);
    ll_deleteLinkedList(listaMapeada);
    ll_deleteLinkedList(listaGenero);
    ll_deleteLinkedList(listaOrdenada);
    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("              ***MOVIES***\n\n");
    printf("  1. Cargar Archivo.\n");
    printf("  2. Imprimir lista.\n");
    printf("  3. Asignar RATINGS:\n");
    printf("  4. Asignar GENEROS:\n");
    printf("  5. Filtrar por GENEROS:\n");
    printf("  6. Ordenar peliculas:\n");
    printf("  7. Guardar peliculas.\n");
    printf("  8. Salir.\n\n");
    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
