/*
 * Venta.h
 *
 *  Created on: 18 nov. 2019
 *      Author: javijps
 */

#ifndef VENTA_H_
#define VENTA_H_
#include "LinkedList.h"

struct S_Venta
{
  int ID_Venta;
  int Status;
  char Fecha_Venta[20];
  char Tipo_Foto[50];
  int Cantidad;
  float Precio_Unitario;
  char CUIT_Cliente[50];
};
typedef struct S_Venta Venta;

Venta* venta_new();
Venta* venta_newParametros(char* ID_Venta,
						   char* Fecha_Venta,
						   char* Tipo_Foto,
						   char* Cantidad,
						   char* Precio_Unitario,
						   char* CUIT_Cliente);
void venta_delete();

int venta_set_IdVenta(Venta* this,int id);
int venta_get_IdVenta(Venta* this,int* id);

int venta_set_FechaVenta(Venta* this,char *fecha);
int venta_get_FechaVenta(Venta* this,char *fecha);

int venta_set_Tipo_Foto(Venta* this,char *tipo_foto);
int venta_get_Tipo_Foto(Venta* this,char *tipo_foto);

int venta_set_Cantidad(Venta* this,int cantidad);
int venta_get_Cantidad(Venta* this,int* cantidad);//va direccion de memoria?

float venta_set_Precio_Unitario(Venta* this,float precio);
float venta_get_Precio_Unitario(Venta* this,float* precio);

int venta_set_CUIT_Cliente(Venta* this,char *cuit);
int venta_get_CUIT_Cliente(Venta* this,char *cuit);

void ven_printAventa(Venta* venta);


int ven_contadorFotosReveladas(void* pElement);
int venta_total_fotos_reveladas(LinkedList* pArrayListEmployee);

int ven_montoMayorA150(void* pElement);
int venta_mayor150(LinkedList* pArrayListEmployee);

int ven_montoMayorA300(void* pElement);
int venta_mayor300(LinkedList* pArrayListEmployee);

int ven_fotoEsPolaroid(void* pElement);
int venta_esPolaroid(LinkedList* pArrayListEmployee);


#endif /* VENTA_H_ */
