/**********************************************************************
Program: Reversing Linked List Daily 6
Author: Maxim Simakoff
Date: 2/5/24
Time spent: 7+ Hours
Purpose: The purpose of this program is to create a dynamic allocated linked list
with a head Node and then there is a reverse_list function that will take any linked list
of type "int" and reverse it, and then return the head of the NEW list which then it'll 
print out using that head.
***********************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
Node* reverse_list(Node* head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node pointer).
	head = reverse_list(head);
	
	//print the reversed list.
	
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	
	return 0;
}
*/
/*
//Define your function here
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
*/