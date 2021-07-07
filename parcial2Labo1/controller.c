#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"


int controller_loadFromText(char* path, LinkedList* pListPaises)
{
    int retorno = 0;
    char confirma = 'n';
    FILE* f = NULL;

    if(path != NULL && pListPaises != NULL)
    {
        f = fopen(path,"r");
        if(f == NULL)
        {
            printf("\n   No se pudo abrir el archivo o el archivo no existe\n\n");
        }
        else
        {
            if(ll_len(pListPaises) > 0)
            {
                printf("\nSe van a sobrescribir los articulos. Desea confirmar?\ns: Si\nn: No\nRespuesta: ");
                fflush(stdin);
                scanf("%c", &confirma);
            }

            if(ll_len(pListPaises) == 0 || confirma == 's')
            {
                if(parser_paisFromText(f, pListPaises))
                {
                    retorno = 1;
                }
            }
        }
        fclose(f);
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pListPaises)
{
    int retorno = 0;
    char confirma = 's';
    FILE* f = NULL;
    ePais* auxPais = NULL;

    if(path != NULL && pListPaises != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            printf("\nCuidado el archivo exite y se va a sobrescribir. Desea confirmar?\ns: Si\nn: No\nRespuesta: ");
            fflush(stdin);
            scanf("%c", &confirma);
        }
        fclose(f);

        if(confirma == 's')
        {
            f = fopen(path,"w");
            if(f == NULL)
            {
                printf("\n   No se pudo abrir el archivo\n\n");
            }
            else
            {
                fprintf(f,"id,nombre,vac1dosis,vac2dosis,sinVacunar\n");
                for(int i = 0; i < ll_len(pListPaises); i++)
                {
                    auxPais = (ePais*) ll_get(pListPaises,i);
                    if(auxPais != NULL)
                    {
                        fprintf(f,"%d,%s,%d,%d,%d\n",
                                auxPais->id,
                                auxPais->nombre,
                                auxPais->vac1dosis,
                                auxPais->vac2dosis,
                                auxPais->sinVacunar);
                    }
                    auxPais = NULL;
                }
                retorno = 1;
            }
            fclose(f);
        }
    }
    return retorno;
}

int controller_listPais(ePais* pPais)
{
    int retorno = 0;
    int id;
    char nombre[28];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
    if(pPais != NULL &&
            pais_getId(pPais,&id) &&
            pais_getNombre(pPais,nombre) &&
            pais_getVac1Dosis(pPais,&vac1Dosis) &&
            pais_getVac2Dosis(pPais,&vac2Dosis) &&
            pais_getSinVacunar(pPais,&sinVacunar))
    {
        printf(" %3d     %-20s %4d           %4d         %4d\n",
               id,
               nombre,
               vac1Dosis,
               vac2Dosis,
               sinVacunar);
        retorno = 1;
    }
    return retorno;
}

int controller_listPaises(LinkedList* pListPaises)
{
    int retorno = 0;
    int len;
    ePais* auxPais = NULL;
    if(pListPaises != NULL)
    {
        len = ll_len(pListPaises);
        printf("-------------------------------------------------------------------\n");
        printf("  Id     Nombre               1 Dosis        2 Dosis    Sin Vacunar\n");
        printf("-------------------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            auxPais = (ePais*) ll_get(pListPaises,i);
            if(auxPais != NULL)
            {
                controller_listPais(auxPais);
            }
        }
        printf("-------------------------------------------------------------------\n");
        retorno = 1;
    }
    return retorno;
}

