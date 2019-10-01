/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "utn.h"
#include "empleados.h"//cambiar por employees
#define QTY_EMPLOYEES 1000
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1

int main(void) {

	Employee aEmployee[QTY_EMPLOYEES];
	Employee bEmployee[5];

	initEmployees(aEmployee,5);
	getDatosEmployee(bEmployee,1);
	printEmployees(bEmployee,5);
		//printf("si");


	return EXIT_SUCCESS;
}
