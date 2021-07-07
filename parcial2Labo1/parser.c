#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "pais.h"


int parser_paisFromText(FILE* pFile, LinkedList* pListPaises)
{
    int retorno = 0;
    int cant = 0;
    char buffer[5][128];
    ePais* auxPais = NULL;

    if(pFile != NULL && pListPaises != NULL)
    {
        ll_clear(pListPaises);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(cant == 5)
            {
                auxPais = pais_newParametros(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]),atoi(buffer[4]));
                if(auxPais != NULL)
                {
                    if( !ll_add(pListPaises, auxPais))
                    {
                        retorno = 1;
                    }
                }
            }
        }
    }
    return retorno;
}
