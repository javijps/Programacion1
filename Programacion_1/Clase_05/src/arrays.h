
#define QTY_EMPLEADOS 1000

int imprimeArrayInt(*array[],int limite);
int initArrayInt(*array[],int limite, valor);
int getArray(int *pResultado,
		        char *mensaje,
				char *mensajeError,
				int *maximo,
				int *minimo,
				int reintentos);
int maximoArray(*array[],int limite,int cantidadElementos, int *pResultados);
int minimoArray(*array[],int limite,int cantidadElementos, int *pResultados);
int promedioArrayInt(*array[],int limite,int cantidadElementos, int *pResultados);
