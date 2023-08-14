#include <stdlib.h>
//malloc (int)
// free

#include <stdio.h>
//printf

#include "Deque.h"
//typedef struct double_liist *Deque;

void emptyness (Deque *d);
void pushingFront (Deque *d, int x);
void pushingBack (Deque *d, int x);
void poppingFront (Deque *d);
void poppingBack (Deque *d);

main ()
{
	Deque d;

	init_Deque (&d);

	emptyness (&d);

	pushingFront (&d, 1);
	pushingBack (&d, 10);

	pushingFront (&d, 2);
	pushingBack (&d, 20);

	pushingFront (&d, 3);
	pushingBack (&d, 30);

	if (isEmpty_Deque (d))
		printf ("Is Empty\n");
	else
		printf ("No empty\n");

	poppingFront (&d);//poppingFront (&d);poppingFront (&d);poppingFront (&d);poppingFront (&d);poppingFront (&d);
	poppingBack (&d);

	poppingFront (&d);
	poppingBack (&d);

	poppingFront (&d);
	poppingBack (&d);

	emptyness (&d);
}

void emptyness (Deque *d)
{
	int *iptr;

	if (popBack_Deque (d, (void **)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Pop Back\n");

	if (popFront_Deque (d, (void **)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Pop Front\n");

	if (back_Deque ((*d), (void **)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Top Back\n");

	if (front_Deque ((*d), (void **)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Top Front\n");

	if (isEmpty_Deque ((*d)))
		printf ("Is Empty\n");
	else
		printf ("Not Empty\n");
}
void pushingFront (Deque *d, int x)
{
	int *i;
	int *iptr;

	i = (int *) malloc (sizeof (int));
	(*i) = x;
	
	pushFront_Deque (i, d);
	
	if (front_Deque ((*d), (void **)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Top Front\n");
}
void pushingBack (Deque *d, int x)
{
	int *i;
	int *iptr;

	i = (int *) malloc (sizeof (int));
	(*i) = x;
	
	pushBack_Deque (i, d);
	
	if (back_Deque ((*d), (void **)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Top Back\n");
}
void poppingFront (Deque *d)
{
	int *iptr;
	
	if (popFront_Deque (d, (void **)&iptr)==0) {
		printf ("%d\n", (*iptr));
		free (iptr);
	}
	else
		printf ("No Pop Front\n");
}
void poppingBack (Deque *d)
{
	int *iptr;
	
	if (popBack_Deque (d, (void **)&iptr)==0) {
		printf ("%d\n", (*iptr));
		free (iptr);
	}
	else
		printf ("No Pop Back\n");
}
