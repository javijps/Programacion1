/*
 * Venta.c
 *
 *  Created on: 18 nov. 2019
 *      Author: javijps
 */
#include "Venta.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_EMPTY 0;
#define STATUS_NOT_EMPTY 1;


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

static int isValidFecha(char fecha)//CARGAR UTN.H
{
//
//	int retorno=-1;
//
//	if(fecha>=0)
//	{
//		retorno=1;
//	}
	return 1;
}

static int isValidTipo_Foto(char tipo_foto)//CARGAR UTN.H
{
//
//	int retorno=-1;
//
//	if(fecha>=0)
//	{
//		retorno=1;
//	}
	return 1;
}

static int isValidCantidad(int cantidad)//CARGAR UTN.H
{
	int retorno=-1;

	if(cantidad>0)
	{
		retorno=1;
	}
	return retorno;
}

static int isValidPrecio(float precio)//CARGAR UTN.H
{
	int retorno=-1;

	if(precio>0)
	{
		retorno=1;
	}
	return retorno;
}


//doc
Venta* venta_new()
{
    Venta* this= NULL;
    this = malloc(sizeof(Venta));
    if(this!=NULL)
    {
    	this->Status = STATUS_EMPTY;
    }
    return this;
}


//doc
void venta_delete(Venta* this)
{
	free(this);
}


//doc
int venta_set_IdVenta(Venta* this,int id)
{
	int retorno = -1;

	if(this!=NULL && isValidId(id))
	{
		this->ID_Venta = id;
		retorno = 0;
	}
	return retorno;
}

//doc
int venta_get_IdVenta(Venta* this,int* id)//va direccion de memoria?
{
	int retorno = -1;

	if(this!=NULL)
	{
		*id = this->ID_Venta;
		retorno = 0;
	}
	return retorno;
}


int venta_set_FechaVenta(Venta* this,char *fecha)
{
	int retorno = -1;

	if(this!=NULL && isValidFecha(*fecha))
	{
		strcpy(this->Fecha_Venta,fecha);
		retorno = 0;
	}
	return retorno;
}

int venta_get_FechaVenta(Venta* this,char *fecha)//va direccion de memoria?
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(fecha,this->Fecha_Venta);
		retorno = 0;
	}
	return retorno;
}



int venta_set_Tipo_Foto(Venta* this,char *tipo_foto)
{
	int retorno = -1;

	if(this!=NULL && isValidTipo_Foto(*tipo_foto))
	{
		strcpy(this->Tipo_Foto,tipo_foto);
		retorno = 0;
	}
	return retorno;
}

int venta_get_Tipo_Foto(Venta* this,char *tipo_foto)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(tipo_foto,this->Tipo_Foto);
		retorno = 0;
	}
	return retorno;
}



int venta_set_Cantidad(Venta* this,int cantidad)
{
	int retorno = -1;

	if(this!=NULL && isValidCantidad(cantidad))
	{
		this->Cantidad = cantidad;
		retorno = 0;
	}
	return retorno;
}

//doc
int venta_get_Cantidad(Venta* this,int* cantidad)//va direccion de memoria?
{
	int retorno = -1;

	if(this!=NULL)
	{
		*cantidad = this->Cantidad;
		retorno = 0;
	}
	return retorno;
}

float venta_set_Precio_Unitario(Venta* this,float precio)
{
	int retorno = -1;

	if(this!=NULL && isValidPrecio(precio))
	{
		this->Precio_Unitario = precio;
		retorno = 0;
	}
	return retorno;
}

float venta_get_Precio_Unitario(Venta* this,float* precio)
{
	int retorno = -1;

	if(this!=NULL)
	{
		*precio = this->Precio_Unitario;
		retorno = 0;
	}
	return retorno;
}

int venta_set_CUIT_Cliente(Venta* this,char *cuit)
{
	int retorno = -1;

	if(this!=NULL && esCuit(cuit)==0)
	{
		strcpy(this->CUIT_Cliente,cuit);
		retorno = 0;
	}
	return retorno;
}
int venta_get_CUIT_Cliente(Venta* this,char *cuit)
{
	int retorno = -1;

	if(this!=NULL)
	{
		strcpy(cuit,this->CUIT_Cliente);
		retorno = 0;
	}
	return retorno;
}



/** \brief Carga todos los campos de una estructura Employee
 *
 * \return 0 si logra la carga -1 si falla
 *
 */
Venta* venta_newParametros(char* ID_Venta,
						   char* Fecha_Venta,
						   char* Tipo_Foto,
						   char* Cantidad,
						   char* Precio_Unitario,
						   char* CUIT_Cliente)
{
	Venta* retorno = NULL;
	Venta* this;
	this = venta_new();

	int bId_venta;
	int bCantidad;
	float bPrecio_Unitario;

	if(this!=NULL)
	{
		bId_venta = atoi(ID_Venta);
		bCantidad = atoi(Cantidad);
		bPrecio_Unitario = atof(Precio_Unitario);

			if(venta_set_IdVenta(this,bId_venta)==0 &&
					venta_set_FechaVenta(this,Fecha_Venta)==0 &&
					venta_set_Tipo_Foto(this,Tipo_Foto)==0 &&
					venta_set_Cantidad(this,bCantidad)==0 &&
					venta_set_Precio_Unitario(this,bPrecio_Unitario)==0 &&
					venta_set_CUIT_Cliente(this,CUIT_Cliente)==0)
			{
				retorno = this;
				this->Status = STATUS_NOT_EMPTY;
			}
			else
				venta_delete(this);
	}
	return retorno;
}




int ven_contadorFotosReveladas(void* pElement)
{
	int cantidadDeFotos = (((Venta*)pElement)->Cantidad);

	if(pElement!=NULL)
	{
		return cantidadDeFotos;
	}
	return 0;

}



int venta_total_fotos_reveladas(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;
	int acumuladorCantidadFotos = 0;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		acumuladorCantidadFotos = ll_count(pArrayListEmployee,ven_contadorFotosReveladas);
		if(acumuladorCantidadFotos>0)
		{
			retorno = acumuladorCantidadFotos;
		}
	}
	else
	{
		printf("No existen datos cargados para calcular!\n");
	}
	return retorno;
}




int ven_montoMayorA150(void* pElement)
{
	int precioUnitario = (((Venta*)pElement)->Precio_Unitario);
	int cantidadDeFotos = (((Venta*)pElement)->Cantidad);
	int precioTotal = precioUnitario * cantidadDeFotos;

	if(pElement!=NULL && precioTotal>150)
	{
		return 1;
	}
	return 0;
}

int venta_mayor150(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;
	int esMayorA150 = 0;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		esMayorA150 = ll_count(pArrayListEmployee,ven_montoMayorA150);
		if(esMayorA150>0)
		{
			retorno = esMayorA150;
		}
	}
	else
	{
		printf("No existen datos cargados para calcular!\n");
	}
	return retorno;
}


int ven_montoMayorA300(void* pElement)
{
	int precioUnitario = (((Venta*)pElement)->Precio_Unitario);
	int cantidadDeFotos = (((Venta*)pElement)->Cantidad);
	int precioTotal = precioUnitario * cantidadDeFotos;

	if(pElement!=NULL && precioTotal>300)
	{
		return 1;
	}
	return 0;
}

int venta_mayor300(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;
	int esMayorA300 = 0;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		esMayorA300 = ll_count(pArrayListEmployee,ven_montoMayorA300);
		if(esMayorA300>0)
		{
			retorno = esMayorA300;
		}
	}
	else
	{
		printf("No existen datos cargados para calcular!\n");
	}
	return retorno;
}


int ven_fotoEsPolaroid(void* pElement)
{
	char* tipoDeFoto = (((Venta*)pElement)->Tipo_Foto);
	char polaroidUno[50] = {"POLAROID_11x9"};
	char polaroidDos[50] = {"POLAROID_10x10"};

	if(pElement!=NULL && (strncmp(tipoDeFoto,polaroidUno,50)==0 || strncmp(tipoDeFoto,polaroidDos,50)==0))
	{
		return 1;
	}
	return 0;
}

int venta_esPolaroid(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;
	int esPolaroid = 0;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		esPolaroid = ll_count(pArrayListEmployee,ven_fotoEsPolaroid);
		if(esPolaroid>0)
		{
			retorno = esPolaroid;
		}
	}
	else
	{
		printf("No existen datos cargados para calcular!\n");
	}
	return retorno;
}
