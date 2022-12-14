#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct
{
	void* pElement; //elemento del nodo
	struct Node* pNextNode; //enlace a proximo nodo, contiene la direc de memoria del sig nodo
}Node; //nodo

typedef struct
{
	Node* pFirstNode; //puntero a primer nodo
	int size; // tam de la linkedList
}LinkedList;

#endif /* LINKEDLIST_H_ */


int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
Node* test_getNode(LinkedList* this, int nodeIndex);

LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList *this, int index);
int ll_clear(LinkedList *this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList *this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
LinkedList* ll_filter(LinkedList* this, int (*fn)(void*));
LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void* element));
int ll_count(LinkedList* this, int (*fn)(void*));
