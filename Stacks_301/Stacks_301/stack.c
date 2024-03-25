#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node;
typedef struct node Node;
struct node
{
	int value;
	Node* next;
};


//A stack is not a node, it is a list.
struct stack //Known Type
{
	Node* head;
};

typedef struct stack Stack;


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

int stack_top(STACK hStack, Status* pStatus)
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


Status stack_push(STACK hStack, int value)
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
	Stack* pStack = (Stack*) hStack;
	return (pStack->head == NULL) ? TRUE : FALSE;
}


void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*) *phStack;
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
	printf("Destroyification Complete!\n");
}