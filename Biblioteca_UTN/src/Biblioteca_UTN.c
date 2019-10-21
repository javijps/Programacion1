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

	int ffloat;

	if(getInt(&ffloat,"ingrese","error",0,1000,3)==0)
		printf("int %d",ffloat);
	else
		printf("no anduvo");

	return EXIT_SUCCESS;
}
