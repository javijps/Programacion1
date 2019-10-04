/*
 ============================================================================
 Name        : TP_2_.c
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
#include "empleados.h"
#define MAX_EMPLOYEE 1000
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1
#define EXIT_MENU 5

//PUNTO 1 TP OK. MODIFICAR LAS FUNCIONES DE INPUT.(NOTAS EN EMPLEADO.C)
//hacer funcion ordenar ASC Y funcion ordenar DESC para llamar dentro de sortEmployees()

int main(void) {

	int option;
	Employee aEmployee[MAX_EMPLOYEE];
	Employee bEmployee[5];
	//empleadoForzado(bEmployee,5);
	int id;
	int fAlta=-1;

	if(initEmployees(aEmployee,MAX_EMPLOYEE)==0)
	{printEmployees(bEmployee,5);
	do
	{

		getInt(&option,"\n-------------------\n"
				"Ingrese :\n"
				"1-Altas\n"
				"2-Modificar\n"
				"3-Baja\n"
				"4-INFORMAR\n"
				"     *1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
				"     *2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
				"5-SALIR\n"
				"\n-------------------\n",
				"Error,opcion incorrecta\n",
				1,5,2);

		switch(option)
		{
		case 1:
			if(addEmployee(bEmployee,1)==0)
			{
				fAlta=0;
			}
			else
			{
				printf("EL empleado no pudo ser dado de alta\n");
			}
			break;
		case 2:
			if(fAlta==0)
			{
				getInt(&id,"Ingrese ID del empleado a modificar\n","Error\n",1,1000,2);//reemplazar x getId
				if(modifyEmployeeById(bEmployee,MAX_EMPLOYEE,id)!=0)
				{
					printf("No fue posible realizar la modificacion\n");
				}
			}
			else
				printf("Es necesario dar empleados de alta!\n");
			break;

		case 3:
			if(fAlta==0)
			{
				getInt(&id,"Ingrese ID del empleado a dar de baja\n","Error\n",1,1000,2);//reemplazar x getId
				if(removeEmployee(bEmployee,MAX_EMPLOYEE,id)!=0)
				{
					printf("No fue posible realizar la modificacion\n");
				}
			}
			else
				printf("Es necesario dar empleados de alta!\n");
			break;
		case 4:
			if(fAlta==0)
			{
				if(getInt(&option,"Ingrese:\n 1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
						"2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio.",
						"Error\n",
						1,
						2,
						2)==0)//reemplazar x getOptionMenu
				{
					switch(option)//dar a elegir si quiere ASC O DESC?
					{
					case 1:
						if(sortEmployees(bEmployee,5,0)!=0)//sortOrder = 1 ASC, sortOrder = 2
						{
							printf("No fue posible realizar el ordenamiento!");
						}
						break;
					case 2:
						//total salarios, promedios, y cuantos arriba del promedio
						if(calcularPunto4(bEmployee,1000)!=0)
						{
							printf("No fue posible procesar la informacion!");
						}
						break;
					}
				}
			}
			else
				printf("Es necesario dar empleados de alta!\n");
		}
	}while(option!=EXIT_MENU);
	}

	return EXIT_SUCCESS;
}
