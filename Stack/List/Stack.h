#ifndef STACK_H
#define STACK_H

// It stacks data through pointers.
// LIFO.
typedef struct list *Stack;

/*
* It initializes a Stack.
*/void init_Stack (Stack *s);

/*
* It test the emptiness of the Stack.
*
* @ret 0: false !0: true
*/int isEmpty_Stack (Stack s);

/*
* Function that pushes data into the Stack.
* In case of error the Stack keeps inaltered.
*
* @arg void * a pointer to the data.
*
* @ret 0: success 1: memory allocation failed
*/int push_Stack (void *, Stack *);

/*
* Function that pops data from the Stack.
*
* @arg void ** a pointer to a data store address.
*
* @ret 0: success 2: empty Stack
*/int pop_Stack (Stack *, void **);

/*
* Function that peeks the top data from the Stack.
*
* @arg void ** a pointer to a data store address.
*
* @ret 0: success 2: empty Stack
*/int top_Stack (Stack, void **);

#endif