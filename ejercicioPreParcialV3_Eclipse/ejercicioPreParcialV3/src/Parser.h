#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);;
int controller_CalcularSueldo(LinkedList* pArrayListEmployee);


#endif // PARSER_H_INCLUDED
