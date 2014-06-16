#include "unity.h"
#include "ErrorCode.h"
#include "CException.h"
#include "Stack.h"

#define STACK_LENGTH 5
Stack stack;
int buffer[sizeof(int) * (STACK_LENGTH + 16)];

void setUp(void)
{
	stack.buffer = buffer;
	stack.length = STACK_LENGTH;
	stack.size = 0;
}

void tearDown(void)
{
}

void test_stackNew_should_init_stack_struct(void)
{	
	TEST_ASSERT_NOT_NULL(&stack); //contain memory not NULL
	TEST_ASSERT_NOT_NULL(stack.buffer);
	TEST_ASSERT_EQUAL(0 , stack.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH , stack.length);
}

void test_stackPush_given_3_should_push_into_buffer_0(void)
{
	stackNew(STACK_LENGTH);
	stackPush(&stack , 3);
	TEST_ASSERT_EQUAL(3, buffer[0]);
	TEST_ASSERT_EQUAL(1, stack.size);
	TEST_ASSERT_EQUAL(STACK_LENGTH, stack.length);
}

void test_stackPush_given_10_11_12_13_14_should_throw_exception(void)
{
	CEXCEPTION_T err;
	
	stackNew(STACK_LENGTH);
	
	Try
	{	
		stackPush(&stack , 10);
		stackPush(&stack , 11);
		stackPush(&stack , 12);
		stackPush(&stack , 13);
		stackPush(&stack , 18);
		stackPush(&stack , 19);
		TEST_FAIL_MESSAGE("Should throw ERR_STACK_EMPTY exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_FULL , err , "Expect ERR_STACK_FULL exception");
		TEST_ASSERT_EQUAL(6, stack.size);
	}
}

void test_stackPop_given_1_should_pop_1(void)
{	
	
	stackNew(STACK_LENGTH);
	stackPush(&stack , 1);
	TEST_ASSERT_EQUAL(1 , stackPop(&stack));
	TEST_ASSERT_EQUAL(0 , stack.size);
}

void test_stackPop_given_2_3_should_pop_3(void)
{	
	
	stackNew(STACK_LENGTH);
	stackPush(&stack , 2);
	stackPush(&stack , 3);
	TEST_ASSERT_EQUAL(3 , stackPop(&stack));
	TEST_ASSERT_EQUAL(1 , stack.size);
}

void test_stackPop_given_4_should_pop_4_throw_ERR_STACK_EMPTY_exception(void)
{	
	CEXCEPTION_T err;
	
	stackNew(STACK_LENGTH);
	stackPush(&stack , 4);
	TEST_ASSERT_EQUAL(4 , stackPop(&stack));
	
	Try
	{
		stackPop(&stack);
		TEST_FAIL_MESSAGE("Should throw ERR_STACK_EMPTY exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_EMPTY , err , "Expect ERR_STACK_EMPTY exception");
		TEST_ASSERT_EQUAL(0 , stack.size); 
	}
}