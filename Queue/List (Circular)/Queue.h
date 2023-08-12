#ifndef QUEUE_H
#define QUEUE_H

//Queue of data via pointers.
//FIFO.
typedef struct list *Queue;


/*
* Queue initialization.
*/void init_Queue (Queue *q);

/*
* Tests if Queue have elements.
*
* @ret 0: False !0: True
*/int isEmpty_Queue (Queue q);

/*
* Enqueues data to the back of the queue.
*
* @arg (void *) a pointer to the data.
*
* @ret 0: success 1: memory allocation failed
*/int enqueue_Queue (void *, Queue *);

/*
* Retrieves data from the front of the queue.
*
* @arg (void **) a pointer to an address where the data will be putted.
*
* @ret 0: success 2: empty queue
*/int dequeue_Queue (Queue *, void **);

/*
* Peaks the data from the front of the queue.
*
* @arg (void **) a pointer to an address where the data will be putted.
*
* @ret 0: success 2: empty queue
*/int front_Queue (Queue q, void **);


#endif