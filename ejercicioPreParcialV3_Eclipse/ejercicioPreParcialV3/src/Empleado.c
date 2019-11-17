#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
/*    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350
*/
void em_calcularSueldo(void* p)
{
	int precio_hs;

	if( (((Employee*)p)->horasTrabajadas) >0 && (((Employee*)p)->horasTrabajadas)<=120)
	{
		precio_hs = 180;
	}
	if((((Employee*)p)->horasTrabajadas) >120 && (((Employee*)p)->horasTrabajadas) <=160)
	{
		precio_hs = 240;
	}
	if((((Employee*)p)->horasTrabajadas)>160 && (((Employee*)p)->horasTrabajadas)<=240)
	{
		precio_hs = 350;
	}
	((Employee*)p)->sueldo = (((Employee*)p)->horasTrabajadas) * precio_hs;
}

/** \brief Validacion de nombre
 *
 * \param char* nombre. puntero a cadena de caracteres
 * \return int 1 si el nombre es valido, -1 si no lo es
 *
 */

static int isValidNombre(char* nombre)
{
	int retorno = -1;
	int i;
	int lenString;

	if(nombre!=NULL)
	{
		lenString = strlen(nombre);
		for(i=0;i<lenString;i++)
		{
			if((nombre[i] >= 'a' && nombre[i] <= 'z') ||
					(nombre[i] >= 'A' && nombre[i] <= 'Z') ||
					(nombre[i]== ' '))
			{

				retorno = 1;
				i++;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Validacion de Id
 *
 * \param char* id. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValidId(int id)//CARGAR UTN.H
{
	int retorno=-1;

	if(id>=0)
	{
		retorno=1;
	}
	return retorno;
}

/** \brief Validacion de horas trabajadas
 *
 * \param char* horas trabajadas. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValhorasTrabajadas(int horasTrabajadas)//CARGAR UTN.H
{
	int retorno=-1;

	if(horasTrabajadas>=1)
	{
		retorno=1;
	}
	return retorno;
}

/** \brief Validacion de sueldo
 *
 * \param char* sueldo. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValsueldo(int sueldo)//CARGAR UTN.H
{
	int retorno=-1;

	if(sueldo>=1)
	{
		retorno=1;
	}
	return retorno;
}

/** \brief Pide espacio en memoria
 *
 * \return puntero a espacio de memoria reservado para dato del tipo Employee
 *
 */
Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

/** \brief Libera espacio de memoria por medio de free
 *
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief Carga id en el campo id de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this!=NULL && isValidId(id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/** \brief Obtiene id del campo id de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/** \brief Carga nombre en el campo nombre de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}


/** \brief Obtiene  nombre del campo nombre  de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

/** \brief Carga horasTrabajadas en el campo horasTrabajadas de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL && isValhorasTrabajadas(horasTrabajadas)==1)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief Obtiene horas trabajadas del campo horas trabajadas de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/** \brief Carga sueldo en el campo sueldo de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this!=NULL && isValsueldo(sueldo))
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief Obtiene sueldo del campo sueldo de una estructura Employee
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}


/** \brief Carga todos los campos de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();

	int bId;
	int bHsTrabajadas;

	if(this!=NULL)
	{
		bId = atoi(idStr);
		bHsTrabajadas = atoi(horasTrabajadasStr);
			if(employee_setId(this,bId)==0 &&
					employee_setNombre(this,nombreStr)==0 &&
					employee_setHorasTrabajadas(this,bHsTrabajadas)==0)
			{
				retorno = this;
			}
			else
				employee_delete(this);
	}
	return retorno;
}

/** \brief Imprime un elemento de la estructura Employee
 *
 *
 *
 */
void emp_printAemployee(Employee* employee)
{
	if(employee!=NULL)
	{
		printf("\nID: %d\n"
				"Nombre: %s\n"
				"Horas trabajadas: %d\n"
				"Sueldo: %d\n",
				employee->id,
				employee->nombre,
				employee->horasTrabajadas,
				employee->sueldo);
	}
}

/** \brief Imprime array de elementos de la estructura Employee
 *
 *
 *
 */void emp_printEmployees(Employee* aEmployee,int len)
{
	int i;

	if(aEmployee!=NULL)
	{
		for(i=0;i<len;i++)
		{
			printf("ID: %d\n"
					"Nombre: %s\n"
					"Horas trabajadas: %d\n"
					"Sueldo: %d",
					aEmployee[i].id,
					aEmployee[i].nombre,
					aEmployee[i].horasTrabajadas,
					aEmployee[i].sueldo);
		}
	}
}
