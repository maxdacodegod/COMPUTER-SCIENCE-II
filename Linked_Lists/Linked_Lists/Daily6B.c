/**********************************************************************
Program: DAILY 6B
Author: Maxim Simakoff
Date: 2/8/2024
Time spent: 6 Hours
Purpose: The purpose of this program is to take inputs of random numbers into
a list which is done by the head insert function. There are 2 seperate lists in this program
that are created. Then take the sum of both lists but before this you have to convert
the lists into integers, and then you can add the 2 integers into a sum and then you take that sum
and turn it into another list, then reverse the list which is the answer. The next thing is printing
the 1st list as an integer, 2nd list as an integer, as well as the total as an integer. Lastly,
both linked lists will be destroyed successfully.
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node;
typedef struct node Node;
struct node
{
	int data;
	Node* next;
};

void head_insert(Node** pHead, int value);
void print_list(Node* head);
Node* destroy_list(Node* head);
Node* list_sum(Node* head1, Node* head2);
Node* reverse_list(Node* head);

int main(int argc, char* argv[])
{
	//add up 189 + 11
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head_sum = NULL;

	//create a list for the number 189
	head_insert(&head1, 9);
	head_insert(&head1, 8);
	head_insert(&head1, 1);

	//create a list for the number 11
	head_insert(&head2, 1);
	head_insert(&head2, 1);

	head_sum = list_sum(head1, head2); 

	printf("The sum of ");
	print_list(head1);
	printf(" + ");

	print_list(head2);
	printf("\n");
	printf(" = ");

	print_list(head_sum);
	printf("\n");

	//clean up three lists
	destroy_list(head1); head1 = NULL;
	destroy_list(head2); head2 = NULL;
	destroy_list(head_sum); head_sum = NULL;
	return 0;
}

void head_insert(Node** pHead, int value)
{
	Node* head = *pHead;
	Node* New_Node;

	New_Node = (Node*)malloc(sizeof(Node));
	if (New_Node != NULL)
	{
		New_Node->data = value;

		New_Node->next = head;

		*pHead = New_Node;
	}
	else
	{
		printf("Memory Allocation failed!");
	}
}

void print_list(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
}

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
Node* list_sum(Node* head1, Node* head2)
{
	head1 = reverse_list(head1);
	head2 = reverse_list(head2);

	Node* temp1 = head1;
	Node* temp2 = head2;

	Node* result = NULL;
	int carry = 0;
	int sum = 0;

	while (temp1 != NULL || temp2 != NULL) 
	{

		sum = carry;

		if (temp1 != NULL)
		{
			sum += temp1->data;
		}
		if (temp2 != NULL)
		{
			sum += temp2->data;
		}

		if (sum >= 10)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}

		sum = sum % 10;

		head_insert(&result, sum);

		if (temp1)
		{
			temp1 = temp1->next;
		}
		if (temp2)
		{
			temp2 = temp2->next;
		}
	}
	if (carry > 0)
	{
		head_insert(&result, carry);
	}
	reverse_list(head1);
	reverse_list(head2);

	return result;
}

Node* reverse_list(Node* head)
{
	Node* previous = NULL; // Previous Hand is empty
	Node* current = head; //First one is the Head
	Node* next; //Next one

	while (current != NULL)
	{
		next = current->next;

		current->next = previous;

		previous = current;

		current = next;

		head = previous;

	}
	return head;
}

