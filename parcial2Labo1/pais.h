#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[28];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
} ePais;

#endif // PAIS_H_INCLUDED

/** \brief imprime un menu de opciones y espera que el usuario ingrese un numero dentro del rango dado
 *
 * \return int retorna un numero dentro del rango dado (1-8)
 *
 */
int pais_menu();

/** \brief crea un puntero de una estructura ePais e inicializa sus campos
 *
 * \return ePais* retorna un puntero a ePais o NULL en caso de falla.
 *
 */
ePais* pais_new();

/** \brief crea un puntero de una estructura ePais e inicializa sus campos con los parametros pasados
 *
 * \param id int numero de id
 * \param nombre char* nombre del pais
 * \param vac1dosis int numero de dosis 1
 * \param vac2dosis int numero de dosis 2
 * \param sinVacunar int numero de Sin vacuar
 * \return ePais* retorna un puntero a ePais o NULL en caso de falla.
 *
 */
ePais* pais_newParametros(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar);

/** \brief libera la memoria de un puntero a una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_delete(ePais* this);


/** \brief carga el campo Id de una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \param id int numero de id
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_setId(ePais* this, int id);

/** \brief carga el campo nombre de una estructrura ePais
 *
 * \param this ePais* puntero a un pais
 * \param nombre char* nombre del pais
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_setNombre(ePais* this, char* nombre);

/** \brief carga el campo vac1dosis de una estructrura ePais
 *
 * \param this ePais* puntero a un pais
 * \param vac1dosis int numero de dosis 1
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_setVac1Dosis(ePais* this, int vac1dosis);

/** \brief carga el campo vac2dosis de una estructrura ePais
 *
 * \param this ePais* puntero a un pais
 * \param vac1dosis int numero de dosis 2
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_setVac2Dosis(ePais* this, int vac2dosis);

/** \brief carga el campo sinVacunar de una estructrura ePais
 *
 * \param this ePais* puntero a un pais
 * \param sinVacunar int numero de sin vacunar
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_setSinVacunar(ePais* this, int sinVacunar);

/** \brief toma el valor del campo id de una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \param id int* puntero donde se guarda el numero de id
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_getId(ePais* this, int* id);

/** \brief toma el valor del campo nombre de una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \param char* nombre puntero donde se guarda el nombre
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_getNombre(ePais* this, char* nombre);

/** \brief toma el valor del campo vac1dosis de una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \param vac1dosis int* puntero donde se guarda el numero de dosis 1
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_getVac1Dosis(ePais* this, int* vac1dosis);

/** \brief toma el valor del campo vac2dosis de una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \param vac2dosis int* puntero donde se guarda el numero de dosis 2
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_getVac2Dosis(ePais* this, int* vac2dosis);

/** \brief toma el valor del campo sinVacunar de una estructura ePais
 *
 * \param this ePais* puntero a un pais
 * \param sinVacunar int* puntero donde se guarda el numero de sin vacunar
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_getSinVacunar(ePais* this, int* sinVacunar);


/** \brief asigna valores aleatorios (segun rango) en los campos de una estructura ePais
 *
 * \param pPais void* puntero a un pais
 * \return void*
 *
 */
void* pais_asignarEstadisticas(void* pPais);

/** \brief filtra los paises tienen mas del 30% de vacunados con 2 dosis
 *
 * \param pElement void* puntero a un elemento
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_filterExitosos(void* pElement);

/** \brief filtra los paises que tienen mas cantidad se gente sin vacunar que vacunados.
 *
 * \param pElement void* puntero a un elemento
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int pais_filterPaisesAlHorno(void* pElement);

/** \brief compara entre paises la cantidad de dosis 1.
 *
 * \param pais1 void* puntero al elemento 1
 * \param pais2 void* puntero al elemento 2
 * \return int retorna 0 si son iguales, retorna 1 si las del elemento son mayores, retorna -1 si son menores.
 *
 */
int pais_cmpVac1Dosis(void* pais1, void* pais2);
