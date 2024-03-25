#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

// Q 1 
// Drawing out a STACK sequence

// Q 2 
// Drawing out a sequence of a QUEUE.

// Q 3 
// MEMORY TABLE

// Q 4
// Write a function called destroy that takes a Node pointer
//of the head of the list and will free memory associated with it.
Node* destroy(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	printf("Destroyification Complete\n");
	return head;
}
// Q 5.a
//Write a Recursive function called sum that given a Node pointer 
//of the head of the list will return the sum of all data in the 
//linked list.

int sum(Node* head)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		return head->data + sum(head->next);
	}
}

// Q 5.b
//Write a iterative version called sum that given a Node pointer 
//of the head of the list will return the sum of all data in the 
//linked list.
int sum(Node* head)
{
	Node* temp = head;
	int add = 0;
	while (temp != NULL)
	{
		add += temp->data;
		temp = temp->next;
	}
	return add;
}

// Q 6
// Write a function called copy_list that, given a Node pointer 
// to the head of the list will return a Node pointer containing
// the address of the head node of a new list that is an exact 
// copy of the original list. Your copy should be independent of 
// the first list and not share any nodes. You may write an iterative
// or recursive version of your function.
Node* copyList(Node* head)
{
	if (head == NULL) 
	{
		return NULL;
	}
	else 
	{
		Node* newNode= (Node*)malloc(sizeof(Node));
		newNode->data = head->data;
		newNode->next = copyList(head->next);
		return newNode;
	}
}
Node* copy_list(Node* head)
{
	Node* new_head = NULL;

	while (head != NULL)
	{
		new_head->data = head->data;
		new_head->next = new_head;
		head = head->next;
		new_head = new_head->next;
	}
	new_head->next = NULL;
	return new_head;
}

// Q 7
// Write a function called my_vector_init_default that initializes
// the vector to have a size of zero, capacity of seven and an 
// appropriate value in the data pointer. Your function should
// return the address of an opaque object upon success and NULL 
// otherwise
struct my_vector	//Known Type
{
	int size;	// Number of elements we CURRENTLY HOLD
	int capacity; // Number of elements we can hold without resizing
	int* data;
};

typedef struct my_vector My_vector;
typedef void* MY_VECTOR;

MY_VECTOR my_vector_init_default(void)
{
	My_vector* pVector = (My_vector*)malloc(sizeof(My_vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 7;
		pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
	}
	return pVector;
}

// Q 8.a
// 
// What is an opaque object handle?
// 
// A reference or identifier representing an object without 
// exposing its internal details or structure.

// Q 8.b
// 
// What is an ADT (Abstract Data Type)?
// 
// Stack, queue, list are all ADT's. 
// use data structures without needing to know their 
// internal implementation details.
// Abstract data types(ADTs) are a way of encapsulating 
// data and operations on that data into a single unit.


// Q
// Destroy vector
void my_vector_destroy(MY_VECTOR* phVector)
{
	My_vector* pVector = (My_vector*)*phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

// Q
// Destroy Linked list
void destroy_list(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
//Q
// Head insert
void head_insert(Node** pHead, int value)
{
	Node* head = *pHead;
	Node* New_Node = (Node*)malloc(sizeof(Node));

	if (New_Node == NULL)
	{
		printf("out of memory?\n");
	}

	New_Node->data = value;

	New_Node->next = head;

	*pHead = New_Node;
}
// Q
// Tail insert
void tail_insert(Node** pHead, int value)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;

	Node* head = *pHead;
	Node* last_node = *pHead;

	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
}

// Q
// Remove item from back
void remove_tail(Node** pHead)
{
	Node* head = *pHead;
	Node* previous = NULL;
	if (head == NULL)
	{
		return;
	}
	if (head->next == NULL)
	{
		free(head);
		*pHead = NULL;
	}
	else
	{
		while (head->next != NULL)
		{
			previous = head;
			head = head->next;
		}

		free(head);
		previous->next = NULL;
	}
}
// Q 
// Remove item from front
void remove_head(Node** pHead)
{
	Node* head = *pHead;
	Node* previous = *pHead;
	if (head == NULL)
	{
		return;
	}
	if (head->next == NULL)
	{
		free(head);
		*pHead = NULL;
	}
	if (head != NULL)
	{
		head = head->next;
	}
	free(previous);
	*pHead = head;
}