/*
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int value;
	Node* next;
};

void print_list(Node* head); //give a copy of the head node

void recursive_print_list(Node* head);

void reverse_print_list(Node* head);
void recursive_reverse_print_list(Node* head);

int main(int argc, char* argv[])
{
	Node* head = NULL; // Head itself is not a node, but refers to a node

	// 42 -> 107 -> 31 -> NULL

	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
	head->value = 42;
	head->next = (Node*)malloc(sizeof(Node));
	if (head->next == NULL)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
	head->next->value = 107;
	head->next->next = (Node*)malloc(sizeof(Node));
	if (head->next->next == NULL)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
	head->next->next->value = 31;
	head->next->next->next = NULL;
	
	print_list(head);

	return 0;
}


void print_list(Node* head)
{
	while (head != NULL)
	{
		printf("%d->", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

void recursive_print_list(Node* head)
{
	if (head != NULL)
	{
		printf("%d->", head->value);
		recursive_print_list(head->next);
	}
	else
	{
		printf("NULL!\n");
	}
}

void recursive_reverse_print_list(Node* head)
{
	if (head != NULL)
	{
		recursive_reverse_print_list(head->next);
		printf("%d->", head->value);
	}
	else
	{
		printf("NULL!\n");
	}
}
void reverse_print_list(Node* head)
{
	Node* last_printed = NULL;
	Node* current;
	while (last_printed != head)
	{
		current = head;
		while (current->next != last_printed)
		{
			current = current->next;
		}
		printf("%d->", current->value);
		last_printed = current;
	}
	printf("\n");
}
*/