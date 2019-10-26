/*
 ============================================================================
 Name        : Biblioteca_UTN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {

	char cadena[50];
	float bufferFloat;

	if(getstringToFloat(&bufferFloat,cadena,"Ingrese numero f","No corresponde a un numero f!\n",50,3)==0)
		printf("%.2f",bufferFloat);

	return EXIT_SUCCESS;
}
