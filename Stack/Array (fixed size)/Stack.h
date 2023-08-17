#ifndef STACK_H
#define STACK_H

// This module handles a Stack with a limited fixed size.
// LIFO.
typedef struct stack *Stack;

/*
* It defines a Stack in memory.
*
* @ret 0: success 1: memory allocation fail
*/int new_Stack (int size, Stack *s);

/*
* Function that formally initializes a Stack.
*/void init_Stack (Stack *s);

/*
* Tests the emptyness of a Stack.
*
* @ret 0: False !0: True
*/int isEmpty_Stack (Stack s);

/*
* Push an element into the Stack.
*
* @ret 0: success 3: Stack reached is definied limit
*/int push_Stack (void *data, Stack *s);

/*
* It pop's out an element of the Stack.
*
* @arg (void **) a pointer to a pointer of the stored data type.
*
* @ret 0: success 2: empty Stack
*/int pop_Stack (Stack *s, void **x);

/*
* Peak the top element of the Stack.
*
* @arg (void **) a pointer to a pointer of the stored data type.
*
* @ret 0: success 2: empty Stack
*/int top_Stack (Stack *s, void **x);


#endif
