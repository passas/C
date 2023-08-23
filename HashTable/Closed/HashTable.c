#include <stdlib.h>
//malloc
//free

#include "HashTable.h"
//typedef struct hash_table *HashTable;

typedef struct bucket
{
	void *key;
	void *data;
	struct bucket *next;
} *Bucket;

struct hash_table
{
	int size;
	int capacity;
	float factor;
	
	Bucket *table;

	int (*hash) (void *);
	int (*equals) (void *, void *);
};

int new_HashTable (int capacity, float factor, int (*hash) (void *), int (*equals) (void *, void *), HashTable *ht)
{
	int error;
	HashTable r;

	error = 0;
	r = (HashTable) malloc (sizeof (struct hash_table));
	if (r)
	{
		r->table = (Bucket *) malloc (sizeof (struct bucket) * capacity);
		if (r->table)
		{
			for (int i=0; i<capacity; i++)
				r->table[i] = NULL;
			r->size = 0;
			r->capacity = capacity;
			r->factor = factor;
			r->hash = hash;
			r->equals = equals;

			(*ht) = r;
		}
		else
		{
			free (r);
			error = 1;
			(*ht) = NULL;
		}
	}
	else
	{
		error = 1;
		(*ht) = NULL;
	}

	return error;
}

static int _dup_HashTable (HashTable *ht)
{
	int error;
	HashTable aux;
	Bucket tmp;
	int h;

	error = new_HashTable ((*ht)->capacity * 2, (*ht)->factor, (*ht)->hash, (*ht)->equals, &aux);
	if (!error)
	{	
		for (int i=0; i<(*ht)->size; i++)
		{	//or create new Bucket's, control errors, and N^2 to free the old ones
			//or not control errors
			//or reuse Bucket's and control errors
			tmp = NULL;
			for (Bucket it=(*ht)->table[i]; it; it=it->next)
			{
				if (tmp) {
					free (tmp);
					tmp = NULL;
				}
				put_HashTable (it->key, it->data, &aux);
				tmp = it;
			}
		}

		free ( (*ht)->table );
		free ( (*ht) );
		(*ht) = aux;
	}
	else
	{
		error = 1;
	}

	return error;
}
static int _push_Bucket (void *k, void *d, Bucket *b)
{
	int error;
	Bucket aux;

	error = 0;
	aux = (Bucket) malloc (sizeof (struct bucket));
	if (aux)
	{
		aux->key = k;
		aux->data = d;
		aux->next = (*b);

		(*b) = aux;
	}
	else
	{
		error = 1;
	}

	return error;
}
int put_HashTable (void *key, void *data, HashTable *ht)
{
	int error;
	int h;
	float load;
	Bucket it;
	
	error = 0;

	// Dup?
	load = (float) ((*ht)->size / (*ht)->capacity);
	if (load >= (*ht)->factor)
	{
		error = _dup_HashTable (ht);
		if (error)
			return error;
	}

	// Either way
	h = ((*ht)->hash (key)) % (*ht)->capacity;

	// Update data
	for (it = (*ht)->table[h]; it; it = it->next)
	{
		if ( (*ht)->equals (key, it->key) == 0 )
		{
			it->data = data;
			error = -1;
			break;
		}
	}

	// New data
	if (it == NULL)
	{
		error = _push_Bucket (key, data, &((*ht)->table[h]));
		(*ht)->size++;
	}

	return error;
}

int get_HashTable (void *key, HashTable ht, void **x)
{
	int error;
	int h;
	Bucket it;

	error = 0;

	h = (ht->hash (key)) % ht->capacity;

	for (it=ht->table[h]; it && ht->equals(it->key, key) == 0; it = it->next);
	if (it)
	{
		(*x) = it->data;
	}
	else
	{
		error = -1;
		(*x) = NULL;
	}

	return error;
}

int remove_HashTable (void *key, HashTable *ht, void **x)
{
	int error;
	int h;
	Bucket *it, tmp;

	error = 0;

	h = ((*ht)->hash (key)) % (*ht)->capacity;

	for (it=&((*ht)->table[h]); (*it) && (*ht)->equals((*it)->key, key) == 0; it = &((*it)->next));

	if ((*it))
	{
		(*x) = (*it)->data;

		tmp = (*it);
		(*it) = (*it)->next;
		free (tmp);

		(*ht)->size--;
	}
	else
	{
		error = -1;
		(*x) = NULL;
	}

	return error;
}

void free_HashTable (HashTable *ht)
{
	Bucket ant, it;

	for (int i=0; i<(*ht)->size; i++)
	{
		ant = NULL;
		for (it=(*ht)->table[i]; it; it->next)
		{
			if (ant)
			{
				free (ant);
				ant = NULL;
			}
			ant = it;
		}
	}

	free ( (*ht)->table );
	free (*ht);
}
