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

//ORDENAR FUNCIONES. HACER LOS GET DE EMPLEADOS. HACER GET NOMBRE, GET APELLIDO, GET SALARY?,GET SECTOR getId
//hacer funcion ordenar ASC Y funcion ordenar DESC
//renombrar los archivos de la biblioteca.


/** \brief To indicate that all position in the array are empty,
*this function put the flag (isEmpty) in TRUE in all
*position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee *list, int len)
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

/**
* \brief Genera el ID correspondiente a una pantalla.
* \return Devuelve el ID correspondiente.
*/

static int idEmployee(void){
	static int id = 0;
	id++;
	return id;
}

int getDatosEmployee(Employee* list,int len){

	int retorno = -1;
	Employee bEmpleado;
	int i;

	for(i=0;i<len;i++)
	{

		if(getString(bEmpleado.name,"Ingrese el nombre del empleado\n",
				"Nombre Incorrecto\n",
				1,49,3)!=0)
			break;
		getString(bEmpleado.lastName,"Ingrese el apellido del empleado\n",
				"Nombre Incorrecto\n",
				1,49,3);
		if(getFloat(&bEmpleado.salary,"Ingrese salario del empleado\n",
				"Error, el salario ingresado es incorrecto\n",
				1,100000,2)!=0)
			break;
		if(getInt(&bEmpleado.sector,"Ingrese sector\n",
				"Error, el sector ingresado es incorrecto\n",
				1,10,3)!=0)
			break;

		list[i].salary = bEmpleado.salary;
		list[i].sector = bEmpleado.sector;
		strncpy(list[i].name,bEmpleado.name,50);
		strncpy(list[i].lastName,bEmpleado.lastName,50);
		list[i].isEmpty = STATUS_NOT_EMPTY;
		list[i].id = idEmployee();
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

int addEmployee(Employee* list,int len)
{

	int retorno = -1;
	int index=0;

	if(list != NULL && len>0)
	{
		index = findEmptyEmployee(list,len);

		if(index!=-1)
		{
			if(getDatosEmployee(list,len)==0)
			{
				retorno = 0;
			}
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

	int retorno = -1;
	int index=0;

	if(list != NULL && len>0)
	{
		index = findEmployeeById(list,len,id);

		if(index!=-1)
		{
			list[index].isEmpty = STATUS_EMPTY;
			retorno = 0;
			printf("Baja Exitosa!\n");
		}
	}
	return retorno;

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
	int i;
	Employee bEmployee;
	int fSwap;
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		retorno = 0;
		do
		{
			fSwap=0;
			for(i=0;i<len-1;i++)
			{
				if(order==1)
				{
					if(strncmp(list[i].lastName,list[i+1].lastName,50)>0)//MAX CHAR?
					{
						if(list[i].isEmpty==STATUS_EMPTY)
							continue;
						fSwap = 1;
						bEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = bEmployee;

					}
					else if(strncmp(list[i].lastName,list[i+1].lastName,50)==0)//MAX CHAR?
					{
						if(list[i].sector>list[i+1].sector)//MAX CHAR?
						{
							if(list[i].isEmpty==STATUS_EMPTY)
								continue;
							fSwap = 1;
							bEmployee = list[i];
							list[i] = list[i+1];
							list[i+1] = bEmployee;

						}
					}
				}
				else if(order==0 && list[i].isEmpty == STATUS_NOT_EMPTY)
				{
					if(strncmp(list[i].lastName,list[i+1].lastName,50)<0)//MAX CHAR?
					{
						fSwap = 1;
						bEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = bEmployee;

					}
					else if(strncmp(list[i].lastName,list[i+1].lastName,50)==0)//MAX CHAR?
					{
						if(list[i].sector<list[i+1].sector)//MAX CHAR?
						{
							fSwap = 1;
							bEmployee = list[i];
							list[i] = list[i+1];
							list[i+1] = bEmployee;

						}
					}
				}


			}
		}while(fSwap);
	}
	return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*IMPRIME SOLO EMPLEADOS ACTIVOS
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
			if(list[i].isEmpty==STATUS_EMPTY)
				continue;
			printf("\n Id: %d - Name: %s - Last name: %s - Salary: %.2f - Sector: %d - Status: %d \n ",
				list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector,list[i].isEmpty);
			//printf("Status: %d\n ",list[i].isEmpty);
		}
	}
	return retorno;
}


int modifyEmployeeById(Employee* list,int len,int id)
{
	int retorno = -1;
	char option;
	Employee bEmployee;

	int index = findEmployeeById(list,len,id);

	if(index!=-1)
	{
		do
		{

			getChar(&option,"a-Modificar nombre\n"
					"b-Modificar apellido\n"
					"c-Modificar salario\n"
					"d-MOdificar sector\n"
					"e-SALIR\n",
					"Error,opcion incorrecta\n",
					'a','e',2);

			switch(option)
			{
			case 'a':
				if(getString(bEmployee.name,"Ingrese el nombre del empleado\n",
						"Nombre Incorrecto\n",
						1,49,3)!=0)
				{
					printf("No se pudo modificar el nombre");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].name,bEmployee.name,50);
					retorno = 0;
				}
				break;
			case 'b':
				if(getString(bEmployee.lastName,"Ingrese el apellido del empleado\n",
						"Apellido Incorrecto\n",
						1,49,3)!=0)
				{
					printf("No se pudo modificar el apellido");
					retorno = -1;
				}
				else
				{
					strncpy(list[index].lastName,bEmployee.lastName,50);
					retorno = 0;
				}
				break;
			case 'c':
				if(getFloat(&bEmployee.salary,"Ingrese el salario del empleado\n",
						"Salario Incorrecto\n",
						1,100000,2)!=0)
				{
					printf("No se pudo modificar el salario");
					retorno = -1;
				}
				else
				{
					list[index].salary = bEmployee.salary;
					retorno = 0;
				}
				break;
			case 'd':
				if(getInt(&bEmployee.sector,"Ingrese el sector del empleado\n",
						"Sector Incorrecto\n",
						1,3,2)!=0)
				{
					printf("No se pudo modificar el sector");
					retorno = -1;
				}
				else
				{
					list[index].sector = bEmployee.sector;
					retorno = 0;
				}
				break;
			}
		}while(option!='e');

		//list[index].isEmpty = STATUS_NOT_EMPTY;

	}
	return retorno;

}

int calcularPunto4(Employee* list,int len)
{
	int retorno = -1;
	int i;
	float acumuladorSalarios;//activos
	int contadorEmpleados=0;//activos
	int contadorAboveAverage=0;
	float averageSalaries;//plural de salary?

	if(list!=NULL && len > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==STATUS_NOT_EMPTY)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salary;
				contadorEmpleados++;//countActiveEmployees
			}
		}
		averageSalaries = acumuladorSalarios / contadorEmpleados;
		for(i=0;i<len;i++)
		{
			if(list[i].salary>averageSalaries)
			{
				contadorAboveAverage++;
			}
		}
		printf("\n---------------------------\n"
				"\nEl total de los salarios es: %.2f\n"
				"El promedio de los salarios es %.2f\n"
				"La cantidad de salarios que se encuentran por encima del promedio es: %d"
				"\n---------------------------\n"
				,acumuladorSalarios,
				averageSalaries,
				contadorAboveAverage);
	}
	return retorno;
}


















void empleadoForzado(Employee *list,int cantidad){

	int aId[] = {1,2,3,4,5};
	int aStatus[] = {1,1,1,1,1};
	char aName[][50] = {"Melina","Camila","Gabriela","Rosa","Cristian"};
	char aLastName [][50] = {"Scian","Castro","Diaz","Simonetti", "Diaz"};
	float aSalary[] = {500,1000,1500,2000,2500};
	int aSector[] = {1,1,2,2,3};
	int i;

	for(i=0;i<cantidad;i++)
	{
		strncpy(list[i].name,aName[i],50);
		strncpy(list[i].lastName,aLastName[i],50);
		list[i].id = aId[i];
		list[i].isEmpty = aStatus[i];
		list[i].sector = aSector[i];
		list[i].salary = aSalary[i];
	}
}






