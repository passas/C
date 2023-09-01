#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

// This module handles a Binary Search Tree.
// Insert, get, and remove executes in order of THETA (N) = log2(N)
typedef struct binary_search_tree *BinarySearchTree;

/*
* Function that allocates memory to the refered data structure.
*
* @arg comparator A function that handles the comparison of the keys.
* @arg equals A function that handles the equality of the data/elements stored.
*/int new_BinarySearchTree (int (*comparator) (void *, void *), int (*equals) (void *, void *), BinarySearchTree *bst);

/*
* Tests the emptyness of the tree.
*
* @ret 0: False 1: True
*/int isEmpty_BinarySearchTree (BinarySearchTree bst);

/*
* Function that trees an element.
*
* @arg key The key factor of the element.
* @arg data The data itself.
*/int put_BinarySearchTree (void *key, void *data, BinarySearchTree *bst);

/*
* Search element by it's key.
*
* @arg (void **) store location of the pointer to the data previous treed.
*
* @ret -1: element not found 0: element found
*/int get_BinarySearchTree (void *key, BinarySearchTree bst, void **x);

/*
* Remove element by it's key.
*
* @arg (void **) store location of the pointer to the data previous treed.
*
* @ret -1: element not found 0: element found & removed
*///int remove_BinarySearchTree (void *key, BinarySearchTree *bst, void **x);

int height_BinarySearchTree (BinarySearchTree bst);

#endif
