/*
 * Parser.h
 *
 *  Created on: 18 nov. 2019
 *      Author: javijps
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"

int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta);
int parser_VentaFromBinary(FILE* pFile , LinkedList* pArrayListVenta);


#endif /* PARSER_H_ */
