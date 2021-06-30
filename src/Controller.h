/*
 * Controller.h
 *
 *  Created on: 29 jun. 2021
 *      Author: jose_
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
int controller_loadFromText(char* path , LinkedList* pArrayListBook,eEditorial editoriales[],int tamE);
int controller_loadFromBinary(char* path , LinkedList* pArrayListBook);
int controller_ListBook(LinkedList* pArrayListBook,eEditorial editoriales[],int tamE);
int controller_sortBook(LinkedList* pArrayListBook);
int controller_discountBook(LinkedList* pArrayListBook);
int controller_saveAsText(char* path , LinkedList* pArrayListBook,eEditorial editoriales[],int tamE);
#endif /* CONTROLLER_H_ */
