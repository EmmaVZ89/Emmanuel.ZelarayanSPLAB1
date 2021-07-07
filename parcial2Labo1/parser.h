#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos de los paises desde un archivo de texto
 *
 * \param pFile FILE* archivo de texto a leer
 * \param pListPaises LinkedList* lista de paises
 * \return int retorna 1 si se cargo al menos un pais al archivo, sino retorna 0 (tambien en caso de falla)
 *
 */
int parser_paisFromText(FILE* pFile, LinkedList* pListPaises);
