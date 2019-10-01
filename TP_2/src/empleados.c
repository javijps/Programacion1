/*
 * empleados.c
 *
 *  Created on: 30 sep. 2019
 *      Author: javijps
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"
#define STATUS_EMPTY  0
#define STATUS_NOT_EMPTY 1


/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/

static int idEmployee(void){
	static int id = 0;
	id++;
	return id;
}

/** \brief To indicate that all position in the array are empty,
*this function put the flag (isEmpty) in TRUE in all
*position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{

	int i;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;

}

int getDatosEmployee(Employee* list,int len){

	int retorno = -1;
	Employee bEmpleado;
	int i;

	for(i=0;i<len;i++)
	{
		getString(bEmpleado.name,"Ingrese el nombre del empleado",
				"Nombre Incorrecto",
				1,49,3);
		getString(bEmpleado.lastName,"Ingrese el apellido del empleado",
				"Nombre Incorrecto",
				1,49,3);
		getFloat(&bEmpleado.salary,"Ingrese salario del empleado",
				"Error, el precio ingresado es incorrecto",
				1,100000,3);
		getInt(&bEmpleado.sector,"Ingrese sector",
				"Error, el sector ingresado es incorrecto",
				1,10,3);

		list[i].salary = bEmpleado.salary;
		list[i].sector = bEmpleado.sector;

		strncpy(list[i].name,bEmpleado.name,50);
		strncpy(list[i].lastName,bEmpleado.lastName,50);
		list[i].id = idEmployee();//DEBERIA IR DENTRO DE ALTA, AL FINAL
		list[i].isEmpty = STATUS_NOT_EMPTY;

		retorno = 0;
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == STATUS_NOT_EMPTY)
			{
				retorno = i;
				break;
			}
			//else
			//printf("ID no encontrado!!!\n");
		}
	}
	return retorno;
}

int findEmptyEmployee(Employee* list,int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==STATUS_EMPTY)
				return i;
		}
	}
	return retorno;
}


/** \brief add in a existing list of employees the values received as parameters
in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list,
		        int len,
				int id,
				char name[],
				char lastName[],
				float salary,
				int sector)
{

	id = idEmployee();
	int retorno = -1;
	int index=0;

	if(list != NULL && len>0)
	{
		index = findEmptyEmployee(list,len);

		if(index!=-1)
		{
			if(getDatosEmployee(list,len)==0)
				retorno = 0;
		}
	}
	return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{
		retorno = 0;

		for(i=0;i<len;i++)
		{
			//if(list[i].isEmpty==STATUS_EMPTY)
			//	continue;
			printf("Id: %d - Name: %s - Last name: %s - Salary: %.2f - Sector: %d - Status: %d\n ",
				list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector,list[i].isEmpty);
			//printf("Status: %d\n ",list[i].isEmpty);
		}
	}
	return retorno;
}

