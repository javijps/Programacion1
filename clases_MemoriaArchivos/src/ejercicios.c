/*
 * ejerciciosPunteros.c
 *
 *  Created on: 27 oct. 2019
 *      Author: javijps
 */

#include <stdio.h>
#include <stdlib.h>
#include "ejercicios.h"
#include <string.h>



//MEMORIA

/*
1) Construir una función llamada "getDynamicString" que permita al usuario ingresar un texto y devuelva un puntero
   a un espacio de memoria donde esta almacenado el texto ingresado. Se requiere el uso de memoria dinámica.
*/

//imprime mensaje, asigna memoria para 1024 caracteres, toma el texto, mide su largo con strlen y despues hace
//un realloc con el texto, para ajustar el espacion de memoria a ocupar a lo que da el strlen
char* getDynamicString(char* messagge)
{
	printf(messagge);

	char *pData = (char*)malloc(sizeof(char)*1024);
	scanf("%1023s",pData);
	int len = strlen(pData);
	pData = (char*)realloc(pData,sizeof(char)*(len+1));

	return pData;
}




