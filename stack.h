#ifndef STACK_H
#define STACK_H

#include "queue.h"

typedef struct StackNode {
    Passenger data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void initStack(Stack* s);
int isStackEmpty(Stack* s);
void push(Stack* s, Passenger p);
Passenger pop(Stack* s);
void displayStack(Stack* s);

#endif
