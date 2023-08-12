#include <stdlib.h>
// malloc
// free

#include "Queue.h"
// typedef struct queue Queue; 

typedef struct list {
	void *data;
	struct list *next;
} *List;

struct queue {
	List first, last;
};

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

int new_Queue (Queue *q)
{
	int error;
	Queue r;

	error = 0;
	r = (Queue) malloc (sizeof (struct queue));
	if (r==NULL)
		error = 1;
	else 
		(*q) = r;
}

void init_Queue (Queue *q)
{
	(*q)->first = (*q)->last = NULL;
}

int isEmpty_Queue (Queue q)
{
	return !(q->first && q->last);
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
		(*q)->first = (*q)->last = aux;
	}
	else {
		(*q)->last->next = aux;
		(*q)->last = aux;
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
	
	else if ((*q)->first == (*q)->last) {	//1 element left
		aux = (*q)->first;

		aux->next = NULL;
		(*x) = aux->data;
		free (aux);

		init_Queue (q);
	}
	
	else {
		aux = (*q)->first;

		(*q)->first = (*q)->first->next;

		aux->next = NULL;
		(*x) = aux->data;
		free (aux);
	}
}

int front_Queue (Queue q, void **x)
{
	int error;
	
	error = 0;
	if ( isEmpty_Queue (q) )
		error = 2;
	else
		(*x) = q->first->data;

	return error;
}