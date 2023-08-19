#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

// This module handles a queue with a priority controll of integers.
// Min-Heap: low integer => most priority
typedef struct priority_queue *PriorityQueue;

/*
* Memory allocation of a Priority Queue.
*
*
* @ret 0: success 1: memory allocation failed
*/int new_PriorityQueue (int size, PriorityQueue *q);

/*
* Memory liberation of a Priority Queue.
*
*/void free_PriorityQueue (PriorityQueue *q);

/*
* Initialization of the Queue.
*
*/void init_PriorityQueue (PriorityQueue *q);

/*
* Test the emptyness of the Queue.
*
* @ret 0: False !0: True
*/int isEmpty_PriorityQueue (PriorityQueue q);

/*
* Enqueue of an element.
*
* Theta: log2(N)
*
* @ret 0: success 1: memory allocation failed (the queue left unchagend)
*/int enqueue_PriorityQueue (int priority, void *data, PriorityQueue *q);

/*
* Dequeue of an element.
*
* Theta: log2(N)
*
* @ret 0: success 2: empty queue
*/int dequeue_PriorityQueue (PriorityQueue *q, void **x);

/*
* Peek of the front element of the queue.
*
* @ret 0: success 2: empty queue
*/int front_PriorityQueue (PriorityQueue *q, void **x);


#endif
