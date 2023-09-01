#include <stdlib.h>
// malloc
// free

#include "BinarySearchTree.h"
//typedef struct binary_search_tree *BinarySearchTree;

#define LEFT -1
#define BAL 0
#define RIGHT 1

typedef struct node
{
	int bal;
	void *key;
	void *data;
	struct node *left, *right;
} *Node;

struct binary_search_tree
{
	int (*comparator) (void *, void *); //for keys
	int (*equals) (void *, void *);		//for data
	Node tree;
};

int new_BinarySearchTree (int (*comparator) (void *, void *), int (*equals) (void *, void *), BinarySearchTree *bst)
{
	int error;
	BinarySearchTree r;

	error = 0;
	r = (BinarySearchTree) malloc (sizeof (struct binary_search_tree));
	if (r)
	{
		r->comparator = comparator;
		r->equals = equals;
		(*bst) = r;
	}
	else
	{
		error = 1;
	}

	return error;
}

int isEmpty_BinarySearchTree (BinarySearchTree bst)
{
	return !(bst->tree);
}

/*
* Funtion that handles a new element or update an old one in a recursive way.
* It also handles the balance factor of the tree.
*/static int _put_BinarySearchTree (void *key, void *data, int (*comparator) (void *, void *), int (*equals) (void *, void *), Node *t, int *new);

int put_BinarySearchTree (void *key, void *data, BinarySearchTree *bst)
{
	int error;
	int new_flag;

	error = _put_BinarySearchTree (key, data, (*bst)->comparator, (*bst)->equals, &((*bst)->tree), &new_flag);
	return error;
}

/*Function that fix insertion in a right node and bal == RIGHT
*/static void _fixRight (Node *t);
/* Function that fix insertion in a left node and bal == LEFT
*/static void _fixLeft (Node *t);

static int _put_BinarySearchTree (void *key, void *data, int (*comparator) (void *, void *), int (*equals) (void *, void *), Node *t, int *new_flag)
{
	int error;
	Node aux;

	if (!(*t))	//new node
	{
		aux = (Node) malloc (sizeof (struct node));
		if (aux)
		{
			error = 0;	//error value

			aux->key = key;
			aux->data = data;
			aux->left = aux->right = NULL;
			aux->bal = BAL;

			(*t) = aux;

			(*new_flag) = 1;
		}
		else
		{
			error = 1;	//error value
		}
	}

	else if ( comparator((*t)->key, key) == 0 ) //update node
	{
		error = -1;	//error value

		(*t)->data = data;
			
		(*new_flag) = 0;
	}

	else if ( comparator((*t)->key, key) > 0 ) //expand left
	{
		error = _put_BinarySearchTree (key, data, comparator, equals, &((*t)->left), new_flag);

		if ( (*new_flag) )
		{
			switch ( (*t)->bal )
			{
				case LEFT:
					_fixLeft (&(*t));
					(*new_flag) = 0;
					break;

				case BAL:
					(*t)->bal = LEFT;
					break;

				case RIGHT:
					(*t)->bal = BAL;
					(*new_flag) = 0;
					break;	
			}	
		}

	}

	else if ( comparator((*t)->key, key) < 0 ) //expand right
	{
		error = _put_BinarySearchTree (key, data, comparator, equals, &((*t)->right), new_flag);

		if ( (*new_flag) )
		{
			switch ( (*t)->bal )
			{
				case LEFT:
					(*t)->bal = BAL;
					(*new_flag) = 0;
					break;

				case BAL:
					(*t)->bal = RIGHT;
					break;

				case RIGHT:
					_fixRight (&(*t));
					(*new_flag) = 0;
					break;	
			}
		}
	}

	return error;
}

/*pre-order: R1 R2 <R2 >R2 R3 ---------- R2 <R2 R1 >R2 R3
*/static void _rotateRight (Node *t);
/*pre-order: R1 R2 <R2 >R2 R3 ---------- R3 R1 R2 <R3 >R3
*/static void _rotateLeft (Node *t);

static void _fixLeft (Node *t)
{
	Node *son, *grand_son;
											if (!(*t)->left) return; //DUE REMOVE FIXURES
	son = &((*t)->left);

	if ((*son)->bal == LEFT)
	{
		(*t)->bal = (*son)->bal = BAL;
		_rotateRight (t);
	}

	else
	{										if (!(*son)->right) return; //DUE REMOVE FIXURES
		grand_son = &((*son)->right);

		if ((*grand_son)->bal == LEFT)
		{
			(*t)->bal = RIGHT;
			(*son)->bal = BAL;
		}
		else if ((*grand_son)->bal == BAL)
		{
			(*t)->bal = BAL;
			(*son)->bal = BAL;
		}
		else if ((*grand_son)->bal == RIGHT)
		{
			(*t)->bal = BAL;
			(*son)->bal = LEFT;
		}

		(*grand_son)->bal = BAL;

		_rotateLeft (son);
		_rotateRight (t);
	}
}

static void _fixRight (Node *t)
{
	Node *son, *grand_son;
								if (!(*t)->right) return; //DUE REMOVE FIXURES
	son = &((*t)->right);

	if ((*son)->bal == RIGHT)
	{
		(*t)->bal = (*son)->bal = BAL;
		_rotateLeft (t);
	}

	else
	{							if (!(*son)->left) return; //DUE REMOVE FIXURES
		grand_son = &((*son)->left);

		if ((*grand_son)->bal == LEFT)
		{
			(*t)->bal = BAL;
			(*son)->bal = RIGHT;
		}

		else if ((*grand_son)->bal == BAL)
		{
			(*t)->bal = BAL;
			(*son)->bal = BAL;
		}

		else if ((*grand_son)->bal == RIGHT)
		{
			(*t)->bal = LEFT;
			(*son)->bal = BAL;
		}

		(*grand_son)->bal = BAL;

		_rotateRight (son);
		_rotateLeft (t);
	}
}

static void _rotateRight (Node *t)
{
	Node aux;

	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t) = aux;
}
static void _rotateLeft (Node *t)
{
	Node aux;

	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t) = aux;
}

int get_BinarySearchTree (void *key, BinarySearchTree bst, void **x)
{
	int error;
	Node aux;

	error = -1;

	aux = bst->tree;

	while (error && aux)
	{
		if (bst->comparator (aux->key, key) == 0)
		{
			error = 0;
		}
		else if (bst->comparator (aux->key, key) > 0)
		{
			aux = aux->left;
		}
		else
		{
			aux = aux->right;
		}
	}

	if (!error)
	{
		(*x) = aux->data;
	}
	else
	{
		(*x) = NULL;
	}

	return error;
}

/*
* This function handles the balance.
* It also handles the disconnection between nodes.
*
* @ret Node of the key most left.
*/static Node _removeMinor (int (*comparator) (void *, void *), Node *t);
static Node _removeRoot (int (*comparator) (void *, void *), Node *t);

/*int remove_BinarySearchTree (void *key, BinarySearchTree *bst, void **x)
{
	int error;
	Node *aux, tmp;

	error = -1;

	aux = &((*bst)->tree);

	while (error && (*aux))
	{
		if ((*bst)->comparator ((*aux)->key, key) == 0)
		{
			tmp = _removeRoot ((*bst)->comparator, aux);
			(*x) = tmp->data;
			free (tmp);

			error = 0;
		}
		else if ((*bst)->comparator ((*aux)->key, key) > 0)
		{
			aux = &((*aux)->left);
		}
		else
		{
			aux = &((*aux)->right);
		}
	}

	return error;
}*/

/*static Node _removeMinor (int (*comparator) (void *, void *), Node *t)
{
	Node *father, son;

	father = NULL;
	son = (*t);
	while (son && son->left)
	{
		father = &(son);
		son = son->left;
	}

	if ((father))
	{
		if (son->right)
		{
			(*father)->left = son->right;
			//son->right = NULL;
		}
		else
		{
			(*father)->left = NULL;
		}
*/
		/*switch ((*father)->bal)
		{
			case LEFT:
				(*father)->bal = BAL;
				break;
			case BAL:
				(*father)->bal = RIGHT;
				break;
			case RIGHT:
				_fixRight (father);
				break;
		}*/
/*	}
	else	//!father
	{
		if ( son->right )
		{
			(*t) = son->right;
			//son->right = NULL;
		}
	}

	return son;
}*/

/*static Node _removeRoot (int (*comparator) (void *, void *), Node *t)
{
	Node root, aux;
	int flag_remove;

	aux = (*t);
	root = NULL;
	if ((*t)->right) 
	{
		root = _removeMinor (comparator, &((*t)->right));
		flag_remove = RIGHT;
	}
	else
	{
		root = _removeMinor (comparator, t);
		flag_remove = LEFT;
	}

	if (root)
	{
		root->left = (*t)->left;
		if ( root != (*t)->right )
			root->right = (*t)->right;
		else
			root->right = NULL;
		(*t) = root;
	
		aux->left = aux->right = NULL;
	}
*/	
	/*switch (aux->bal)
	{
		case LEFT:
			if (flag_remove == LEFT)
				(*t)->bal = BAL;
			else
				_fixLeft (t);
			break;
		case BAL:
			if (flag_remove == LEFT)
				(*t)->bal = RIGHT;
			else
				(*t)->bal = LEFT;
			break;
		case RIGHT:
			if (flag_remove == LEFT)
				(*t)->bal = BAL;
			else
				_fixRight (t);
	}*/
/*
	return aux;
}*/

static int _heightLeft (Node t);
static int _heightRight (Node t);
int height_BinarySearchTree (BinarySearchTree bst)
{
	int left, right;

	left = _heightLeft (bst->tree);
	right = _heightRight (bst->tree);

	return left>right?left:right;
}

static int _heightLeft (Node t)
{
	if (t)
	{
		return 1 + _heightLeft (t->left);
	}
	else
		return 0;
}

static int _heightRight (Node t)
{
	if (t)
	{
		return 1 + _heightRight (t->right);
	}
	else
		return 0;
}
