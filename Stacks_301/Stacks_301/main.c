#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
// Input Redirection: "Code File" < "Stuff.txt" > "PRINT_RESULT_HERE.TXT"
// Stack Question on Exam. Trace the code, Draw a picture of the stack
// Study a stack
// ADT - Abstract Data Type

int main(int argc, char* argv[])
{
	STACK hStack;
	int i;
	hStack = stack_init_default; // Make the Stack (Init is Initialize) 

	if (hStack == NULL)
	{
		printf("Failed to Allocate space for stack object");
		exit(1);
	}

	//Work
	for (i = 0; i < 10; i++)
	{
		if (stack_push(hStack, i) == FAILURE)
		{
			printf("Failed to push = %d\n", i);
			exit(1);
		}
	}
	while (!stack_is_empty(hStack))
	{
		printf("Pop! %d\n", stack_top(hStack, NULL));
		stack_pop(hStack);
	}
	stack_destroy(&hStack);

	return 0;
}