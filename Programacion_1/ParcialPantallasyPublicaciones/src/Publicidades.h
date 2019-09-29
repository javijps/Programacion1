/*
 * Publicidad.h
 *
 *  Created on: 28 sep. 2019
 *      Author: javijps
 */

#ifndef PUBLICIDADES_H_
#define PUBLICIDADES_H_

typedef struct publicidad{

	int id;
	int status;
	char cuitCliente[50]; //cambiar a char cuando haga getCuit
	int diasPublicacion;
	char filePublicacion[50];
	int idPantalla;

} publicidad;

int initPublicidad(publicidad *aPublicidad, int cantidad);
int imprimirPublicidades(publicidad *aPublicidad, int cantidad);
int getDatosPublicidad(publicidad *aPublicidad, int cantidad);//reemplazar getstring por get nombre, get strin x get direccion
int buscarPublicidadLibre(publicidad *aPublicidad,int cantidad);
int contratarPublicidad(publicidad *aPublicidad, int cantidad,int idPantalla);

int buscarPublicidadPorId(publicidad *aPublicidad, int cantidad,int cuit);
int modificarPublicidadPorCuit(publicidad *aPublicidad, int cantidad,int cuit);
int bajaPublicidadPorId(publicidad *aPublicidad, int cantidad,int cuit);

//int contratarPublicidad(publicidad *aPublicidad, int cantidad,int idPantalla);
//void pantallaForzada(pantalla *aPantalla,int cantidad);
#endif /* PUBLICIDADES_H_ */
