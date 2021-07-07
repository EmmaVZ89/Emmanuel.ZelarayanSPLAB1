#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "utn.h"
#include <time.h>
#include "LinkedList.h"

int pais_menu()
{
    int opcion;
    system("cls");
    printf("***   Pandemia   ***\n\n");
    printf("Menu de opciones: \n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar paises exitosos\n");
    printf("5. Filtrar paises en el horno\n");
    printf("6. Ordenar por nivel de vacunacion\n");
    printf("7. Mostrar mas castigado/s\n");
    printf("8. SALIR\n");
    utn_getNumero(&opcion,"Ingrese su opcion: ","Ingreso invalido!\n\n",1,8,3);
    return opcion;
}

ePais* pais_new()
{
    ePais* newPais = (ePais*) malloc(sizeof(ePais));
    if(newPais != NULL)
    {
        newPais->id = 0;
        strcpy(newPais->nombre, " ");
        newPais->vac1dosis = 0;
        newPais->vac2dosis = 0;
        newPais->sinVacunar = 0;
    }
    return newPais;
}

ePais* pais_newParametros(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar)
{
    ePais* newPais = pais_new();
    if(newPais != NULL)
    {
        if( !(pais_setId(newPais,id) &&
                pais_setNombre(newPais,nombre) &&
                pais_setVac1Dosis(newPais,vac1dosis) &&
                pais_setVac2Dosis(newPais,vac2dosis) &&
                pais_setSinVacunar(newPais,sinVacunar)))
        {
            pais_delete(newPais);
            newPais = NULL;
        }
    }
    return newPais;
}

int pais_delete(ePais* this)
{
    int retorno = 0;
    if(this != NULL)
    {
        free(this);
        retorno = 1;
    }
    return retorno;
}

int pais_setId(ePais* this, int id)
{
    int retorno;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int pais_setNombre(ePais* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int pais_setVac1Dosis(ePais* this, int vac1Dosis)
{
    int retorno = 0;
    if(this != NULL && vac1Dosis >= 0)
    {
        this->vac1dosis = vac1Dosis;
        retorno = 1;
    }
    return retorno;
}

int pais_setVac2Dosis(ePais* this, int vac2Dosis)
{
    int retorno = 0;
    if(this != NULL && vac2Dosis >= 0)
    {
        this->vac2dosis = vac2Dosis;
        retorno = 1;
    }
    return retorno;
}

int pais_setSinVacunar(ePais* this, int sinVacunar)
{
    int retorno = 0;
    if(this != NULL && sinVacunar >= 0)
    {
        this->sinVacunar = sinVacunar;
        retorno = 1;
    }
    return retorno;
}

int pais_getId(ePais* this, int* id)
{
    int retorno;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int pais_getNombre(ePais* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

int pais_getVac1Dosis(ePais* this, int* vac1Dosis)
{
    int retorno = 0;
    if(this != NULL && vac1Dosis != NULL)
    {
        *vac1Dosis = this->vac1dosis;
        retorno = 1;
    }
    return retorno;
}

int pais_getVac2Dosis(ePais* this, int* vac2Dosis)
{
    int retorno = 0;
    if(this != NULL && vac2Dosis != NULL)
    {
        *vac2Dosis = this->vac2dosis;
        retorno = 1;
    }
    return retorno;
}

int pais_getSinVacunar(ePais* this, int* sinVacunar)
{
    int retorno = 0;
    if(this != NULL && sinVacunar != NULL)
    {
        *sinVacunar = this->sinVacunar;
        retorno = 1;
    }
    return retorno;
}

void* pais_asignarEstadisticas(void* pPais)
{
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
    int minVac1;
    int maxVac1;
    int minVac2;
    int maxVac2;
    ePais* pAuxPais = NULL;
    if(pPais != NULL)
    {
        minVac1 = 1;
        maxVac1 = 60;
        minVac2 = 1;
        maxVac2 = 40;

        vac1Dosis = rand() % (maxVac1 - minVac1 + 1) + minVac1;
        vac2Dosis = rand() % (maxVac2 - minVac2 + 1) + minVac2;
        sinVacunar = 100 - vac1Dosis - vac2Dosis;

        pAuxPais = (ePais*) pPais;

        pais_setVac1Dosis(pAuxPais,vac1Dosis);
        pais_setVac2Dosis(pAuxPais,vac2Dosis);
        pais_setSinVacunar(pAuxPais,sinVacunar);
    }
    return pAuxPais;
}

int pais_filterExitosos(void* pElement)
{
    int returnAux = 0;
    ePais* pais = NULL;
    if(pElement != NULL)
    {
        pais = (ePais*) pElement;
        if(pais->vac2dosis > 30)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int pais_filterPaisesAlHorno(void* pElement)
{
    int returnAux = 0;
    ePais* pais = NULL;
    if(pElement != NULL)
    {
        pais = (ePais*) pElement;
        if(pais->sinVacunar > pais->vac1dosis + pais->vac2dosis)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int pais_cmpVac1Dosis(void* pais1, void* pais2)
{
    int retorno = 0;
    ePais* auxPais1 = NULL;
    ePais* auxPais2 = NULL;
    if(pais1 != NULL && pais2 != NULL)
    {
        auxPais1 = (ePais*) pais1;
        auxPais2 = (ePais*) pais2;
        if(auxPais1->vac1dosis > auxPais2->vac1dosis)
        {
            retorno = 1;
        }
        else
        {
            if(auxPais1->vac1dosis < auxPais2->vac1dosis)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

