#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

//This module maps information trough key->value
typedef struct hash_table *HashTable;

/*
* Function that allocates mem. space for a HashTable.
*
* @arg capacity Initial capacity of it.
* @arg factor Load factor of the HashTable.
* @arg hash Hash function of the Keys.
* @arg equals Equals function of the Data/Elements.
*
* @ret 0: success 1: memory allocation fail
*/int new_HashTable (int capacity, float factor, int (*hash) (void *), int (*equals) (void *, void*), HashTable *ht);

/*
* Put data into HashTable.
*
* @ret -1: data updated 0: new data 1: memory alloc. failed
*/int put_HashTable (void *key, void *data, HashTable *ht);

/*
* Get data from HashTable
*
* @param (void **) Where data gets passed by.
*
* @ret -1: key not found 0: key found
*/int get_HashTable (void *key, HashTable ht, void **x);

/*
* Removes data from HashTable
*
* @param (void **) Where data gets passed by.
*
* @ret -1: key not found 0: key found
*/int remove_HashTable (void *key, HashTable *ht, void **x);

/*
* Free Data Structure and it's elements.
*/void free_HashTable (HashTable *ht);

#endif
