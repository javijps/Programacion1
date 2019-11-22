#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorro.h"






/*CAMBIAR NOMBRE DE LOS BUFFER
 * MODIFICAR FSCANF EN FUNCION DE LA FORMA EN LA QUE ESTAN LOS DATOS EN EL ARCHIVO
 */


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_sCachorroFromText(FILE* pFile , LinkedList* pArrayListsCachorro)
{
	int retorno = -1;
	int flagCabecera=0;

	char bIdStr[1046];
	char bNombreStr[1046];
	char bDiasStr[1046];
	char bRaza[1046];
	char bReservado[1046];
	char bGenero[1046];
	sCachorro* bCachorro;
	int rd;

	if(pFile!=NULL && pArrayListsCachorro!=NULL)
	{
		while(!feof(pFile))
		{
			rd = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					    bIdStr,
						bNombreStr,
						bDiasStr,
						bRaza,
						bReservado,
						bGenero);
			if(flagCabecera==0)
			{
				flagCabecera=1;
				continue;
			}
			else if(flagCabecera!=0 && rd==6)
			{
				bCachorro = sCachorro_newParametros(bIdStr,
						                            bNombreStr,
													bDiasStr,
													bRaza,
													bReservado,
													bGenero);
				if(bCachorro!=NULL && ll_add(pArrayListsCachorro,bCachorro)==0)
				{
					retorno = 0;
				}
				else
				{
					retorno = -1;
					break;
				}
			}
		}
	}
	return retorno;
}

//
////CON EL CAMBIO DE ESTRUCTURA Y LOS PASOS PREVIOS HECHOS, SOLO DEBERIA REFACTORIZAR
///** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
// *
// * \param path char*
// * \param pArrayListEmployee LinkedList*
// * \return int
// *
// */
//int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
//{
//	int retorno = -1;
//	Employee* bEmpleado;
//	int cant =0;
//
//	if(pFile!=NULL && pArrayListEmployee!=NULL)
//	{
//		while(!feof(pFile))
//		{
//			bEmpleado = employee_new();
//			cant = fread(bEmpleado,sizeof(Employee),1,pFile);
//			if(cant==1)
//			{
//				ll_add(pArrayListEmployee,bEmpleado);
//				retorno = 0;
//			}
//		}
//	}
//	else
//		printf("error de lectura");
//	return retorno;
//}
