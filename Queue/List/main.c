#include <stdlib.h>
// malloc (int)
// free

#include <stdio.h>
// printf

#include "Queue.h"
//typedef struct queue *Queue;

void emptyness (Queue *);
void enqueing (Queue *, int x);
void dequeing (Queue *);

main ()
{
	Queue q;
	new_Queue (&q);

	init_Queue (&q);

	emptyness (&q);

	enqueing (&q, 1);
	enqueing (&q, 2);
	enqueing (&q, 3);

	if (isEmpty_Queue(q))
		printf("Is Empty\n");
	else
		printf("Not Empty\n");

	dequeing (&q);
	dequeing (&q);
	dequeing (&q);

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

void enqueing (Queue *q, int x)
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

void dequeing (Queue *q)
{
	int *iptr;
	
	if (dequeue_Queue (q, (void **)&iptr))
		printf ("No Dequeue\n");
	else {
		printf ("%d\n", (*iptr));
		free (iptr);
	}
}
