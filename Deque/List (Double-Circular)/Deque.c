#include <stdlib.h>
// malloc
// free

#include "Deque.h"
//typedef struct double_list *Deque;

typedef struct double_list {
	void *data;
	struct double_list *prev, *next;
} *DoubleList;

static DoubleList _new_DoubleList (void *data, DoubleList prev, DoubleList next)
{
	DoubleList aux;
	aux = (DoubleList) malloc (sizeof (struct double_list));
	if (aux) {
		aux->data = data;
		aux->prev = prev;
		aux->next = next;
	}

	return aux;
}

void init_Deque (Deque *d)
{
	(*d) = NULL;
}

int isEmpty_Deque (Deque d)
{
	return !(d);
}

int pushBack_Deque (void *data, Deque *d)
{
	int error;
	DoubleList aux;

	error = 0;
	aux = _new_DoubleList (data, NULL, NULL);
	if (aux == NULL) {
		error = 1;
	}
	else if (isEmpty_Deque (*d))	//1st element
	{
		aux->prev = aux->next = aux;
		(*d) = aux;
	}
	else
	{
		aux->next = (*d)->next;
		aux->prev = (*d);
		(*d)->next = aux;
		(*d) = aux;
	}

	return error;
}

int pushFront_Deque (void *data, Deque *d)
{
	int error;
	DoubleList aux;

	error = 0;
	aux = _new_DoubleList (data, NULL, NULL);
	if (aux == NULL) {
		error = 1;
	}
	else if (isEmpty_Deque (*d))	//1st element
	{
		aux->prev = aux->next = aux;
		(*d) = aux;
	}
	else
	{
		aux->prev = (*d);
		aux->next = (*d)->next;
		(*d)->next->prev = aux;
		(*d)->next = aux;
	}

	return error;
}

int popBack_Deque (Deque *d, void **x)
{
	int error;
	DoubleList tmp;

	error = 0;
	if (isEmpty_Deque (*d))
	{
		error = 2;
	}
	else if ( (*d) == (*d)->next ) //1 element left
	{
		tmp = (*d)->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		(*x) = tmp->data;

		free (tmp);

		init_Deque (d);
	}
	else
	{
		tmp = (*d);

		(*d)->prev->next = (*d)->next;
		(*d)->next->prev = (*d)->prev;
		(*d) = (*d)->prev;

		tmp->next = NULL;
		tmp->prev = NULL;
		(*x) = tmp->data;
		free (tmp);
	}

	return error;
}

int popFront_Deque (Deque *d, void **x)
{
	int error;
	DoubleList tmp;

	error = 0;
	if (isEmpty_Deque (*d)) {
		error = 2;
	}
	else if ( (*d)->next == (*d) ) //1 element left
	{
		tmp = (*d)->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		(*x) = tmp->data;

		free (tmp);

		init_Deque (d);
	}
	else
	{
		tmp = (*d)->next;

		(*d)->next->next->prev = (*d);
		(*d)->next = (*d)->next->next;		

		tmp->prev = NULL;
		tmp->next = NULL;
		(*x) = tmp->data;
		free (tmp);
	}

	return error;
}

int back_Deque (Deque d, void **x)
{
	int error;

	error = 0;
	if (isEmpty_Deque (d))
		error = 2;
	else
		(*x) = d->data;

	return error;
}

int front_Deque (Deque d, void **x)
{
	int error;

	error = 0;
	if (isEmpty_Deque (d))
		error = 2;
	else
		(*x) = d->next->data;

	return error;
}
