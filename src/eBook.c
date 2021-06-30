#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eBook.h"

eLibro* eLibro_nuevo()
{
	return (eLibro*) malloc(sizeof(eLibro));
}

eLibro* eLibro_nuevoParametros(char* id,char* titulo,char* autor,char* precio,char* editorial,eEditorial editoriales[],int tamE)
{
	eLibro* pLibro=eLibro_nuevo();
	int editorialID;
	if (pLibro !=NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL && editorial != NULL)
	{
		eLibro_setId(pLibro,atoi(id));
		eLibro_setTitulo(pLibro,titulo);
		eLibro_setAutor(pLibro,autor);
		eLibro_setPrecio(pLibro,atof(precio));
		idPorEditorial(editorial,editoriales,tamE,&editorialID);
		eLibro_setEditorialID(pLibro,editorialID);

	}
	return pLibro;
}

int eLibro_setId(eLibro* this, int id)
{
	int retorno=-1;
	if (this!=NULL)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int eLibro_getId(eLibro* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int eLibro_setTitulo(eLibro* this,char* titulo)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(this->titulo,titulo);
        retorno=0;
    }
    return retorno;
}

int eLibro_getTitulo(eLibro* this,char* titulo)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(titulo,this->titulo);
        retorno=0;
    }
    return retorno;
}

int eLibro_setAutor(eLibro* this,char* autor)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(this->autor,autor);
        retorno=0;
    }
    return retorno;
}

int eLibro_getAutor(eLibro* this,char* autor)
{
    int retorno=-1;
    if(this != NULL)
    {
        strcpy(autor,this->autor);
        retorno=0;
    }
    return retorno;
}

int eLibro_setPrecio(eLibro* this,float precio)
{
	int retorno=-1;
	if (this!=NULL)
	{
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}

int eLibro_getPrecio(eLibro* this,float* precio)
{
	int retorno=-1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int eLibro_setEditorialID(eLibro* this, int editorialID)
{
	int retorno=-1;
	if (this!=NULL)
	{

		this->editorialID=editorialID;
		retorno=0;
	}
	return retorno;
}

int eLibro_getEditorialID(eLibro* this,int* editorialID)
{
	int retorno=-1;
	if(this!=NULL && editorialID!=NULL)
	{
		*editorialID=this->editorialID;
		retorno=0;
	}
	return retorno;
}

void eLibro_imprimir(eLibro* this,eEditorial editoriales[],int tamE)
{
	int id, editorialID;
	char titulo[200], autor[200], editorial[200];
	float precio;


	if (
	eLibro_getId(this,&id)==0 &&
	eLibro_getTitulo(this,titulo)==0 &&
	eLibro_getAutor(this,autor)==0 &&
	eLibro_getPrecio(this,&precio)==0 &&
	eLibro_getEditorialID(this,&editorialID)==0
	)
	{

		editorialPorId(editorialID,editoriales,tamE,editorial);

		printf("ID: %3d		TITULO: %-50s	AUTOR: %-10s	PRECIO: %f		EDITORIAL: %-15s	EDITORIAL ID: %d\n",id,titulo,autor,precio,editorial,editorialID);
	}
}

int editorialPorId(int id,eEditorial editoriales[],int tam,char* editorial)
{
	int retorno=-1;
	int i;

	for (i=0;i<tam;i++)
	{
		if (editoriales[i].id==id)
		{
			strcpy(editorial,editoriales[i].editorial);
			retorno=0;
		}
	}
	return retorno;
}

int idPorEditorial(char* editorial,eEditorial editoriales[],int tam,int* id)
{
	int retorno=-1;
	int i;

	for (i=0;i<tam;i++)
	{

		if (strcmp(editoriales[i].editorial,editorial)==0)
		{
			*id=editoriales[i].id;
			retorno=0;
		}
	}
	return retorno;
}

int eLibro_ordenarPorAutor(void* pLibroA,void* pLibroB)
{
	int retorno=0;

	char autorA[300];
	char autorB[300];

	eLibro* pLibroauxA;
	eLibro* pLibroauxB;

	pLibroauxA=(eLibro*)pLibroA;
	pLibroauxB=(eLibro*)pLibroB;

	eLibro_getAutor(pLibroauxA,autorA);
	eLibro_getAutor(pLibroauxB,autorB);

	retorno=strcmp(autorA,autorB);

	return retorno;
}

int Descuento (void* libro)
{
	int retorno=-1;
	eLibro* pLibroaux;
	int descuento;
	pLibroaux=(eLibro*)libro;

	if (pLibroaux->editorialID==1 && pLibroaux->precio>=300)
	{
		retorno=0;
		descuento=pLibroaux->precio*20/100;
		pLibroaux->precio=pLibroaux->precio-descuento;
	}
	else
	{
		if(pLibroaux->editorialID==2 && pLibroaux->precio<=200)
		{
			retorno=0;
			descuento=pLibroaux->precio*10/100;
			pLibroaux->precio=pLibroaux->precio-descuento;
		}
	}
	return retorno;
}



