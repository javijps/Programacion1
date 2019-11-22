#ifndef employee_H_INCLUDED

#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"

#define employee_H_INCLUDED
typedef struct
{
    int ID_Cachorro;
    char nombre[128];
    int dias;
    char raza[50];
    char reservado[10];;//1 reservado 0 no reservado
    char genero[10];
}sCachorro ;

sCachorro* sCachorro_new();
sCachorro* sCachorro_newParametros(char* idStr,
		                           char* nombreStr,
								   char* diasStr,
								   char* raza,
								   char* reservado,
								   char* genero);
void sCachorro_delete();

int sCachorro_setId(sCachorro* this,int id);
int sCachorro_getId(sCachorro* this,int* id);

int sCachorro_setDias(sCachorro* this,int dias);
int sCachorro_getdias(sCachorro* this,int* dias);

int sCachorro_setRaza(sCachorro* this,char* raza);
int sCachorro_getRaza(sCachorro* this,char* raza);

int sCachorro_setReservado(sCachorro* this,char* Reservado);
int sCachorro_getReservado(sCachorro* this,char* Reservado);

int sCachorro_setGenero(sCachorro* this,char* genero);
int sCachorro_getGenero(sCachorro* this,char* genero);

void emp_printAsCachorro(sCachorro* sCachorro);
sCachorro* emp_findsCachorroById(LinkedList* pArrayListsCachorro,int idsCachorro);//busqueda por ID

int cachorro_filtersCachorroByDias(void* cachorro);
int cachorro_filtersCachorroByGenero(void* cachorro);
int cachorro_filtersCachorroByCallejero(void* genero);

#endif // sCachorro_H_INCLUDED
