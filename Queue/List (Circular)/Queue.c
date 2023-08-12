#include <stdlib.h>
// malloc
// free

#include "Queue.h"
// typedef struct list *Queue; 

typedef struct list {
	void *data;
	struct list *next;
} *List;

static List _new_List (void *data, List l)
{
	List aux;
	aux = (List) malloc (sizeof (struct list));
	if (aux != NULL) {
		aux->data = data;
		aux->next = l;
	}

	return aux;
}


void init_Queue (Queue *q)
{
	(*q) = NULL;
}

int isEmpty_Queue (Queue q)
{
	return !(q);
}

int enqueue_Queue (void *data, Queue *q)
{
	int error;
	List aux;

	error = 0;
	aux = _new_List (data, NULL);
	if (aux==NULL) {
		error = 1;
	}
	
	else if ( isEmpty_Queue (*q) ) {	//1st element
		aux->next = aux;
		
		(*q) = aux;
	}
	else {
		aux->next = (*q)->next;	//point to 1st element
		(*q)->next = aux;		//embrace the new element

		(*q) = aux;				//be the queue
	}

	return error;
}

int dequeue_Queue (Queue *q, void **x)
{
	int error;
	List aux;

	error = 0;

	if ( isEmpty_Queue (*q) ) {
		error = 2;
	}
	else if ( (*q)->next == (*q)  ) {	//1 element left
		aux = (*q)->next;

		aux->next = NULL;
		(*x) = aux->data;
		free (aux);

		init_Queue (q);
	}
	else {
		aux = (*q)->next;				//1st element

		(*q)->next = (*q)->next->next;	//after the 1st

		aux->next = NULL;
		(*x) = aux->data;
		free (aux);
	}

	return error;
}

int front_Queue (Queue q, void **x)
{
	int error;
	
	error = 0;
	if ( isEmpty_Queue (q) )
		error = 2;
	else
		(*x) = q->next->data;	//1st element

	return error;
}