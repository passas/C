#ifndef QUEUE_H
#define QUEUE_H

// This module handles a fixed max capacity queue of pointers.
// FIFO.
typedef struct queue *Queue;

/*
* It allocates space memory for a Queue.
*
* @ret 0: success 1: memory allocation failed
*/int new_Queue (int size, Queue *q);

/*
* It initializes a Queue, or resets it.
*/void init_Queue (Queue *q);

/*
* It tests the emptyness of a Queue.
*
* @ret 0: False !0: True
*/int isEmpty_Queue (Queue q);

/*
* Enqueues an element.
*
* @ret 0: success 3: full queue
*/int enqueue_Queue (void *data, Queue *q);

/*
* Dequeue an element.
*
* @ret 0: success 2: empty queue
*/int dequeue_Queue (Queue *q, void **x);

/*
* Peaks the front element of the Queue.
*
* @ret 0: success 2: empty queue
*/int front_Queue (Queue q, void **x);

#endif
