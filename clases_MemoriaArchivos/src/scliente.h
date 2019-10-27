/*
 * persona.h
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	int idCliente;
	int status;
	char nombre[51];
	char direccion[51];
	char cuit[15];
	char localidad[51];

}sCliente;


sCliente* cli_new_Cliente();
void cli_deleteCliente(sCliente* this);

int cli_setNombre(sCliente* this,char* nombre);
int cli_getNombre(sCliente* this,char* nombre);

int cli_setDireccion(sCliente* this,char* direccion);
int cli_getDireccion(sCliente* this,char* direccion);

int cli_setCuit(sCliente* this,char* cuit);
int cli_getCuit(sCliente* this,char* cuit);

int cli_setLocalidad(sCliente* this,char* localidad);
int cli_getLocalidad(sCliente* this,char* localidad);

sCliente cli_new_ClienteParametros(char *nombre,char *direccion,char *cuit,char *localidad);

void printPerson(sCliente* pCliente);

#endif /* PERSONA_H_ */
