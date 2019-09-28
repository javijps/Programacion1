

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utnF.h"

#define QTY_EMPLEADOS 1000





int main(void) {

	int edadesEmpleados[QTY_EMPLEADOS];

	if(initArrayInt(edadesEmpleados, QTY_EMPLEADOS,10)==0)
	{
		imprimeArrayInt(edadesEmpleados,QTY_EMPLEADOS);
	}

	return EXIT_SUCCESS;
}
