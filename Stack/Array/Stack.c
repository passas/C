#include <stdlib.h>
// malloc
// free

#include "Stack.h"
// typedef struct stack *Stack;

struct stack {
	int sp;
	int size;
	void **stack;
};

int new_Stack (int size, Stack *s)
{
	int error;
	Stack r;

	error = 0;

	r = (Stack) malloc (sizeof (struct stack));
	if (r!=NULL)
	{
		r->stack = (void **) malloc (sizeof (void *) * size);
		r->size = size;
		r->sp = 0;
			
		if (r->stack != NULL)
		{
			(*s) = r; //job done.
		}
		else
		{
			error = 1;
			free (r);
		}
	}
	else
	{
		error = 1;
	}

	return error;
}

void init_Stack (Stack *s)
{
	(*s)->sp = 0;
}

int isEmpty_Stack (Stack s)
{
	return !(s->sp);
}

int push_Stack (void *data, Stack *s)
{
	Stack aux;
	int error;

	error = 0;
	if ((*s)->sp == (*s)->size) {	//full
		//dup
		error = new_Stack ((*s)->size * 2, &aux);
		if (error == 0)
		{
			for (int i=0; i<(*s)->size; i++)
				push_Stack ((*s)->stack[i], &aux);

			free ( (*s) );
			(*s) = aux;
		}
	}

	if (error == 0)
		(*s)->stack [(*s)->sp++] = data;

	return error;
}

int pop_Stack (Stack *s, void **x)
{
	int error;

	error = 0;
	if (isEmpty_Stack(*s) == 0)
	{
		(*s)->sp--;
		(*x) = (*s)->stack[ (*s)->sp ];
	}
	else
	{
		error = 2;
	}

	return error;
}

int top_Stack (Stack *s, void **x)
{
	int error;

	error = 0;
	if (isEmpty_Stack(*s) == 0)
	{
		(*x) = (*s)->stack[ (*s)->sp - 1 ];
	}
	else
	{
		error = 2;
	}
	
	return error;
}
