/**********************************************************************
Program: Daily 7 Challenge Problem
Author: Maxim Simakoff
Date: 2/24/2024
Time spent: 5 Hours
Purpose: The purpose of this program is to read in a random string of 
Parantheses, curly braces, or brackets and then see if they are "correct".
To determine if they are correct... every open has a close.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

enum status { FAILURE, SUCCESS };
typedef enum status Status;
enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

struct node;
typedef struct node Node;
struct node
{
	char value;
	Node* next;
};
//A stack is not a node, it is a list.
struct stack //Known Type
{
	Node* head;
};
typedef struct stack Stack;


// FUNCTION DECLARATIONS
typedef void* STACK; //Pointer without context
STACK stack_init_default(void);
//Push
Status stack_push(STACK hStack, char value);
//Pop
Status stack_pop(STACK hStack);
//Top
char stack_top(STACK hStack, Status* pStatus);
//Empty
Boolean stack_is_empty(STACK hStack);
//Destroy
void stack_destroy(STACK* phStack);


int main(int argc, char* argv[])
{
	int test_cases;
	char c;
	char top;
	FILE* fp;
	FILE* output;
	fp = fopen("Input.txt", "r");
	output = fopen("output.txt", "w");

	if (fp == NULL)
	{
		printf("Failed to open the file.\n");
		exit(1);
	}

	fscanf(fp, "%d\n", &test_cases);
	printf("The number of Test cases are: %d\n\n", test_cases);

	STACK hStack;
	int i;
	hStack = stack_init_default(); // Make the Stack (Init is Initialize) 

	if (hStack == NULL)
	{
		printf("Failed to Allocate space for stack object");
		exit(1);
	}

	char str[30];

	//Work: Read 1 by 1 into stack
	for(i = 0; i < test_cases; i++) //8192 TEST CASES RUNNING IN THIS FOR LOOP
	{
		hStack = stack_init_default(); //Initiliaze a new stack every iteration
		if (hStack == NULL)
		{
			printf("Failed to Allocate space for stack object");
			exit(1);
		}

		char c = '\0'; // Initialize c with Terminator Every iteration
		Boolean balance = TRUE;
		int j = 0; // Initialize j with Terminator Every iteration

		char str[30] = { '\0' };

		while (fscanf(fp, "%c", &c) != EOF && c != '\n') // Read line into string (Array)
		{
			str[j] = c;
			j++;
		}
		str[j] = '\0'; // NULL TERMINATE THE STRING
		j = 0;
		c = str[j]; // Give the first character from the array to c.


		while (c != '\0' && c != '\n')
		{
			// READ IN
			if (c == '[' || c == '{' || c == '(') //If it is a left, push onto stack
			{
				stack_push(hStack, c);
			}
			else if (c == ']' || c == '}' || c == ')') // if it is one of the right markers
			{
				if (stack_is_empty(hStack)) //Is it empty?
				{
					balance = FALSE;
					break;
				}
				else
				{
					top = stack_top(hStack, NULL); //CHECKING TOP OF STACK
					if ((c == ']' && top == '[') || (top == '{' && c == '}') || (top == '(' && c == ')')) //if it is the correct left marker then pop it out
					{
						stack_pop(hStack);
					}
					else
					{
						balance = FALSE;
						break;
					}
				}
			}
			j++; //Transition to Next character
			c = str[j]; //Give that character to the char variable c.
		}

		if (stack_is_empty(hStack) && balance == TRUE) //If the stack is empty and the balance is true, meaning everything worked, print YES
		{
			fprintf(output,"YES\n");
		}
		else
		{
			fprintf(output,"NO\n");
		}
		
		stack_destroy(&hStack); // Destroy the stack on every iteration, creating a new one then removing it
	}

	if (hStack != NULL)
	{
		stack_destroy(&hStack);
	}
	fclose(output);
	fclose(fp);
	return 0;
}

STACK stack_init_default(void)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->head = NULL;
	}
	return pStack;
}

Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;
	if (stack_is_empty(pStack))
	{
		return FAILURE;
	}
	temp = pStack->head;
	pStack->head = pStack->head->next;
	free(temp);
	return SUCCESS;
}

char stack_top(STACK hStack, Status* pStatus)
{
	Stack* pStack = (Stack*)hStack;
	if (stack_is_empty(pStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return -1337;
	}
	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	return pStack->head->value;
}


Status stack_push(STACK hStack, char value)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}

	temp->value = value;
	temp->next = pStack->head;
	pStack->head = temp;
	return SUCCESS;
}


Boolean stack_is_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	return (pStack->head == NULL) ? TRUE : FALSE;
}


void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	Node* temp;
	while (pStack->head != NULL) // DESTROYING ON EXAM
	{
		temp = pStack->head;
		pStack->head = pStack->head->next;
		free(temp);
	}

	//Now kill memory footprint
	free(pStack);
	*phStack = NULL;
}
