#include "unity.h"
#include "MockExample.h"
#include "mock_Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_reverseString_exploration(void)
{	
	char *result;
	//Create test fixture
	Stack stackInstance;
	int staticStackbuffer[10];
	stackInstance.buffer = staticStackbuffer;
	stackInstance.length = 512;	
	stackInstance.size = 0;
	printf("stackInstance: %p\n", &stackInstance);
	
	//Mock
	stackNew_ExpectAndReturn(512,&stackInstance);
	stackPush_Expect(&stackInstance, 'b');
	stackPush_Expect(&stackInstance, 'a');
	stackPush_Expect(&stackInstance, 'n');
	stackPush_Expect(&stackInstance, 'a');
	stackPush_Expect(&stackInstance, 'n');
	stackPush_Expect(&stackInstance, 'a');
	
	stackisEmpty_ExpectAndReturn(&stackInstance , 0);
	stackPop_ExpectAndReturn(&stackInstance, 'a');
	stackisEmpty_ExpectAndReturn(&stackInstance , 0);
	stackPop_ExpectAndReturn(&stackInstance, 'n');
	stackisEmpty_ExpectAndReturn(&stackInstance , 0);
	stackPop_ExpectAndReturn(&stackInstance, 'a');
	stackisEmpty_ExpectAndReturn(&stackInstance , 0);
	stackPop_ExpectAndReturn(&stackInstance, 'n');
	stackisEmpty_ExpectAndReturn(&stackInstance , 0);
	stackPop_ExpectAndReturn(&stackInstance, 'a');
	stackisEmpty_ExpectAndReturn(&stackInstance , 0);
	stackPop_ExpectAndReturn(&stackInstance, 'b');
	stackisEmpty_ExpectAndReturn(&stackInstance , 1);
	
	//Run
	result = reverseString("banana");
	
	TEST_ASSERT_EQUAL_STRING("ananab", result );
}
