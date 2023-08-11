#include <stdio.h>
// printf

#include <stdlib.h>
//malloc (int)

#include "Stack.h"
//typedef List Stack;

void emptyness (Stack *s);
void pushing (Stack *s, int x);
void popping (Stack *s);

main ()
{	
	Stack s;
	init_Stack (&s);
	
	emptyness (&s);

	pushing (&s, 1);
	pushing (&s, 2);
	pushing (&s, 3);

	if (isEmpty_Stack (s))
		printf ("Is Empty\n");
	else
		printf ("No Empty\n");
	
	popping (&s);
	popping (&s);
	popping (&s);

	emptyness (&s);
}

void emptyness (Stack *s)
{
	int *iptr;

	if (pop_Stack (s, (void **)&iptr))
		printf ("No Pop\n");
	if (top_Stack ((*s), (void **)&iptr))
		printf ("No Top\n");
	if (isEmpty_Stack ((*s)))
		printf ("Is Empty\n");
}

void pushing (Stack *s, int x)
{
	int *i;
	int *iptr;

	i = malloc (sizeof (int));
	(*i) = x;
	push_Stack (i, s);
	if (top_Stack ((*s), (void **)&iptr))
		printf ("No Top\n");
	else
		printf ("%d\n", (*iptr));

}

void popping (Stack *s)
{
	int *iptr;
	
	if (pop_Stack (s, (void **)&iptr))
		printf ("No Pop\n");
	else {
		printf ("%d\n", (*iptr));
		free (iptr);
	}
}