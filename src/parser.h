/*
 * parser.h
 *
 *  Created on: 29 jun. 2021
 *      Author: jose_
 */

#ifndef PARSER_H_
#define PARSER_H_

//int parser_BookFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook,eEditorial editoriales[],int tamE);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListLibros);

#endif /* PARSER_H_ */
