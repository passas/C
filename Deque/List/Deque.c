#include <stdlib.h>
// malloc
// free

#include "Deque.h"
//typedef struct deque *Deque;

typedef struct double_list {
	void *data;
	struct double_list *prev, *next;
} *DoubleList;

struct deque {
	DoubleList back, front;
};

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

int new_Deque (Deque *d)
{
	int error;
	Deque r;

	error = 0;
	r = (Deque) malloc (sizeof (struct deque));
	if (r == NULL)
		error = 1;
	else
		(*d) = r;

	return error;
}

void init_Deque (Deque *d)
{
	(*d)->back = (*d)->front = NULL;
}

int isEmpty_Deque (Deque d)
{
	return !(d->front && d->back);
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
	else if (isEmpty_Deque (*d))
	{
		(*d)->back = (*d)->front = aux;
	}
	else
	{
		(*d)->back->prev = aux;
		aux->next = (*d)->back;
		(*d)->back = aux;
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
	else if (isEmpty_Deque (*d))
	{
		(*d)->back = (*d)->front = aux;
	}
	else
	{
		(*d)->front->next = aux;
		aux->prev = (*d)->front;
		(*d)->front = aux;
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
	else if ( (*d)->back == (*d)->front ) //1 element left
	{
		tmp = (*d)->back;
		tmp->next = NULL;
		(*x) = tmp->data;

		free (tmp);

		init_Deque (d);
	}
	else
	{
		tmp = (*d)->back;

		(*d)->back = (*d)->back->next;

		tmp->next = NULL;
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
	else if ( (*d)->back == (*d)->front ) //1 element left
	{
		tmp = (*d)->front;
		tmp->prev = NULL;
		(*x) = tmp->data;

		free (tmp);

		init_Deque (d);
	}
	else
	{
		tmp = (*d)->front;

		(*d)->front = (*d)->front->prev;

		tmp->prev = NULL;
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
		(*x) = d->back->data;

	return error;
}

int front_Deque (Deque d, void **x)
{
	int error;

	error = 0;
	if (isEmpty_Deque (d))
		error = 2;
	else
		(*x) = d->front->data;

	return error;
}