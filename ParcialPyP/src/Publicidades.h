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
int getDatosPublicidad(publicidad *aPublicidad, int cantidad,int idPantalla);//reemplazar getstring por get nombre, get strin x get direccion
int buscarPublicidadLibre(publicidad *aPublicidad,int cantidad);
int contratarPublicidad(publicidad *aPublicidad, int cantidad,int idPantalla);
int buscarPublicidadesPorCuit(publicidad *aPublicidad, int cantidad,char *cuit);
int buscarPublicidadPorId(publicidad *aPublicidad, int cantidad,int id);
int bajaPublicidadPorId(publicidad *aPublicidad, int cantidad,int cuit);
void publicidadesForzadas(publicidad aPublicidad[],int cantidad);
void imprimirUnaPublicidad(publicidad miPublicidad);
int buscarPublicidadPorIdPantallaYcuit(publicidad *aPublicidad, int cantidad,int idPantalla,char *cuit);
int modificarPublicidadPorCuit(publicidad *aPublicidad, int cantidad,int cuit);

void imprimirUnaPublicidadConPrecio(publicidad miPublicidad,float precioPublicidad);

#endif /* PUBLICIDADES_H_ */
