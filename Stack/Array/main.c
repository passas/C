#include <stdio.h>
//printf

#include <stdlib.h>
//malloc(int)
//free

#include "Stack.h"
// typedef struct stack *Stack;

void emptyness (Stack *s);
void pushing (Stack *s, int x);
void popping (Stack *s);

main ()
{
	Stack s;
	new_Stack (1, &s);

	init_Stack (&s);

	emptyness (&s);

	pushing (&s, 1);
	pushing (&s, 2);
	pushing (&s, 3);

	if (isEmpty_Stack (s))
		printf ("Is Empty\n");
	else
		printf ("Not Empty\n");

	popping (&s);
	popping (&s);
	popping (&s);

	emptyness(&s);
}

void emptyness (Stack *s)
{
	int *iptr;

	if (pop_Stack (s, (void**)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Pop\n");
	
	if (top_Stack (s, (void**)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Top\n");
	
	if ( isEmpty_Stack ((*s)) )
		printf ("Is Empty\n");
	else
		printf ("Not Empty\n");

}
void pushing (Stack *s, int x)
{
	int *i;
	int *iptr;

	i = (int *) malloc (sizeof (int));
	(*i) = x;

	push_Stack (i, s);

	if (top_Stack (s, (void**)&iptr)==0)
		printf ("%d\n", (*iptr));
	else
		printf ("No Top\n");
}

void popping (Stack *s)
{
	int *iptr;

	if (pop_Stack (s, (void**)&iptr)==0) {
		printf ("%d\n", (*iptr));
		free (iptr);
	}
	else
		printf ("No Pop\n");
}
