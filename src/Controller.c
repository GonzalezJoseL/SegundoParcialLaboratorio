#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eBook.h"
//#include "utn.h"
#include "parser.h"
// //#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBook,eEditorial editoriales[],int tamE)
{
    int retorno=-1;
    FILE* pFile;

    if(path != NULL && pArrayListBook != NULL)
    {
        pFile=fopen(path,"r");

        if (pFile!=NULL)
        {

      	     retorno=parser_BookFromText(pFile,pArrayListBook,editoriales,tamE);

        }

    }
    fclose(pFile);
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListBook)
{
    int retorno=-1;
    FILE* pFile;

    if(path != NULL && pArrayListBook != NULL)
    {

        pFile=fopen(path,"rb");
        if (pFile!=NULL)
        {

            retorno=parser_EmployeeFromBinary(pFile,pArrayListBook);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_ListBook(LinkedList* pArrayListBook,eEditorial editoriales[],int tamE)
{
    int retorno=-1;
    int i, len;
    eLibro* pLibro;

    if (pArrayListBook != NULL)
    {
    	len=ll_len(pArrayListBook);
    	for (i=0;i<len;i++)
    	{
    		pLibro=(eLibro*)ll_get(pArrayListBook,i);

    		if (pLibro != NULL)
    		{
    			eLibro_imprimir(pLibro,editoriales,tamE);
    		}
    	}
    	retorno=0;
    	printf("\n");
    }
    return retorno;
}

int controller_sortBook(LinkedList* pArrayListBook)
{
	int retorno=-1;
	if(pArrayListBook != NULL)
	{
		retorno=ll_sort(pArrayListBook,eLibro_ordenarPorAutor,1);
	}
    return retorno;
}

int controller_discountBook(LinkedList* pArrayListBook)
{
	int retorno=-1;
	if(pArrayListBook != NULL)
	{
		retorno=ll_map(pArrayListBook,Descuento);
	}
	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListBook,eEditorial editoriales[],int tamE)
{
	int retorno=-1;
	int len, i;
	char editorialAux[90];
	eLibro* pLibro;
	FILE* pFILE;
	if (path != NULL && pArrayListBook != NULL)
	{
		pFILE=fopen(path,"w");
		if (pFILE != NULL)
		{
			fprintf(pFILE,"id,titulo,autor,precio,editorialId\n");
			retorno=0;
			len=ll_len(pArrayListBook);
			for (i=0;i<len;i++)
			{
				pLibro=ll_get(pArrayListBook,i);
				editorialPorId(pLibro->editorialID,editoriales,tamE,editorialAux);
				fprintf(pFILE,"%d,%s,%s,%f,%s\n",pLibro->id,pLibro->titulo,pLibro->autor,pLibro->precio,editorialAux);
			}
			fclose(pFILE);
		}
	}

	return retorno;
}
