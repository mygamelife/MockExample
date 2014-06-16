#ifndef Stack_H
#define Stack_H

typedef struct
{
	int *buffer;
	int size;
	int length;
}Stack;

Stack *stackNew(int length);
void stackPush(Stack *stackPtr, int data);
int stackPop(Stack *stackPtr);
void StackDel(Stack *stack);
int stackisEmpty(Stack *stackPtr);
int stackisFull(Stack *stackPtr);

#endif // Stack_H
