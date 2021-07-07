#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "pais.h"

int pais_mayorSinVacunar(LinkedList* pListPaises)
{
    int retorno = 0;
    int len;
    int mayor;
    ePais* auxPais = NULL;
    if(pListPaises != NULL)
    {
        len = ll_len(pListPaises);
        for(int i = 0; i < len; i++)
        {
            auxPais = (ePais*) ll_get(pListPaises,i);
            if(auxPais != NULL)
            {
                if( i == 0 || mayor < auxPais->sinVacunar)
                {
                    mayor = auxPais->sinVacunar;
                }
            }
        }
        printf("\nCantidad de NO vacunados: %d      Pais/es: ", mayor);
        for(int i = 0; i < len; i++)
        {
            auxPais = (ePais*) ll_get(pListPaises,i);
            if(auxPais != NULL)
            {
                if(mayor == auxPais->sinVacunar)
                {
                    printf("%s ", auxPais->nombre);
                }
            }
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}
