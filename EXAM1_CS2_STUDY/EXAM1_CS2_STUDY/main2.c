#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
	int data;
	Node* next;
};


Node* destroy_list(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	return head;
}

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

int sum(Node* head)
{
	Node* temp = head;
	int sum = 0;
	while (temp != NULL)
	{
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

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
		pVector->data = (int*)malloc(sizeof(int)* pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
	}
	return pVector;
}

void my_vector_destroy(MY_VECTOR* phVector)
{
	My_vector* pVector = (My_vector*) *phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

/****************************************************************************************************************/

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

int sum(Node* head)
{
	Node* temp = head;
	int add;
	while (temp != NULL)
	{
		add += temp->data;
		temp = temp->next;
	}
	return add;
}

Node* destroy_list(Node* head)
{
	Node* temp = head;
	while (head != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	return head;
}
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
void my_vector_destroy(MY_VECTOR* phVector)
{
	My_vector* pVector = (My_vector*) *phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}
/****************************************************************************************************************/

void tail_insert(Node** pHead, int value)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("out of memory?\n");
	}
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
void head_insert(Node** pHead, int value)
{
	Node* head = *pHead;
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("out of memory?\n");
	}
	new_node->data = value;
	new_node->next = head;
	*pHead = new_node;
}

/****************************************************************/
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
/****************************************************************/

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
void my_vector_destroy(MY_VECTOR* phVector)
{
	My_vector* pVector = (My_vector*)*phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}
/****************************************************************/
void head_insert(Node** pHead, int value)
{
	Node* head = *pHead;
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		return NULL;
	}
	new_node->data = value;
	new_node->next = head;
	*pHead = new_node;

}

void tail_insert(Node** pHead, int value)
{
	Node* head = *pHead;
	Node* new_node = (Node*)malloc(sizeof(Node));
	Node* last_node = *pHead;
	if (new_node == NULL)
	{
		return;
	}
	new_node->data = value;
	new_node->next = NULL;
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
void remove_tail(Node** pHead)
{
	Node* head = *pHead;
	Node* previous = NULL;
	if (head == NULL)
	{
		return;
	}
	if(head->next == NULL)
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
	if(head != NULL)
	{
		head = head->next;
	}
	free(previous);
	*pHead = head;
}

Node* copyList(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	else 
	{
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = head->data;
		new_node->next = copyList(head->next);
		return new_node;
	}
}
