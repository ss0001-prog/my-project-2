
#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    char name[50];
    int age;
    int ticketNumber;
} Passenger;

typedef struct Node {
    Passenger data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q);
int isQueueEmpty(Queue* q);
void enqueue(Queue* q, Passenger p);
Passenger dequeue(Queue* q);
void displayQueue(Queue* q);

#endif
