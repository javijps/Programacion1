#include "Parser.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)//MENSAJE ACA EN LUGAR DEL MAIN?
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile!=NULL &&
			pArrayListEmployee!=NULL &&
			parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
	{
		retorno = 0;
		printf("Archivo cargado!\n");
		fclose(pFile);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario). Si no existe, lo crea
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path,"rb");
	if(pFile!=NULL)
	{
		if(pArrayListEmployee!=NULL &&
		   ll_len(pArrayListEmployee)==0 &&
		   parser_EmployeeFromBinary(pFile,pArrayListEmployee)==0)
		{
			retorno = 0;
			printf("Archivo cargado!\n");
		}
		fclose(pFile);
	}
	else
		printf("Archivo inexistente!\n");

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int i;
	Employee* bEmpleado;

	pFile = fopen(path,"w");
	lenLL = ll_len(pArrayListEmployee);
	if(pFile!=NULL && pArrayListEmployee!=NULL && lenLL>0)
	{
		fprintf(pFile,"Id,Nombre,HorasTrabajadas,Sueldo\n");
		for(i=0;i<lenLL;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			if(bEmpleado!=NULL)
			{
				fprintf(pFile,"%d,%s,%d,%d\n",
						bEmpleado->id,
						bEmpleado->nombre,
						bEmpleado->horasTrabajadas,
						bEmpleado->sueldo);
				retorno = 0;
			}
			else
				break;
		}
		printf("Informacion guardada!\n");
	}
	else
		printf("No fue posible guardar la informacion!\n");
	fclose(pFile);
	return retorno;

}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int lenLL;
	int i;
	Employee* bEmpleado;

	pFile = fopen(path,"wb");
	lenLL = ll_len(pArrayListEmployee);

	if(pFile!=NULL && pArrayListEmployee!=NULL && lenLL>0)
	{
		for(i=0;i<lenLL;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);

			if(bEmpleado!=NULL)
			{
				fwrite(bEmpleado,sizeof(Employee),1,pFile);
				retorno = 0;
			}
		}
		printf("Informacion guardada!\n");
		fclose(pFile);
	}
	else
		printf("No fue posible guardar la informacion!\nArchivo Inexistente!\n");
	return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char bId[1046];
	char bName[1046];
	char bHoras[1046];
	int flagCabecera=0;
	Employee* bEmpleado;
	int rd;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			rd = fscanf(pFile,"%[^,],%[^,],%[^\n],\n",bId,bName,bHoras);
			if(rd==3)
			{
				if(flagCabecera==0)
				{
					flagCabecera=1;
					continue;
				}
				else if(flagCabecera!=0 && rd==3)
				{
					bEmpleado = employee_newParametros(bId,bName,bHoras);
					if(bEmpleado!=NULL && ll_add(pArrayListEmployee,bEmpleado)==0)
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
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* bEmpleado;
	int cant =0;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			bEmpleado = employee_new();
			cant = fread(bEmpleado,sizeof(Employee),1,pFile);
			if(cant==1)
			{
				ll_add(pArrayListEmployee,bEmpleado);
				retorno = 0;
			}
		}
	}
	else
		printf("error de lectura");
	return retorno;
}


int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    return 1;
}












int controller_CalcularSueldo(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lenLL;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		ll_map(pArrayListEmployee,em_calcularSueldo);//1asc y 0 desc
		retorno = 0;
	}
	else
	{
		printf("No existen datos cargados a mapear!\n");
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int lenLL;
	Employee* bEmpleado;

	lenLL = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL && lenLL>0)
	{
		for(i=0;i<lenLL;i++)
		{
			bEmpleado = ll_get(pArrayListEmployee,i);
			printf("ID: %d     Employee: %15s     Horas trabajadas %6d     Sueldo: %8d\n",
					bEmpleado->id,bEmpleado->nombre,bEmpleado->horasTrabajadas,bEmpleado->sueldo);
			retorno = 0;
		}
	}
	else
		printf("No fue posible imprimir la informacion!\n");
	return retorno;
}


