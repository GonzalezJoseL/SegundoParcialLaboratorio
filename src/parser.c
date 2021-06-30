#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eBook.h"
#include "parser.h"

int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook,eEditorial editoriales[],int tamE)
{
	int retorno=-1;
	eLibro* pLibro;
	char id[1000], titulo[1000], autor[1000], precio[1000], editorial[1000];

	if (pFile != NULL && pArrayListBook != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,editorial);

		do
		{

			if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,editorial)==5)
			{

				pLibro=eLibro_nuevoParametros(id,titulo,autor,precio,editorial,editoriales,tamE);
				if (pLibro != NULL)
				{
					ll_add(pArrayListBook,pLibro);
					retorno=0;
				}
			}
			else
			{
				retorno=-2;
				break;
			}
		}while (!feof(pFile));
	}
    return retorno;
}



int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno = -1;
	eLibro *pLibro;
	if(pFile != NULL && pArrayListLibros != NULL)
	{
		do
		{
			pLibro=eLibro_nuevo();
			if(fread(pLibro,sizeof(eLibro),1,pFile)==1)
			{
				ll_add(pArrayListLibros, pLibro);
			}
			retorno=0;
		}while(!feof(pFile));
	}
	return retorno;
}
