/*
* FILE			: A2.c
* PROJECT		: Assignment 2
* PROGRAMMER	: Tarik Kurt
* FIRST VERSION	: 11/1/2026
* Description	: Browser history management program using lniked list stacks for back and forward navigation and a queue for history management
*/

#include "A2.h"

/*
* Function 		: createStack
* Description	: Allocates an empty stack and returns a pointer to it
* Parameters	: void
* returns		: Stack* - pointer to the newly created stack
*/
Stack* createStack(void)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL)
	{
		printf("No memory available to create stack\n");
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	return stack;
}

/*
* Function 		: newStackNode
* Description	: Allocates a new stack node with the given URL and returns a pointer to it
* Parameters	: char * url - url string to store
* returns		: StackNode* - porinter to newly created stack node
*/
StackNode* newStackNode(char* url)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (newNode == NULL)
	{
		printf("No memory available to create stack node\n");
		exit(EXIT_FAILURE);
	}
	snprintf(newNode->url, sizeof(newNode->url), "%s", url);
	newNode->next = NULL;
	return newNode;
}
/*
* Function 		: push
* Description	: Inserts a url node onto the top of the stack
* Parameters	: Stack* stack - the targetr stack
*				  char* - allocates string copy of url or null if stack is empty
* returns		: void
*/
void push(Stack* stack, char* newUrl)
{
	StackNode* newNode = newStackNode(newUrl);
	newNode->next = stack->top;
	stack->top = newNode;
}

/*
* Function 		: pop
* Description	: removes and returns the url from the top of the stack
* Parameters	: Stack* stack - the target stack
* returns		: char* - pointer to the url string or null if stack is empty
*/

char* pop(Stack* stack)
{
	if (isEmptyStack(stack))
	{
		printf("Stack is empty\n");
		return NULL;
	}
	StackNode* nodeToPop = stack->top;
	char* urlCopy = (char*)malloc(sizeof(char) * MAX_URL);
	if (urlCopy == NULL)
	{
		snprintf(urlCopy, MAX_URL, "%s", nodeToPop->url);
	}

	stack->top = nodeToPop->next;
	free(nodeToPop);

	return urlCopy;
}
/*
* Function 		: peek
* Description	: returms the url from the top of the stack without removing it
* Parameters	: Stack* stack - the target stack
* returns		: char* - top url string or null if stack is empty
*/
char* peek(Stack* stack)
{
	if (isEmptyStack(stack))
	{
		return NULL;
	}
	return stack->top->url;
}

/*
* Function 		: isEmptyStack
* Description	: verifies if the stack contains any nodes
* Parameters	: Stack* stack - the target stack
* returns		: bool - true if empty and false if not
*/

bool isEmptyStack(Stack* stack)
{
	return stack->top == NULL;
}

/*
* Function 		: freeStack
* Description	: frees every remaning noide in the stack and frees the stack struct itself
* Parameters	: Stack* stack - the target stack
* returns		: void
*/

void freeStack(Stack* stack)
{
	StackNode* current = stack->top;
	StackNode* temp = NULL;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

/*
* Function 		: createQueue
* Description	: Allocates an empty queue and returns a pointer to it
* Parameters	: void
* returns		: Queue* - pointer to the newly created queue
*/

Queue* createQueue(void)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL)
	{
		printf("No memory available to create queue\n");
		exit(EXIT_FAILURE);
	}
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

/*
* Function 		: newQueueNode
* Description	: Allocates a new queue node with the given URL and returns a pointer to it
* Parameters	: char* url - url string to store
* returns		: QueueNode* - pointer to the newly created queue node
*/
QueueNode* newQueueNode(char* url)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("No memory available to create queue node\n");
		exit(EXIT_FAILURE);
	}
	snprintf(newNode->url, sizeof(newNode->url), "%s", url);
	newNode->next = NULL;
	return newNode;
}
/*
* Function 		: enqueue
* Description	: Adds a url to the rear of the queue 
* Parameters	: Queue* queue - the target queue
*				  char* newUrl - url string to add to the queue
* returns		: void
*/

void enqueue(Queue* queue, char* newUrl)
{
	QueueNode* newNode = newQueueNode(newUrl);
	if (queue->rear == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

/*
* Function 		: dequeue
* Description	: removes and returns the url string from the front of the queue
* Parameters	: Queue* queue - the targert queue
* returns		: char* - pointer to the url string or null if queue is empty
*/

char* dequeue(Queue* queue)
{
	if (isEmptyQueue(queue))
	{
		printf("Queue is empty\n");
		return NULL;
	}
	QueueNode* nodeToDequeue = queue->front;
	char* urlCopy = (char*)malloc(sizeof(char) * MAX_URL);
	if (urlCopy == NULL)
	{
		snprintf(urlCopy, MAX_URL, "%s", nodeToDequeue->url);
	}
	queue->front = nodeToDequeue->next;
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
	free(nodeToDequeue);
	return urlCopy;
}

/*
* Function 		: queuePeek
* Description	: returns the url string from the front of the queue without removing it
* Parameters	: Queue* queue - the target queue
* returns		: char* - front url string or null if queue is empty
*/

char* queuePeek(Queue* queue)
{
	if (isEmptyQueue(queue))
	{
		return NULL;
	}
	return queue->front->url;
}

/*
* Function 		: isEmptyQueue
* Description	: verifies if the queue contains any nodes
* Parameters	: Queue* queue - the targe	
* returns		: bool - true if front is NULL and false if not
*/
bool isEmptyQueue(Queue* queue)
{
	return queue->front == NULL;
}
/*
* Function 		: moveToRear
* Description	: if targeturl exists in the queue, it is removed and added to the rear of the queue
* Parameters	: Queue* queue - the target queue
*				  char* targetUrl - url string to move to the rear of the queue
* returns		: void
*/

void moveToRear(Queue* queue, char* targetUrl)
{
	if (queue == NULL || targetUrl == NULL)
	{
		return;
	}
	if (isEmptyQueue(queue))
	{
		enqueue(queue, targetUrl);
		return;
	}

	QueueNode* current = queue->front;
	QueueNode* prev = NULL;

	while (current != NULL)
	{
		if (strcmp(current->url, targetUrl) == 0)
		{
			if (prev == NULL)
			{
				queue->front = current->next;
			}
			else
			{
				prev->next = current->next;
			}

			current->next = NULL;
			queue->rear->next = current;
			queue->rear = current;
			return;
		}
		prev = current;
		current = current->next;
	}

	enqueue(queue, targetUrl);
}

/*
* Function 		: printHistory
* Description	: Traverses the queue and prints the url strings in order from front to rear
* Parameters	: Queue* queue - the target queue
* returns		: void
*/
void printHistory(Queue* queue)
{
	if (isEmptyQueue(queue))
	{
		printf("No history available\n");
		return;
	}
	QueueNode* current = queue->front;
	int count = 1;

	printf("Browsing History:\n");
	while (current != NULL)
	{
		printf("%d. %s\n", count, current->url);
		current = current->next;
		count++;
	}
	printf("----------------------------");
}

/*
* Function 		: freeQueue
* Description	: frees every remaining node in the queue and frees the queue struct itself
* Parameters	: Queue* queue - the target queue
* returns		: void
*/

void freeQueue(Queue* queue)
{
	QueueNode* current = queue->front;
	QueueNode* temp = NULL;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(queue);
}
/*
* Function 		: cleanNewline
* Description	: removes the newline character from the end of a string if it exists
* Parameters	: char* str - the target string
* returns		: void
*/

void cleanNewline(char* str)
{
	if (str != NULL)
	{
		size_t len = strlen(str);
		if (len > 0 && str[len - 1] == '\n')
		{
			str[len - 1] = '\0';
		}
	}
}

