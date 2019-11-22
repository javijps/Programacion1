#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

/** \brief Validacion de nombre //DE SER NECESARIO PUEDE MODIFICARSE PARA SER ALFANUMERICA
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


/** \brief Validacion de dias//VALIDA ENTEROS MODIFICAR NOMBRE Y VALIDACION DE SER NECESARIO
 *
 * \param char* horas trabajadas. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValidDias(int dias)//CARGAR UTN.H
{
	int retorno=-1;

	if(dias>0)
	{
		retorno=1;
	}
	return retorno;
}



/** \brief Validacion de reservado//VALIDA ENTEROS MODIFICAR NOMBRE Y VALIDACION DE SER NECESARIO
 *
 * \param char* horas trabajadas. puntero a cadena de caracteres
 * \return int 1 si el id es valido, -1 si no lo es
 *
 */
static int isValidReservado(char* reservado)//CARGAR UTN.H
{
	int retorno=-1;

 	char reservaSi[10] = {"SI"};
 	char reservaNo[10] = {"NO"};

 	if((strncmp(reservaSi,reservado,10)==0) || (strncmp(reservaNo,reservado,10)==0))
 	{
 		return 1;
 	}	return retorno;
}

/** \brief Validacion de genero //DE SER NECESARIO PUEDE MODIFICARSE PARA SER ALFANUMERICA
 *
 * \param char* genero. puntero a cadena de caracteres
 * \return int 1 si el genero es valido, -1 si no lo es
 *
 */

static int isValidGenero(char* genero)
{
	int retorno = -1;
	int i;
	int lenString;

	if(genero!=NULL)
	{
		lenString = strlen(genero);
		for(i=0;i<lenString;i++)
		{
			if((genero[i] != 'M' || genero[i] != 'H' ||
					genero[i] != 'm' || genero[i] != 'h'))
			{
				retorno = -1;
				break;
			}

			else
			{
				retorno = 1;
				i++;
			}
		}
	}
	return retorno;
}










/** \brief Pide espacio en memoria
 *
 * \return puntero a espacio de memoria reservado para dato del tipo sCachorro
 *
 */
sCachorro* sCachorro_new()
{
	return malloc(sizeof(sCachorro));
}

/** \brief Libera espacio de memoria por medio de free
 *
 *
 */
void sCachorro_delete(sCachorro* this)
{
	free(this);
}

/** \brief Carga id en el campo id de una estructura sCachorro
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int sCachorro_setId(sCachorro* this,int id)
{
	int retorno = -1;

	if(this!=NULL && isValidId(id))
	{
		this->ID_Cachorro = id;
		retorno = 0;
	}
	return retorno;
}
//SET DE INT
/** \brief Obtiene id del campo id de una estructura sCachorro
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int sCachorro_getId(sCachorro* this,int* id)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*id = this->ID_Cachorro;
		retorno = 0;
	}
	return retorno;
}
//SET DE CHAR
/** \brief Carga nombre en el campo nombre de una estructura sCachorro
  *
 * \return 0 si logra la carga -1 si falla
 *
 */
int sCachorro_setNombre(sCachorro* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

//GET DE CHAR
/** \brief Obtiene  nombre del campo nombre  de una estructura sCachorro
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int sCachorro_getNombre(sCachorro* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

/** \brief Carga dias en el campo dias de una estructura sCachorro
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int sCachorro_setDias(sCachorro* this,int dias)
{
	int retorno = -1;

	if(this!=NULL && isValidDias(dias)==1)
	{
		this->dias = dias;
		retorno = 0;
	}
	return retorno;
}
//GET DE INT
/** \brief Obtiene horas trabajadas del campo horas trabajadas de una estructura sCachorro
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int sCachorro_getdias(sCachorro* this,int* dias)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*dias = this->dias;
		retorno = 0;
	}
	return retorno;
}



/** \brief Carga raza en el campo raza de una estructura sCachorro
  *
 * \return 0 si logra la carga -1 si falla
 *
 */
int sCachorro_setRaza(sCachorro* this,char* raza)
{
	int retorno = -1;

	if(this!=NULL && isValidNombre(raza))
	{
		strcpy(this->raza,raza);
		retorno = 0;
	}
	return retorno;
}

//GET DE CHAR
/** \brief Obtiene  raza del campo raza  de una estructura sCachorro
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int sCachorro_getRaza(sCachorro* this,char* raza)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(raza,this->raza);
		retorno = 0;
	}
	return retorno;
}



/** \brief Carga Reservado en el campo Reservado de una estructura sCachorro
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
int sCachorro_setReservado(sCachorro* this,char* Reservado)
{
	int retorno = -1;

	if(this!=NULL && isValidReservado(Reservado)==1)
	{
		strcpy(this->reservado,Reservado);
		retorno = 0;
	}
	return retorno;
}
//GET DE INT
/** \brief Obtiene horas trabajadas del campo horas trabajadas de una estructura sCachorro
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int sCachorro_getReservado(sCachorro* this,char* Reservado)

{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(Reservado,this->reservado);
		retorno = 0;
	}
	return retorno;
}


//SET DE CHAR
/** \brief Carga Genero en el campo Genero de una estructura sCachorro
  *
 * \return 0 si logra la carga -1 si falla
 *
 */
int sCachorro_setGenero(sCachorro* this,char* genero)
{
	int retorno = -1;

	if(this!=NULL && isValidGenero(genero))
	{
		strcpy(this->genero,genero);
		retorno = 0;
	}
	return retorno;
}

//GET DE CHAR
/** \brief Obtiene  Genero del campo Genero  de una estructura sCachorro
 *
 * \return 0 si logra la obtenerlo -1 si falla
 *
 */
int sCachorro_getGenero(sCachorro* this,char* genero)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(genero,this->genero);
		retorno = 0;
	}
	return retorno;
}







/** \brief Carga todos los campos de una estructura sCachorro
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
sCachorro* sCachorro_newParametros(char* idStr,
		                           char* nombreStr,
								   char* diasStr,
								   char* raza,
								   char* reservado,
								   char* genero)
{
	sCachorro* retorno = NULL;
	sCachorro* this;
	this = sCachorro_new();

	int bId;
	int bDias;

	if(this!=NULL)
	{
		bId = atoi(idStr);
		bDias = atoi(diasStr);

		{
			if((sCachorro_setId(this,bId)==0) &&
			   sCachorro_setNombre(this,nombreStr)==0 &&
			   sCachorro_setDias(this,bDias)==0 &&
			   sCachorro_setRaza(this,raza)==0 &&
			   sCachorro_setReservado(this,reservado)==0 &&
			   sCachorro_setGenero(this,genero)==0)
			{
				retorno = this;
			}
			else
				sCachorro_delete(this);
		}
	}
	return retorno;
}


/** \brief Imprime un elemento de la estructura sCachorro
 *
 *
 *
 */
void emp_printAsCachorro(sCachorro* sCachorro)
{
	if(sCachorro!=NULL)
	{
		printf("\nID: %d\n"
				"Nombre: %s\n"
				"Dias: %d\n"
				"Raza: %s\n"
				"Reservado: %s\n"
				"Genero: %s\n",
				sCachorro->ID_Cachorro,
				sCachorro->nombre,
				sCachorro->dias,
				sCachorro->raza,
				sCachorro->reservado,
				sCachorro->genero);
	}
}


/** \brief Imprime array de elementos de la estructura sCachorro
 *
 *
 *
 */
void emp_printsCachorros(sCachorro* asCachorro,int len)
{
	int i;

	if(asCachorro!=NULL)
	{
		for(i=0;i<len;i++)
		{
			printf("\nID: %d\n"
					"Nombre: %s\n"
					"Dias: %d\n"
					"Raza: %s\n"
					"Reservado: %s\n"
					"Genero: %s\n",
					asCachorro[i].ID_Cachorro,
					asCachorro[i].nombre,
					asCachorro[i].dias,
					asCachorro[i].raza,
					asCachorro[i].reservado,
					asCachorro[i].genero);
		}
	}
}





/** \brief fUNCION CRITERIO CACHORRO MENOR A 45 DIAS
 *
 *
 *
 */
 int cachorro_filtersCachorroByDias(void* cachorro)
 {
 	int bsCachorro_dias = ((sCachorro*)cachorro)->dias;

 	if(bsCachorro_dias<45)
 	{
 		return 1;
 	}
 	else
 		return 0;

 	return -1;
 }

 int cachorro_filtersCachorroByGenero(void* genero)
 {
 	char* bsCachorro_genero = ((sCachorro*)genero)->genero;
 	char generoM[3] = {'M'};

 	if(strncmp(bsCachorro_genero,generoM,3)==0)
 	{
 		return 1;
 	}
 	else
 		return 0;

 	return -1;
 }

 int cachorro_filtersCachorroByCallejero(void* raza)
 {
 	char* bsCachorro_raza = ((sCachorro*)raza)->raza;
 	char callejero[10] = {"Callejero"};

 	if(strncmp(bsCachorro_raza,callejero,3)==0)
 	{
 		return 1;
 	}
 	else
 		return 0;

 	return -1;
 }
