#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Passenger p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;
    if (isQueueEmpty(q))
        q->front = q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Passenger dequeue(Queue* q) {
    Passenger temp = { "", 0, 0 };
    if (!isQueueEmpty(q)) {
        Node* del = q->front;
        temp = del->data;
        q->front = q->front->next;
        free(del);
        if (q->front == NULL)
            q->rear = NULL;
    }
    return temp;
}

void displayQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("\nNo booked tickets.\n");
        return;
    }
    Node* temp = q->front;
    printf("\n--- Booked Tickets ---\n");
    while (temp) {
        printf("Ticket No: %d | Name: %s | Age: %d\n",
               temp->data.ticketNumber, temp->data.name, temp->data.age);
        temp = temp->next;
    }
}
