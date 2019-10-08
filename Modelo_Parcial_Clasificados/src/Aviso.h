/*
 * Aviso.h
 *
 *  Created on: 7 oct. 2019
 *      Author: javijps
 */

#ifndef AVISO_H_
#define AVISO_H_
#include <stdio.h>
#include <string.h>


typedef struct {

	int idAviso;
	int statusAviso;
	int numeroRubro;
	char textoAviso[64];
	int idCliente;
} sAviso;



int initAviso(sAviso *list, int len);
int getDatosAviso(sAviso *list,int len);
int findEmptyAviso(sAviso *list,int len);
int addAviso(sAviso *list,int len);
int removeAviso(sAviso *list, int len, int id);
int printAviso(sAviso *list, int len);
int findAvisoById(sAviso* list, int len,int id);
void mostrarUnAviso(sAviso miAviso);
void avisoForzado(sAviso *list,int cantidad);


#endif /* AVISO_H_ */
