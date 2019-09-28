/*
 ============================================================================
 Name        : Funciones_C4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
/*
int main(void)
{

	int pResultado;
	if(getInt(&pResultado, "Ingrese edad \n", "Error\n", 0,150,2)==-1)//??
	{
		printf("El resultado es : %d",pResultado);
	}

	return -1;
}*/


int main(void)
{

	float pResultado;
	if(getFloat(&pResultado, "Ingrese edad \n", "Error\n", 0,150,2)==-1)//chequea que la funcion ande bien
	{
		printf("El resultado es : %f",pResultado);
	}

	return -1;
}
