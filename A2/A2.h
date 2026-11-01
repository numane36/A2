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
