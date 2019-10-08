/*
 * Client.h
 *
 *  Created on: 6 oct. 2019
 *      Author: javijps
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdio.h>
#include <string.h>


typedef struct {

	int idCLient;
	int statusClient;
	char name[51];
	char lastName[51];
	char cuit[51];

} sClient;

int initClient(sClient *list, int len);
int getDatosClient(sClient *list,int len);
int findEmptyClient(sClient *list,int len);
int addClient(sClient *list,int len);
int modifyClientById(sClient *list,int len,int id);
int removeClient(sClient *list, int len, int id);
int sortClient(sClient *list, int len, int order);
int printClient(sClient *list, int len);
int findClientById(sClient* list, int len,int id);

void clienteForzado(sClient *list,int cantidad);



#endif /* CLIENT_H_ */
