#ifndef LISTA_DUPLAMENTE_ENCADEADA_HECTOR
#define LISTA_DUPLAMENTE_ENCADEADA_HECTOR

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
	struct node *next;
	struct node *previous;
	void* data;
}Node;

typedef struct{
	Node* sentinela;
	int size;
	unsigned long int sizeOfType;

	void (*printData)(void*);
	void (*removeData)(void*);
	int (*compare)(void*,void*);
}List;

//cria um node novo
//
//parametros:
//void* e : ponteiro para o dado que sera copiado para o node
//unsigned long int sizeOfData: tamanho em bytes do dado Utilize sizeof( <inserir dado aqui> ) !
//
//retorna: Um ponteiro de node com os seguintes parametros
//node* next = NULL;
//node* previous = NULL;
//void data = um ponteiro para uma nova posicao de memoria que tem o mesmo conteudo que *e 
//
//ATENCAO:
//newNode(NULL,0) retorna um Node* com data* para um endereco de memoria de tamanho "0".Assim,  Node->data != NULL !!!
Node* newNode( void* e, unsigned long int sizeOfData );

//cria a lista
//retorna: um ponteiro de lista nao inicializada (com lixo de memoria)
List* createList();

//inicializa a lista
//
//parametros:
//List* l : ponteiro da lista que sera inicializada
//unsigned long int sizeOfType : tamanho do tipo do dado 
//		utilize o sizeof !  sizeof( <inserir o tipo aqui> )
//int(compare*)(void*,void*) : endereco de funcao que compare os dois elementos da lista e retorne 1 se os dois parametros forem iguais e 0 se forem diferentes
//		Se for NULL a funcao nao e executada
//void(*printData)(void*) : endereco de uma funcao que imprima o conteudo do dado guardado no node
//		Se for NULL a funcao nao e executada
//void(*removeData)(void*) : endereco de uma funcao que remova o dado guardado no node
//		Se for NULL, a funcao nao e executada
//
//retorna: o ponteiro da lista inicializada
//Uma lista incializada tem os seguintes parametros
//Node* sentinela->next = &sentinela(proprio endereco)
//Node* sentinela->previous = &sentinela(proprio endereco)
//int size = 0;
//unsigned sizeOfType = tamanho do tipo de dado guardado
//int(compare*)(void*,void*) = endereco de funcao que compare os dois elementos da lista e retorne 1 se os dois parametros forem iguais e 0 se forem diferentes
//void(*printData)(void*) = endereco de uma funcao que imprima o conteudo do dado guardado no node
//void(*removeData)(void*) = endereco de uma funcao que remova o dado guardado no node
List *initializeList ( List *l, unsigned long int sizeOfType, int(*compare)(void*,void*), void(*printData)(void*), void(*removeData)(void*));

//adiciona E no comeco da lista
//
//parametros:
//List* l: lista a ser alterada
//void* e: endereco do ponteiro que contem o conteudo
//
//retorna: 
//1 se foi possivel adicionar na lista
//0 se nao foi possivel adicionar na lista (Tem como isso acontecer ?)
int addList ( List * l, void* e );

//escreve no elemento INDEX da lista, o elemento E
//
//parametros:
//List* l: 		lista a ser modificada
//void* e: 		elemento a ser incluido na lista
//int index:	posicao da lista no qual sera inserido o elemento
//
//retorna:
//0 se o index nao estiver no intervalo (fora da lista)
//1 se o elemento foi inserido no lugar certo.
//2 se o elemento foi inserido no final da insta( index > intervalo da lista )
int addIndexList ( List * l, int index, void* e);

//remove o elemento correspondente ao index dado
//
//parametros:
//List* l: 		lista a ser modificada
//int index: 	indice do elemento que sera retirado
//void* e:		endereco onde sera escrito o elemento removido ( isso implica que uma variavel do mesmo tipo seja instanciado antes ) 
//
//exemplo:
//char letra;
//removeList( L, 10, &letra );
//
//retorna
//	0 se o index nao for acessivel (fora do intervalo). o valo de E nao e alterado
//	1 se a remocao foi concluida e E contem valor do elemento deletado
int removeList ( List * l, int index, void* e );

//remove o elemento E da lista
//
//parametros:
//List* l: 		lista a ser modificada
//void* e: 		endereco do struct que sera removido 
//
//retorna:
//-2 se a funcao de comparar for nula
//-1 se o elemento nao foi encontrado 
//index do elemento que foi removido( lembre-se, pode ser 0 !)
int removeElementList ( List * l, void* e);

//escreve em E o elemento INDEX da lista
//
//parametros:
//List* l: 		lista a ser verificada
//void* e: 		endereco do struct que sera escrito o elemento
//
//retorna:
//0 se o index nao for acessivel. E aponta para null
//1 se o index foi acessado
int getList ( List * l, int index, void* e);

//retorna o index do elemento E
//
//parametros:
//List* l: 		lista a ser verificada
//void* e: 		elemento a ser encontrado na lista
//
//retorna:
//-2 se a funcao de comparar nao estiver definda
//-1 se o elemento nao foi encontrado
//o indice do elemento E
int indexOfList ( List * l, void* e);

//retorna o tamanho da lista
//
//parametros:
//List* l: 		lista a ser verificada
//
//retorna:
//-1 se nao houver lista ( se List for NULL  )
//quantidade de elementos na lista ( 0 e um valor valido )
int sizeList ( List * l);

//escreve a lista na tela
//
//parametros:
//List* l: 		lista a ser escrita
//
//retorna:
//-2 se a funcao printData nao for definida
int printList ( List * l);

//remove um node 
//(uso interno, nao verifica o parametro.Para remover um elemento da lista, utilize as funcoes removeList e removeElementList )
//
//parametros:
//Node* n:		endereco do node que sera removido
//
//retorna:
//...nada ( eu disse que era de uso interno ! )
void removeNode( Node* node );
#endif
