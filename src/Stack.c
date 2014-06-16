#include <stdio.h>
#include <malloc.h>
#include "ErrorCode.h"
#include "CException.h"
#include "Stack.h"

Stack *stackNew(int lengthOfStack)
{
	Stack *stack = malloc(sizeof(Stack));
	stack->buffer = malloc(sizeof(int) * lengthOfStack);
	stack->size = 0;
	stack->length = lengthOfStack;
	
	return stack;
}

int stackisFull(Stack *stackPtr)
{
	if(stackPtr->size > stackPtr->length)
		return 0;
	
	return 1;
}

void stackPush(Stack *stackPtr, int data)
{
	stackPtr->buffer[stackPtr->size] = data;
	stackPtr->size++;
	
	if(!stackisFull(stackPtr))
	Throw(ERR_STACK_FULL);
}

void StackDel(Stack *stack)
{
	if(stack != NULL)
	{
		free(stack->buffer);
		free(stack);
	}
}

int stackisEmpty(Stack *stackPtr)
{
	if(stackPtr->size == 0)
		return 0;
		
	return 1;
}

int stackPop(Stack *stackPtr)
{
	int PopData;
	
	if(!stackisEmpty(stackPtr))
	Throw(ERR_STACK_EMPTY);	
	
	PopData = stackPtr->buffer[stackPtr->size-1];
	stackPtr->size--;
	
	return PopData;
}