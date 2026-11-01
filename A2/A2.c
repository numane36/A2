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
