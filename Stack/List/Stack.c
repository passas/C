#include <stdlib.h>
// malloc
// free

#include "Stack.h"
// typedef List Stack;

typedef struct list {
	void *data;
	struct list *next;
} *List;

static List _new_List (void *data, List l)
{
	List aux;
	aux = (List) malloc (sizeof (struct list));
	if (aux!=NULL) {
		aux->data = data;
		aux->next = l;
	}
	return aux;
}

void init_Stack (Stack *s)
{
	(*s) = NULL;
}

int isEmpty_Stack (Stack s)
{
	return !s;
}

int push_Stack (void *data, Stack *s)
{
	int error;
	List aux;

	error = 0;	
	aux = _new_List (data, (*s));
	
	if (aux==NULL)
		error = 1;
	else
		(*s) = aux;

	return error;
}

int pop_Stack (Stack *s, void **x)
{
	int error;
	List tmp;

	error = 0;
	if (isEmpty_Stack (*s))
		error = 2;
	else {
		tmp = (*s);
		(*s) = (*s)->next;

		tmp->next = NULL;
		(*x) = tmp->data;
		free (tmp);
	}

	return error;
}

int top_Stack (Stack s, void **x)
{
	int error;

	error = 0;
	if (isEmpty_Stack (s))
		error = 2;
	else
		(*x) = s->data;

	return error;
}