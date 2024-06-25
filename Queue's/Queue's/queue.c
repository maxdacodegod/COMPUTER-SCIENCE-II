#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node Node;
struct node {
	int number;
    Node* prev;
    Node* next;
};

typedef struct queue Queue;
struct queue{
	Node* front;
	Node* rear;
};

QUEUE queue_init_default(void)
{
	Queue* pQ = (Queue*)malloc(sizeof(Queue));
	if (pQ != NULL)
	{
		pQ->front = NULL;
		pQ->rear = NULL;
	}
	return pQ;
}
Status queue_insert(QUEUE hQ, int value)
{
	Queue* pQ = (Queue*)hQ;
	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL)
	{
		return FAILURE;
	}

	new_node->number = value;
	new_node->next = NULL;

	if (pQ->rear != NULL)
	{
		pQ->rear->next = new_node;
		new_node->prev = pQ->rear;
	}
	pQ->rear = new_node;

	if (pQ->front == NULL)
	{
		pQ->front = new_node;
	}
	return SUCCESS;
}
Status queue_service(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	Node* temp;
	if (queue_is_empty(hQ))
	{
		return FAILURE;
	}

	temp = pQ->front;
	pQ->front = pQ->front->next;

	if (pQ->front != NULL)
	{
		pQ->front->prev = NULL;
	}
	else
	{
		pQ->rear = NULL;
	}

	free(temp);
	return SUCCESS;
}
int queue_front(QUEUE hQ, Status* pStatus)
{
	Queue* pQ = (Queue*)hQ;
	if (queue_is_empty(hQ))
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
	return pQ->front->number;
}
Boolean queue_is_empty(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	return (pQ->front == NULL);
}
void queue_destroy(QUEUE* phQ)
{
	Queue* pQ = (Queue*)*phQ;
	Node* temp;
	while (pQ->front != NULL) // Destroy linked list
	{
		temp = pQ->front;
		pQ->front = pQ->front->next;
		free(temp);
	}
	free(pQ);
	*phQ = NULL;
}