#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare( void* a, void* b )
{
	return ( *((char*)a) == *((char*)b)) ? 1 : 0;
}

int main()
{
//valgrind memoryLeak : PASS
//Teste de Alocacao de Nodes
/*{{{
=======
Teste de Alocacao de Nodes
	Node* n = newNode("asdfghjkl;\0",sizeof(char)*11 );
	char c[100];
	c[10] = '\0';
	strcpy(c,n->data);
	rintf("%s\n",c);

	free( n->data );
	free( n );

	return 0;
	printf("%s\n",c);
	return 0;


//valgrind memoryLeak : PASS
//Teste de Alocacao de Lista
	List *l = initializeList( createList(), sizeof(char), &main, NULL ,NULL );
	free( l->sentinela );
	free( l );
	return 0;
*/

//TEste de adicionar na Lista
	List *l = initializeList( createList(), sizeof(char), &main, NULL ,NULL );

	char letra = 'c';
	addList( l,  &letra);
	addList( l,  &letra);
	addList( l,  &letra);
	addList( l,  &letra);
	addList( l,  &letra);

	Node* n = l->sentinela->next;

	printf("size: %d\n", l->size );
	while( n->data != NULL )
	{
		printf("%c\n", *((char*)n->data) );
		n = n->next;
	}

	n = l->sentinela;
	while( n->data != NULL )
	{
		free( n->data );
		n = n->next;
	}

//Teste adicionanado na lista em lugares diferentes
	addIndexList(l, 3, "g");
	n = l->sentinela->next;

	printf("size: %d\n", l->size );
	while( n->data != NULL )
	{
		printf("%s\n", (char*) n->data );
		n = n->next;
	}

	addIndexList(l, 0, "g");
	n = l->sentinela->next;

	printf("size: %d\n", l->size );
	while( n->data != NULL )
	{
		printf("%s\n", (char*) n->data );
		n = n->next;
	}

	addIndexList(l, 13, "AAA");
	n = l->sentinela->next;

	printf("size: %d\n", l->size );
	while( n->data != NULL )
	{
		printf("%s\n", (char*) n->data );
		n = n->next;
	}
	
//Teste para removeList(List* l, int index, void* e )
//	List *l = initializeList( createList(), sizeof(char), NULL, NULL, NULL );
//	addList( l, "a");
//	addList( l, "b");
//	addList( l, "c");
//	addList( l, "d");
//	addList( l, "e");
//	addList( l, "f");
//	addList( l, "g");
//	addList( l, "h");
//	addList( l, "i");
//
//	char letra;
//	removeList( l, 0, &letra );
//	printf("%c\n", letra );
//
//	Node* n = l->sentinela->next;
//	printf("size: %d\n", l->size );
//	while( n->data != NULL )
//	{
//		printf("%s\n", (char*) n->data );
//		n = n->next;
//	}

//Teste para a funcao removeElementList
//

	
//Teste para a funcao getList
//
//	List *l = initializeList( createList(), sizeof(char), &compare, NULL, NULL );
//	addList( l, "a");
//	addList( l, "b");
//	addList( l, "c");
//	addList( l, "d");
//	addList( l, "e");
//	addList( l, "f");
//	addList( l, "g");
//	addList( l, "h");
//	addList( l, "i");
//
//	int i=0;
//	char letra;
//	for(; i< sizeList(l) ; i++ )
//	{
//		getList(l, i, &letra );
//		printf("%c\n", letra);
//	}	
//
//	return 0;

//Teste para a funcao indexOfList
	/*List *l = initializeList( createList(), sizeof(char), &compare, NULL, NULL );*/
	/*addList( l, "a");*/
	/*addList( l, "b");*/
	/*addList( l, "c");*/
	/*addList( l, "d");*/
	/*addList( l, "e");*/
	/*addList( l, "f");*/
	/*addList( l, "g");*/
	/*addList( l, "h");*/
	/*addList( l, "i");*/

	/*int i=0;*/
	/*char letra;*/
	/*for(; i< sizeList(l) ; i++ )*/
	/*{*/
		/*getList(l, i, &letra );*/
		/*printf("%c\n", letra);*/
	/*}	*/

//	List *l = initializeList( createList(), sizeof(char), &compare, NULL, NULL );
//	addList( l, "a");
//	addList( l, "b");
//	addList( l, "c");
//	addList( l, "d");
//	addList( l, "e");
//	addList( l, "f");
//	addList( l, "g");
//	addList( l, "h");
//	addList( l, "i");
//
//	int i=0;
//	char letra;
//	for(; i< sizeList(l) ; i++ )
//	{
//		getList(l, i, &letra );
//		printf("%c\n", letra);
//	}	
//
//	printf("index of a %d\n", indexOfList(l, "a") );
//	printf("index of f %d\n", indexOfList(l, "f") );
//	printf("index of z %d\n", indexOfList(l, "z") );
//
//	return 0;
}
