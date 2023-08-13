#ifndef DEQUE_H
#define DEQUE_H

// It handles a Double Ended Queue.
// Elements are pushed by it's pointers.
// FIFO & LIFO
typedef struct deque *Deque;

/*
* Constructor.
*
* @ret 0: success 1: memory allocation fail
*/int new_Deque (Deque *d);

/*
* Formal initialization of a Deque.
*
*/void init_Deque (Deque *d);

/*
* Test the emptyness of a Deque.
*
* @ret 0: False 1: True
*/int isEmpty_Deque (Deque d);

/*
* Push to the last position of the queue.
*
* @ret 0: success 1: memory allocation fail
*/int pushBack_Deque (void *data, Deque *d);

/*
* Push to the first position of the queue.
*
* @ret 0: success 1: memory allocation fail
*/int pushFront_Deque (void *data, Deque *d);

/*
* Pops the last element of the queue.
*
* @ret 0: success 2: empty queue
*/int popBack_Deque (Deque *d, void **x);

/*
* Pops the first element of the queue.
*
* @ret 0: success 2: empty queue
*/int popFront_Deque (Deque *d, void **x);

/*
* Peaks the last element of the queue.
*
* @ret 0: success 2: empty queue
*/int back_Deque (Deque d, void **x);

/*
* Peaks the first element of the queue.
*
* @ret 0: success 2: empty queue
*/int front_Deque (Deque d, void **x);

#endif