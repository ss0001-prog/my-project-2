#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack* s) {
    s->top = NULL;
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, Passenger p) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = p;
    newNode->next = s->top;
    s->top = newNode;
}

Passenger pop(Stack* s) {
    Passenger temp = { "", 0, 0 };
    if (!isStackEmpty(s)) {
        StackNode* del = s->top;
        temp = del->data;
        s->top = s->top->next;
        free(del);
    }
    return temp;
}

void displayStack(Stack* s) {
    if (isStackEmpty(s)) {
        printf("\nNo canceled tickets.\n");
        return;
    }
    StackNode* temp = s->top;
    printf("\n--- Canceled Tickets ---\n");
    while (temp) {
        printf("Ticket No: %d | Name: %s | Age: %d\n",
               temp->data.ticketNumber, temp->data.name, temp->data.age);
        temp = temp->next;
    }
}
