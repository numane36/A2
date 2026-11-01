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