/*
* FILE			: A2.h
* PROJECT		: Assignment 2
* PROGRAMMER	: Tarik Kurt
* FIRST VERSION	: 11/1/2026
* Description	: Header file for declearing data structures and functions for stacks, queues and brower navigation managemnt
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL 50
#define BUFFER_SIZE 64

typedef struct StackNode {
	char url[MAX_URL];
	struct StackNode* next;
} StackNodec;

typedef struct Stack {
	StackNodec* top;
} Stack;

typedef struct QueueNode {
	char url[MAX_URL];
	struct QueueNode* next;
} QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
} Queue;


// prototype
Stack* createStack(void);
StackNode* newStackNode(char* url);
void push(Stack* stack, char* newUrl);
char* pop(Stack* stack);
char* peek(Stack* stack);
bool isEmptyStack(Stack* stack);
void freeStack(Stack* stack);

// queue functions
Queue* createQueue(void);
QueueNode* newQueueNode(char* url);
void enqueue(Queue* queue, char* newUrl);
char* dequeue(Queue* queue);
char* queuePeek(Queue* queue);
bool isEmptyQueue(Queue* queue);
void moveToRear(Queue* queue, char* targetUrl);
void printHistory(Queue* queue);
void freeQueue(Queue* queue);


// browser navigation functions
void cleanNewline(char* str);

