#ifndef STACK_H
#define STACK_H

typedef struct list *Stack;

void init_Stack (Stack *s);

int isEmpty_Stack (Stack s);

int push_Stack (void *, Stack *);

int pop_Stack (Stack *, void **);

int top_Stack (Stack, void **);

#endif