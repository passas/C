#include <stdlib.h>
//malloc
//free

#include "PriorityQueue.h"
//typedef strucct priority_queue *PriorityQueue;

typedef struct element
{
	int priority;
	void *data;
} Element;

struct priority_queue
{
	int length;
	int size;
	Element *queue;
};

static void _swap (Element q[], int i1, int i2);
static void _bubbleUp (Element q[], int down);
static void _bubbleDown (Element q[], int up, int length);

int new_PriorityQueue (int size, PriorityQueue *q)
{
	int error;
	PriorityQueue r;

	error = 0;
	r = (PriorityQueue) malloc (sizeof (struct priority_queue));
	if (r!=NULL)
	{
		r->queue = (struct element *) malloc (sizeof (struct element) * size);
		if (r->queue!=NULL)
		{
			r->length = 0;
			r->size = size;

			(*q) = r;
		}
		else
		{
			free (r);
			error = 1;
		}
	}
	else
	{
		error = 1;
	}

	return error;
}

void init_PriorityQueue (PriorityQueue *q)
{
	(*q)->length = 0;
}

int isEmpty_PriorityQueue (PriorityQueue q)
{
	return !(q->length);
}

int enqueue_PriorityQueue (int priority, void *data, PriorityQueue *q)
{	
	Element *aux;
	int error;

	error = 0;
	if ((*q)->length == (*q)->size)
	{
		aux = realloc ((*q)->queue, sizeof (struct element) * (*q)->size * 2);

		if (aux != NULL)
		{
			(*q)->size *= 2;
			(*q)->queue = aux;
		}
		else
		{
			error = 1;
		}
	}

	if (!error)
	{
		(*q)->queue [ (*q)->length ].priority = priority;
		(*q)->queue [ (*q)->length ].data = data;

		_bubbleUp ((*q)->queue, (*q)->length);
		(*q)->length++;
	}

	return error;
}

int dequeue_PriorityQueue (PriorityQueue *q, void **x)
{	
	int error;

	error = 0;
	if (! isEmpty_PriorityQueue (*q))
	{
		(*x) = (*q)->queue[0].data; //dequeue
		(*q)->length--;

		_swap ((*q)->queue, 0, (*q)->length);	//element dequeued off
		_bubbleDown ((*q)->queue, 0, (*q)->length);	//re-order
	}
	else
	{
		error = 2;
	}

	return error;
}

int front_PriorityQueue (PriorityQueue *q, void **x)
{	
	int error;

	error = 0;
	if (! isEmpty_PriorityQueue (*q))
	{
		(*x) = (*q)->queue[0].data; //dequeue
	}
	else
	{
		error = 2;
	}

	return error;
}

void free_PriorityQueue (PriorityQueue *q)
{
	free ( (*q)->queue );
	free ( (*q) );
}

// -- Aux's -- //

static void _swap (Element q[], int i1, int i2)
{
	Element aux;
	aux.priority = q[i1].priority;
	aux.data = q[i1].data;

	q[i1].priority = q[i2].priority;
	q[i1].data = q[i2].data;

	q[i2].priority = aux.priority;
	q[i2].data = aux.data;
}

static void _bubbleUp (Element q[], int down)
{
	int up;

	up = (down - 1) / 2; //father / up-node
	while (down > 0 && q[up].priority > q[down].priority)
	{
		_swap (q, up, down);
		down = up;
		up = (down - 1) / 2;
	}
}

static void _bubbleDown (Element q[], int up, int length)
{
	int down;

	down = (up * 2) + 1; //left-child
	while ( down < length )
	{
		if ( (down + 1) < length && q[down].priority > q[down+1].priority)
			down = down + 1; //right-child

		if ( q[down].priority > q[up].priority )
			break;

		_swap (q, up, down);
		up = down;
		down = (up * 2) + 1;
	}
}
