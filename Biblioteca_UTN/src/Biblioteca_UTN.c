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

	char letra;

	if(getLetra(&letra,"Ingrese letra\n","No es una letra\n",3)==0)
		printf("%c",letra);

	return EXIT_SUCCESS;
}
