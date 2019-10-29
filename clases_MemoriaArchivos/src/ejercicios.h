/*
 * ejerciciosPunteros.h
 *
 *  Created on: 27 oct. 2019
 *      Author: javijps
 */

#ifndef EJERCICIOSPUNTEROS_H_
#define EJERCICIOSPUNTEROS_H_

#include "utn.h"


struct sPersonaPunteros{

	int id;
	//-------------------------
	char nombrePersona[50];
	int edadPersona;
	int dniPersona;
}typedef sPersonaPunteros;


int funcionUno(int array[],int len);
int funcionDos(int array[],int len);
int funcionTres(int array[],int len);
int funcionCuatro(int array[],int len);

int loadPerson(sPersonaPunteros* pPerson);
char* getDynamicString(char* messagge);




struct sDAta{

	char* key;
	char* value;

}typedef sData;

sData* ped_new_Data();
void ped_deleteData(sData* this);
int ped_setKey(sData* this,char* key);
int ped_setValue(sData* this,char* value);

int loadDataFile(char* fileName,sData* array, int arrayLen);





typedef struct
{
	char namePeople[32];
	char surnamePeople[32];
	int agePeople;

}sPeople;

sPeople* peo_new_People();
void peo_deletePeople(sPeople* this);
int peo_setNamePeople(sPeople* this,char* name);
int peo_getNamePeople(sPeople* this,char* name);
int peo_setSursurnamePeople(sPeople* this,char* surname);
int peo_setSurnamePeople(sPeople* this,char* surname);
int peo_setAgePeople(sPeople* this,int* age);
int peo_getAgePeople(sPeople* this,int* age);
sPeople peo_new_PeopleParametros(char* namePeople,char* surnamePeople,int *agePeople);

void peo_loadDataPeople(sPeople* p);

int peo_savePeople(sPeople *p);
sPeople* peo_readPeople(char* surnamePeople);


#endif /* EJERCICIOSPUNTEROS_H_ */
