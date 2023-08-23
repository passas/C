#include <stdio.h>
//printf

#include <stdlib.h>
//malloc
//free

#include <string.h>
//strdup

#include "HashTable.h"
//typedef struct hash_table *HashTable;

int hash (void *v1)
{
	int *i1 = (int *)v1;

	return (*i1); //id
}

int equals (void *v1, void *v2)
{
	int *i1 = (int *) v1;
	int *i2 = (int *) v2;

	return ((*i1) == (*i2));
}

void _put (int k, char *data, HashTable *ht);
void _get (int k, HashTable ht);
void _remove (int k, HashTable *ht);

main ()
{
	HashTable ht;
	//_put (1, "Ana", &ht);
	
	new_HashTable (4, 6, hash, equals, &ht);

	_put (1, "Ana", &ht);
	_put (2, "Bob", &ht);
	_put (3, "Cynthia", &ht);
	_put (4, "Dalila", &ht);
	_put (5, "Ed", &ht);
	_put (6, "Fiona", &ht);
	_put (7, "Gustaf", &ht);
	_put (8, "Henry", &ht);
	_put (9, "Inna", &ht);
	_put (10, "Julian", &ht);
	_put (11, "Kurt", &ht);
	_put (12, "Louis", &ht);
	_put (13, "Michael", &ht);
	_put (14, "Nicole", &ht);
	_put (15, "Orpheu", &ht);
	_put (16, "Peter", &ht);
	_put (17, "Quark", &ht);
	_put (18, "Xavier", &ht);
	_put (19, "Yuan", &ht);
	_put (20, "Waldo", &ht);
	_put (21, "Zac", &ht);

	putchar ('\n');
	for (int i=0; i<22; i++)
	{
		_get (i, ht);
	}

	putchar ('\n');
	for (int i=0; i<22; i++)
	{
		_remove (i, &ht);
	}

	putchar ('\n');
	for (int i=0; i<22; i++)
	{
		_get (i, ht);
	}
	
	putchar ('\n');
	for (int i=0; i<22; i++)
	{
		_remove (i, &ht);
	}

	free_HashTable (&ht);
	//_put (1, "Ana", &ht);
	/**/
}

void _put (int k, char *data, HashTable *ht)
{
	char *s;
	int *i;

	i = malloc (sizeof (int));
	(*i) = k;

	s = strdup (data);

	int error = put_HashTable (i, s, ht);
	if ( error == 0 || error == -1 )
		printf ("%d: Put\n", k);
	else
		printf ("%d: Not Put\n", k);
}

void _get (int k, HashTable ht)
{
	char *s;
	int *i;

	i = malloc (sizeof (int));
	(*i) = k;

	if ( get_HashTable (i, ht, (void**)&s) == 0 )
		printf ("%d: %s\n", k, s);
	else
		printf ("%d: Not getted\n", k);
}

void _remove (int k, HashTable *ht)
{
	char *s;
	int *i;

	i = malloc (sizeof (int));
	(*i) = k;

	if ( remove_HashTable (i, ht, (void**)&s) == 0 ) {
		printf ("%d: %s\n", k, s);
		free (s);
	}
	else
		printf ("%d: Not Removed\n", k);
}
