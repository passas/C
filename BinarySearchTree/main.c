#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "BinarySearchTree.h"

int comparator (void *v1, void *v2)
{
	char* s1 = (char *) v1;
	char* s2 = (char *) v2;

	return strcmp (s1, s2);
}

void _put (int k, char *data, BinarySearchTree *bst);
void _get (int k, BinarySearchTree bst);
void _remove (int k, BinarySearchTree *bst);

main ()
{
	BinarySearchTree bst;

	new_BinarySearchTree (comparator, comparator, &bst);

	_put (1, "Ana", &bst);
	_put (2, "Bob", &bst);
	_put (3, "Cynthia", &bst);
	_put (4, "Dalila", &bst);
	_put (5, "Ed", &bst);
	_put (6, "Fiona", &bst);
	_put (7, "Gustaf", &bst);
	_put (8, "Henry", &bst);
	_put (9, "Inna", &bst);
	_put (10, "Julian", &bst);
	_put (11, "Kurt", &bst);
	_put (12, "Louis", &bst);
	_put (13, "Michael", &bst);
	_put (14, "Nicole", &bst);
	_put (15, "Orpheu", &bst);
	_put (16, "Peter", &bst);
	_put (17, "Quark", &bst);
	_put (18, "Xavier", &bst);
	_put (19, "Yuan", &bst);
	_put (20, "Waldo", &bst);
	_put (21, "Zac", &bst);

	printf ("\nHeight: %d\n\n", height_BinarySearchTree (bst));

	for (int i=0; i<22; i++)
	{
		_get (i, bst);
	}

}

void _put (int k, char *data, BinarySearchTree *bst)
{
	char *s;
	int *i;

	i = malloc (sizeof (int));
	(*i) = k;

	s = strdup (data);

	if (! put_BinarySearchTree (i, s, bst) )
		printf ("Put\n");
	else
		printf ("Not Put\n");
}

void _get (int k, BinarySearchTree bst)
{
	char *s;
	int *i;

	i = malloc (sizeof (int));
	(*i) = k;

	if ( get_BinarySearchTree (i, bst, (void**)&s) == 0 )
		printf ("%s\n", s);
	else
		printf ("Not getted\n");
}

/*void _remove (int k, BinarySearchTree *bst)
{
	char *s;
	int *i;

	i = malloc (sizeof (int));
	(*i) = k;

	if ( remove_BinarySearchTree (i, bst, (void**)&s) == 0 ) {
		printf ("%s\n", s);
		free (s);
	}
	else
		printf ("Not Removed\n");
}*/
