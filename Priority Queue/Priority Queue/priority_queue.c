#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "heap.h"

struct node //This structure is INSIDE priority queue
{
	int priority; 
	int data;
};

struct priority_queue
{
	Node* max_heap; // max_heap stores node's which have a priority and a data
	int size;
	int capacity;
};
typedef struct priority_queue PriorityQueue;

PRIORITY_QUEUE priority_queue_init_default(void)
{
	PriorityQueue* pQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	if (pQ != NULL)
	{
		pQ->size = 0;
		pQ->capacity = 1;
		pQ->max_heap = (Node*)malloc(sizeof(Node) * pQ->capacity);
		if (pQ->max_heap == NULL)
		{
			free(pQ);
			return NULL;
		}
	}
	return pQ;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	PriorityQueue* pQ = (PriorityQueue*)hQueue;
	Node* temp;
	int i;

	if (pQ->size >= pQ->capacity) //Not enough room, make room
	{
		temp = (Node*)malloc(sizeof(Node) * pQ->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pQ->size; i++) // Deep COPY
		{
			temp[i] = pQ->max_heap[i];
		}
		free(pQ->max_heap);
		pQ->max_heap = temp;
		pQ->capacity *= 2;
	}
	if (pQ != NULL)
	{
		heap_insert(pQ->max_heap, &(pQ->size), priority_level, data_item);
		return SUCCESS;
	}
	return FAILURE;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	PriorityQueue* pQ = (PriorityQueue*)hQueue;

	if (priority_queue_is_empty(pQ))
	{
		return FAILURE;
	}
	remove_max(pQ->max_heap, &(pQ->size));
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	PriorityQueue* pQ = (PriorityQueue*)hQueue;
	if (priority_queue_is_empty(pQ))
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
	return pQ->max_heap[0].data;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	PriorityQueue* pQ = (PriorityQueue*) hQueue;
	return pQ->size <= 0 ? TRUE : FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue) // This destroy's EVERYTHING
{
	PriorityQueue* pQ = (PriorityQueue*) phQueue;

	free(pQ->max_heap);
	free(pQ);
	*phQueue = NULL;
}
/***************************************************************************************/
// HEAP FUNCTIONS
void heap_insert(Node* pHeap, int* pSize, int priority, int value)
{
	pHeap[*pSize].data = value;
	pHeap[*pSize].priority = priority;
	(*pSize)++;
	fix_up(pHeap, (*pSize - 1));
}
void fix_up(Node* pHeap, int index)
{
	int index_of_parent;
	int temp_priority;
	int temp_value;
	if (index > 0)
	{
		index_of_parent = (index - 1) / 2;
		if (pHeap[index].priority > pHeap[index_of_parent].priority)
		{
			temp_priority = pHeap[index].priority;
			temp_value = pHeap[index].data;
			pHeap[index].priority = pHeap[index_of_parent].priority;
			pHeap[index].data = pHeap[index_of_parent].data;
			pHeap[index_of_parent].priority = temp_priority;
			pHeap[index_of_parent].data = temp_value;
			fix_up(pHeap, index_of_parent);
		}
	}
}

void remove_max(Node* pHeap, int* pSize)
{
	// Swap root with last element
	// Call fix down on root
	int temp_priority;
	int temp_value;
	temp_priority = pHeap[0].priority;
	temp_value = pHeap[0].data;
	pHeap[0].data = pHeap[*pSize - 1].data;
	pHeap[0].priority = pHeap[*pSize - 1].priority;
	pHeap[*pSize - 1].data = temp_value;
	pHeap[*pSize - 1].priority = temp_priority;
	(*pSize)--;
	fix_down(pHeap, pSize, 0);
}
void fix_down(Node* pHeap, int* size, int index)
{
	int index_of_left_child;
	int index_of_right_child;
	int index_of_largest_child;
	int temp_data;
	int temp_priority;

	index_of_left_child = index * 2 + 1;
	index_of_right_child = index * 2 + 2;

	if (index_of_left_child < *size) // At least 1 Child
	{
		if (index_of_right_child < *size)// 2 Children
		{
			index_of_largest_child = (pHeap[index_of_left_child].priority > pHeap[index_of_right_child].priority) ? index_of_left_child : index_of_right_child;
		}
		else
		{
			index_of_largest_child = index_of_left_child;
		}
		if (pHeap[index_of_largest_child].priority > pHeap[index].priority)
		{
			temp_priority = pHeap[index_of_largest_child].priority;
			temp_data = pHeap[index_of_largest_child].data;
			pHeap[index_of_largest_child].priority = pHeap[index].priority;
			pHeap[index_of_largest_child].data = pHeap[index].data;
			pHeap[index].priority = temp_priority;
			pHeap[index].data = temp_data;
			fix_down(pHeap, size, index_of_largest_child);
		}
	}
}