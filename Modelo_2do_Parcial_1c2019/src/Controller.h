/*
 * Controller.h
 *
 *  Created on: 18 nov. 2019
 *      Author: javijps
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"


int controller_loadFromText(char* path , LinkedList* pArrayListVenta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListVenta);
int controller_saveAsText(char* path , LinkedList* pArrayListVenta);
int controller_saveAsBinary(char* path , LinkedList* pArrayListVenta);
int controller_ListVenta(LinkedList* pArrayListVenta);
int controller_generarInformes(char* path , LinkedList* pArrayListVenta);
int controller_grabarInfo(FILE* pFile, LinkedList* pArrayListVenta);

#endif /* CONTROLLER_H_ */
