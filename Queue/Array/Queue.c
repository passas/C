#include <stdlib.h>
// malloc
// free

#include "Queue.h"
// typedef struct queue *Queue;

struct queue {
	int front;
	int length;
	int size;
	void **queue;
};

int new_Queue (int size, Queue *q)
{
	int error;
	Queue r;

	error = 0;
	r = (Queue) malloc (sizeof (struct queue));
	if (r!=NULL)
	{
		r->queue = malloc (sizeof (void *) * size);
		if (r->queue!=NULL)
		{
			r->front = 0;
			r->length = 0;
			r->size = size;
		}
		else
		{
			error = 1;
			free (r);
			(*q) = NULL;
		}
		(*q) = r;
	}
	else
	{
		error = 1;
		(*q) = NULL;
	}
	return error;
}

void init_Queue (Queue *q)
{
	(*q)->front = (*q)->length = 0;
}

int isEmpty_Queue (Queue q)
{
	return !(q->length);
}

int enqueue_Queue (void *data, Queue *q)
{
	Queue aux;
	int error;
	int pos;

	error = 0;
	if ((*q)->length == (*q)->size)
	{	//dup
		error = new_Queue ((*q)->size * 2, &aux);
		if (error == 0)
		{
			for (int i=0; i<(*q)->size; i++) {
				pos = ( (*q)->front + i ) % (*q)->size;
				enqueue_Queue ((*q)->queue[pos], &aux);
			}
			(*q) = aux;
		}
	}
	
	if (!error)	//enqueue
	{
		pos = ( (*q)->front + (*q)->length ) % (*q)->size;
		(*q)->queue [ pos ] = data;
		(*q)->length++;
	}

	return error;
}

int dequeue_Queue (Queue *q, void **x)
{
	int error;

	error = 0;
	if ( !isEmpty_Queue((*q)) ) //not empty
	{
		(*x) = (*q)->queue [ (*q)->front ];
		(*q)->front = ( (*q)->front + 1 ) % (*q)->size;
		(*q)->length--;
	}
	else
	{
		error = 2;
	}

	return error;
}

int front_Queue (Queue q, void **x)
{
	int error;

	error = 0;
	if ( !isEmpty_Queue((q)) ) //not empty
	{
		(*x) = (q)->queue [ (q)->front ];
	}
	else
	{
		error = 2;
	}

	return error;
}
