/*
 * eBook.h
 *
 *  Created on: 29 jun. 2021
 *      Author: jose_
 */

#ifndef EBOOK_H_
#define EBOOK_H_

typedef struct
{
	int id;
	char titulo[999];
	char autor[999];
	float precio;
	int editorialID;
}eLibro;

typedef struct
{
	int id;
	char editorial[50];
}eEditorial;

eLibro* eLibro_nuevo();

eLibro* eLibro_nuevoParametros(char* id,char* titulo,char* autor,char* precio,char* editorial,eEditorial editoriales[],int tamE);
int eLibro_setId(eLibro* this, int id);
int eLibro_getId(eLibro* this,int* id);
int eLibro_setTitulo(eLibro* this,char* titulo);
int eLibro_getTitulo(eLibro* this,char* titulo);
int eLibro_setAutor(eLibro* this,char* autor);
int eLibro_getAutor(eLibro* this,char* autor);
int eLibro_setPrecio(eLibro* this,float precio);
int eLibro_getPrecio(eLibro* this,float* precio);
int eLibro_setEditorialID(eLibro* this, int editorialID);
int eLibro_getEditorialID(eLibro* this,int* editorialID);

void eLibro_imprimir(eLibro* this,eEditorial editoriales[],int tamE);
int eLibro_ordenarPorAutor(void* pLibroA,void* pLibroB);

int editorialPorId(int id,eEditorial editoriales[],int tam,char* editorial);
int idPorEditorial(char* editorial,eEditorial editoriales[],int tam,int* id);
int Descuento (void* libro);

#endif /* EBOOK_H_ */
