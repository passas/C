#include <stdio.h>
//printf

#include <stdlib.h>
//malloc
//free

#include "PriorityQueue.h"
//typedef strucct priority_queue *PriorityQueue;

void emptyness (PriorityQueue *q);
void pushing (PriorityQueue *q, int x, int priority);
void popping (PriorityQueue *q);

main ()
{
	PriorityQueue q;
	new_PriorityQueue (1, &q);

	init_PriorityQueue (&q);

	emptyness (&q);

	pushing (&q, 1, 6);
	pushing (&q, 2, 5);
	pushing (&q, 3, 4);
	//pushing (&q, 4, 3);
	//pushing (&q, 5, 2);
	//pushing (&q, 6, 1);


	if (isEmpty_PriorityQueue (q))
		printf ("Empty\n");
	else
		printf ("Not Empty\n");

	popping (&q);
	popping (&q);
	popping (&q);
	//popping (&q);
	//popping (&q);
	//popping (&q);

	emptyness (&q);

	free_PriorityQueue (&q);
}

void emptyness (PriorityQueue *q)
{
	int *iptr;

	if (dequeue_PriorityQueue (q, (void**)&iptr) == 0)
		printf ("Dequeue\n");
	else
		printf ("No Dequeue\n");
	if (front_PriorityQueue (q, (void**)&iptr) == 0)
		printf ("Front\n");
	else
		printf ("No Front\n");
	if (isEmpty_PriorityQueue (*q))
		printf ("Empty\n");
	else
		printf ("Not Empty\n");
}
void pushing (PriorityQueue *q, int x, int priority)
{
	int *i;
	int *iptr;

	i = malloc (sizeof (int));
	(*i) = x;

	if (enqueue_PriorityQueue (priority, i, q)==0)
	{
		if (front_PriorityQueue (q, (void**)&iptr) == 0)
			printf ("%d\n", (*iptr));
		else
			printf ("No Front\n");
	}
	else 
	{
		printf ("No Enqueue\n");
	}
}

void popping (PriorityQueue *q)
{
	int *iptr;
	if (dequeue_PriorityQueue (q, (void**)&iptr) == 0)
	{
		printf ("%d\n", (*iptr));
		//free (iptr);
	}
	else
		printf ("No Dequeue\n");
}
