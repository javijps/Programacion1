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
	int cuitCliente; //cambiar a char cuando haga getCuit
	int diasPublicacion;
	char filePublicacion;
	int idPantalla;

} publicidad;

int initPublicidad(publicidad *aPublicidad, int cantidad);
int getDatosPublicidad(publicidad *aPublicidad, int cantidad);//reemplazar getstring por get nombre, get strin x get direccion
int buscarPublicidadLibre(publicidad *aPublicidad, int cantidad);
int altaPublicidad(publicidad *aPublicidad, int cantidad);
int imprimirPublicidades(publicidad *aPublicidad, int cantidad);
int buscarPublicidadPorId(publicidad *aPublicidad, int cantidad,int cuit);
int modificarPublicidadPorCuit(publicidad *aPublicidad, int cantidad,int cuit);
int bajaPublicidadPorId(publicidad *aPublicidad, int cantidad,int cuit);

//void pantallaForzada(pantalla *aPantalla,int cantidad);
#endif /* PUBLICIDADES_H_ */
