/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "eBook.h"
#include "Controller.h"



int main(void)
{
	setbuf(stdout,NULL);

	char continuar='s';
	int opcion;

	eEditorial miEditorial[6]={{1,"Planeta"},{2,"SIGLO XXI EDITORES"},{3,"Pearson"},{4,"Minotauro"},{5,"SALAMANDRA"},{6,"PENGUIN BOOKS"}};
	LinkedList* listaLibros = ll_newLinkedList();

	do
	{
		printf("\nIngresar opcion\n\n1.Lectura del archivo 'Datos.csv'\n2.Listado de los libros\n3.Ordenamiento de los libros\n4.Realizar descuentos\n5.Generar archivo con los descuentos realizados\n");
		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			if (controller_loadFromText("Datos.csv",listaLibros,miEditorial,6) ==0)
				{
					printf("Lectura realizada con exito \n");
				}
			break;
		case 2:
			if (controller_ListBook(listaLibros,miEditorial,6)==0)
				{
					printf("Listado realizado con exito\n");
				}
			break;
		case 3:
			if (controller_sortBook(listaLibros)==0)
				{
					printf("Ordenamiento realizado con exito\n");
				}
			break;
		case 4:
			if (controller_discountBook(listaLibros)==0)
			{
				printf("Descuentos realizados con exito\n");
			}
			break;
		case 5:
			if (controller_saveAsText("mapeado.csv",listaLibros,miEditorial,6)==0)
			{
				printf("Archivo guardado con exito\n");
			}
			break;
		case 0:
			continuar='n';
			break;
		default:
			printf("Ingresar una opcion valida\n");
			break;
		}
	}while(continuar!='n');



	return EXIT_SUCCESS;
}
