#include "pais.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief abre un archivo para pasarselo a un parser
 *
 * \param path char* archivo de texto a abrir
 * \param pListPaises LinkedList* lista de paises
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int controller_loadFromText(char* path, LinkedList* pListPaises);


/** \brief crea un archivo de texto
 *
 * \param path char* archivo de texto
 * \param pListPaises LinkedList* lista de paises
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int controller_saveAsText(char* path, LinkedList* pListPaises);

/** \brief imprime los datos de un pais
 *
 * \param pPais ePais* puntero a un pais
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int controller_listPais(ePais* pPais);

/** \brief muestra la lista completa de una lista de paises
 *
 * \param pListPaises LinkedList* puntero a una LinkedList
 * \return int retorna 1 en caso de exito, retorna 0 en caso de falla
 *
 */
int controller_listPaises(LinkedList* pListPaises);

