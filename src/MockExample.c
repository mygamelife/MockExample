#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "MockExample.h"
#include "Stack.h"

char *reverseString(char *stringToReverse)
{
	int i , j = 0;
	char *reversedString , ch;
	Stack *stack = stackNew(512);
	printf("stack:%p\n", stack);
	printf("size:%d, length:%d\n", stack->size , stack->length);
	
	for(i = 0; stringToReverse[i] != '\0' ; i++)
	{
		stackPush(stack, (int)stringToReverse[i]);
		printf("%c",stringToReverse[i]);
	}
	
	printf("\n");
	reversedString = malloc(sizeof(char) * (i + 1) );
	
	while(!stackisEmpty(stack)) 
	{
		reversedString[j++] = stackPop(stack);
		printf("%c", reversedString[j-1]);
	}
	reversedString[j] = '\0';
	
	return reversedString;
}