#include "list.h"

//cria um node novo
//ATENCAO:
//newNode(NULL,0) retorna um Node* com data* para um endereco de memoria de tamanho "0". Node->data != NULL !!!
//
Node* newNode( void* e, unsigned long int sizeOfData )
{
	Node* node = malloc( sizeof(Node) );

	node->previous = NULL;
	node->next = NULL;

	if( sizeOfData )
	{
		node->data = malloc( sizeOfData );
		memcpy( node->data, e, sizeOfData );
	}
	else
	{
		node->data = NULL;
	}
	
	return node;
}

//cria a lista
List* createList()
{
	return (List*) malloc( sizeof(List) );
}

//inicializa a lista
List *initializeList ( List *l, unsigned long int sizeOfType, int(*compare)(void*,void*), void(*printData)(void*), void(*removeData)(void*) )
{
	l->sentinela = newNode(NULL,0);
	l->sentinela->next = l->sentinela;
	l->sentinela->previous = l->sentinela;

	l->size = 0;
	l->sizeOfType = sizeOfType;

	l->printData = printData;
	l->compare = compare;
	l->removeData = removeData;

	return l;
}

//adiciona E no comeco da lista
int addList ( List * l, void* e )
{
	Node* node = newNode( e, l->sizeOfType );

	node->previous = l->sentinela;
	node->next = l->sentinela->next;

	l->sentinela->next->previous = node;
	l->sentinela->next = node;

	l->size ++;
	
	return 1;
}

//escreve no elemento INDEX da lista, o elemento E
int addIndexList ( List * l, int index, void* e)
{
	if( index < 0 )
	{
		return 0;
	}

	//inserindo no final da lista
	if( index > l->size )
	{
		Node* node = newNode( e, l->sizeOfType );
		node->next = l->sentinela;
		node->previous = l->sentinela->previous;

		l->sentinela->previous->next = node;
		l->sentinela->previous = node;

		l->size ++;
		return 2;
	}
	else
	{
		Node* n = l->sentinela;
		Node* tmp = l->sentinela;

		for(; index; index-- )
		{
			n = n->next;
		}
		l->sentinela = n;
		addList( l, e );

		l->sentinela = tmp;
	}

	return 1;
}

//remove o elemento correspondente ao index dado
int removeList ( List * l, int index, void* e )
{
	if( index < 0 || index > l->size || !l->size )
		return 0;

	Node* node = l->sentinela->next;
	for( ; index > 0; index-- )
	{
		node = node->next;
	}

	memcpy( e, node->data, l->sizeOfType );

	if( l->removeData )
		l->removeData( node->data );

	removeNode( node );

	l->size --;

	return 1;
}

//remove um node 
void removeNode( Node* node )
{
	Node* prev = node->previous;
	Node* next = node->next;

	prev->next = next;
	next->previous = prev;

	free(node->data);
	free(node);
}

//remove o elemento E da lista
int removeElementList ( List * l, void* e)
{
	if( !l->compare )
	{
		printf("Funcao de comparar nao definida. Retornando -2, nenhum elemento removido\n");
		return -2;
	}

	Node* node = l->sentinela->next;
	int index = 0;

	//varre a lista procurando pelo node com o mesmo dado
	while( node->data != NULL )
	{
		if( l->compare(e, node->data ) )
			break;
		node = node->next;
		index ++;
	}

	//se, depos de varrer, node apontar para sentinela, entao nao existe um node com o dado passado.
	if( node->data == NULL )
		return -1;
	
	removeNode( node );
	l->size --;	
	return index;
}

//escreve em E o elemento INDEX da lista
int getList ( List * l, int index, void* e)
{
	if( index < 0 || index > l->size || !l->size)
		return 0;

	Node* node = l->sentinela->next;

	for(; index > 0; index-- ){
		node = node->next;
	}

	memcpy( e, node->data, l->sizeOfType );
	return 1;
}

//retorna o index do elemento E
int indexOfList ( List * l, void* e)
{
	if( !l->compare )
	{
		printf("Funcao de comparar nao definida. Retornando -2, nenhum elemento procurado\n");
		return -2;
	}

	int index = 0;
	Node* node = l->sentinela->next;

	while( node->data != NULL )
	{
		if( l->compare(e, node->data) )
			break;
		
		node = node->next;	
		index++;
	}

	//elemento nao encontrado
	if( node->data == NULL )
		return -1;

	return index;	
}

//retorna o tamanho da lista
int sizeList ( List * l)
{
	return l->size;
}

//escreve a lista na tela
int printList ( List * l)
{
	if( !l->printData )
	{
		printf("Funcao de imprimir nao definida. Retornando -2, nenhum elemento escrito na tela\n");
		return -2;
	}

	Node* node = l->sentinela->next;
	while( node->data != NULL )
	{
		l->printData( node->data );
		node = node->next;
	}

	return 0;
}

