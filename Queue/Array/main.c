#include <stdio.h>
// printf

#include <stdlib.h>
// malloc
// free

#include "Queue.h"
// typedef struct queue *Queue;

void emptyness (Queue *q);
void enqueueing (Queue *q, int x);
void dequeueing (Queue *q);

main ()
{
	Queue q;
	new_Queue (2, &q);

	init_Queue (&q);

	emptyness (&q);

	enqueueing (&q, 1);
	enqueueing (&q, 2); //dequeueing (&q); enqueueing (&q, 3); dequeueing (&q); dequeueing (&q); dequeueing (&q);
	enqueueing (&q, 3);

	if (isEmpty_Queue ((q)))
		printf ("Is Empty\n");
	else
		printf ("No empty\n");	

	dequeueing (&q);
	dequeueing (&q);
	dequeueing (&q);

	emptyness (&q);
}

void emptyness (Queue *q)
{
	int *iptr;

	if (dequeue_Queue (q, (void **)&iptr))
		printf ("No Dequeue\n");
	if (front_Queue ((*q), (void **)&iptr))
		printf ("No Front\n");
	if (isEmpty_Queue ((*q)))
		printf ("Is Empty\n");
}

void enqueueing (Queue *q, int x)
{
	int *i;
	int *iptr;

	i = malloc (sizeof (int));
	(*i) = x;
	enqueue_Queue (i, q);
	if (front_Queue ((*q), (void **)&iptr))
		printf ("No Front\n");
	else
		printf ("%d\n", (*iptr));
}

void dequeueing (Queue *q)
{
	int *iptr;
	
	if (dequeue_Queue (q, (void **)&iptr))
		printf ("No Dequeue\n");
	else {
		printf ("%d\n", (*iptr));
		free (iptr);
	}
}
