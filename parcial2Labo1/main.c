#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "LinkedList.h"
#include "controller.h"
#include "informes.h"


int main()
{
    srand(time(NULL));
    int opcion;
    int flagEst = 0;
    char path[50];
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesExitosos = NULL;
    LinkedList* listaPaisesAlHorno = NULL;
    LinkedList* listaEstadisticas = NULL;
    if(listaPaises != NULL)
    {
        do
        {
            opcion = pais_menu();
            switch(opcion)
            {
            case 1:
                system("cls");
                printf("Nombre del archivo principal: vacunas.csv\n\n");
                utn_getDescripcion(path,sizeof(path),"Ingrese Nombre del archivo de texto (nombre.csv): ",
                              "Ingreso invalido!\n\n",3);
                if(controller_loadFromText(path,listaPaises))
                {
                    printf("\n   Archivo cargado con exito!\n\n");
                }
                system("pause");
                break;
            case 2:
                if(ll_isEmpty(listaPaises) && flagEst == 0)
                {
                    printf("\n   No hay paises cargados y/o no se cargaron estadisticas!\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n      *** LISTA DE PAISES ***\n\n");
                    controller_listPaises(listaPaises);
                }
                system("pause");
                break;
            case 3:
                if(ll_isEmpty(listaPaises))
                {
                    printf("\n   No hay paises cargados!\n\n");
                }
                else
                {
                    listaEstadisticas = ll_map(listaPaises,pais_asignarEstadisticas);
                    if(listaEstadisticas != NULL)
                    {
                        printf("\n   Estadisticas asignadas con exito!\n\n");
                        flagEst = 1;
                    }
                }
                system("pause");
                break;
            case 4:
                if((ll_isEmpty(listaPaises) == 1 || ll_isEmpty(listaPaises) == 0) && flagEst == 0)
                {
                    printf("\n   No hay paises cargados y/o no se cargaron estadisticas!\n\n");
                }
                else
                {
                    listaPaisesExitosos = ll_filter(listaPaises,pais_filterExitosos);
                    if(listaPaisesExitosos != NULL)
                    {
                        system("cls");
                        printf("\n      *** LISTA DE PAISES EXITOSOS  ***\n\n");
                        controller_listPaises(listaPaisesExitosos);
                        if(controller_saveAsText("listaPaisesExitosos.csv",listaPaisesExitosos))
                        {
                            printf("\n   Se guardo el archivo listaPaisesExitosos.csv con exito!\n\n");
                        }
                    }
                }
                system("pause");
                break;
            case 5:
                if((ll_isEmpty(listaPaises) == 1 || ll_isEmpty(listaPaises) == 0) && flagEst == 0)
                {
                    printf("\n   No hay paises cargados y/o no se cargaron estadisticas!\n\n");
                }
                else
                {
                    system("cls");
                    listaPaisesAlHorno = ll_filter(listaPaises,pais_filterPaisesAlHorno);
                    if(listaPaisesAlHorno != NULL)
                    {
                        printf("\n      *** LISTA DE PAISES AL HORNO  ***\n\n");
                        controller_listPaises(listaPaisesAlHorno);
                        if(controller_saveAsText("listaPaisesAlHorno.csv",listaPaisesAlHorno))
                        {
                            printf("\n   Se guardo el archivo listaPaisesAlHorno.csv con exito!\n\n");
                        }
                    }
                }
                system("pause");
                break;
            case 6:
                if((ll_isEmpty(listaPaises) == 1 || ll_isEmpty(listaPaises) == 0) && flagEst == 0)
                {
                    printf("\n   No hay paises cargados y/o no se cargaron estadisticas!\n\n");
                }
                else
                {
                    if( !ll_sort(listaPaises,pais_cmpVac1Dosis,1))
                    {
                        system("cls");
                        printf("\n      *** LISTA DE PAISES ORDENADA  ***\n\n");
                        controller_listPaises(listaPaises);
                    }

                }
                system("pause");
                break;
            case 7:
                if((ll_isEmpty(listaPaises) == 1 || ll_isEmpty(listaPaises) == 0) && flagEst == 0)
                {
                    printf("\n   No hay paises cargados y/o no se cargaron estadisticas!\n\n");
                }
                else
                {
                    pais_mayorSinVacunar(listaPaises);
                }
                system("pause");
                break;
            }
        }
        while(opcion != 8);
    }
    ll_deleteLinkedList(listaPaises);
    ll_deleteLinkedList(listaPaisesExitosos);
    ll_deleteLinkedList(listaPaisesAlHorno);
    ll_deleteLinkedList(listaEstadisticas);
    return 0;
}

