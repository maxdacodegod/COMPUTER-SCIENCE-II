///**********************************************************************
//Program: DAILY 6B 
//Author: Maxim Simakoff
//Date: 2/8/2024
//Time spent: 6 Hours
//Purpose: The purpose of this program is to take inputs of random numbers into 
//a list which is done by the head insert function. There are 2 seperate lists in this program
//that are created. Then take the sum of both lists but before this you have to convert 
//the lists into integers, and then you can add the 2 integers into a sum and then you take that sum
//and turn it into another list, then reverse the list which is the answer. The next thing is printing 
//the 1st list as an integer, 2nd list as an integer, as well as the total as an integer. Lastly,
//both linked lists will be destroyed successfully.
//***********************************************************************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//struct node;
//typedef struct node Node;
//struct node
//{
//	int data;
//	Node* next;
//};
//
//void head_insert(Node** pHead, int value);
//void print_list(Node* head);
//Node* destroy_list(Node* head);
//Node* list_sum(Node* head1, Node* head2);
//Node* reverse_list(Node* head);
//
//int main(int argc, char* argv[])
//{
//	//add up 189 + 11
//	Node* head1 = NULL;
//	Node* head2 = NULL;
//	Node* head_sum = NULL;
//	//create a list for the number 189
//	head_insert(&head1, 9);
//	head_insert(&head1, 8);
//	head_insert(&head1, 1);
//	
//	//create a list for the number 11
//	head_insert(&head2, 1);
//	head_insert(&head2, 1);
//
//	head_sum = list_sum(head1, head2);
//
//	printf("The sum of ");
//	print_list(head1);
//	printf(" + ");
//	
//	print_list(head2);
//	printf("\n");
//	printf(" = ");
//	print_list(head_sum);
//	printf("\n");
//
//	//clean up three lists
//	destroy_list(head1); head1 = NULL;
//	destroy_list(head2); head2 = NULL;
//	destroy_list(head_sum); head_sum = NULL;
//	return 0;
//}
//
//void head_insert(Node** pHead, int value)
//{
//	Node* head = *pHead;
//	Node* New_Node;
//	
//	New_Node = (Node*)malloc(sizeof(Node));
//
//	if (New_Node == NULL)
//	{
//		printf("out of memory?\n");
//	}
//
//	New_Node->data = value;
//
//	New_Node->next = head;
//
//	*pHead = New_Node;
//}
//
//void print_list(Node* head)
//{
//	Node* temp = head;
//
//	while (temp != NULL)
//	{
//		printf("%d", temp->data);
//		temp = temp->next;
//	}
//}
//
//Node* destroy_list(Node* head)
//{
//	Node* temp = head;
//	while (temp != NULL)
//	{
//		temp = temp->next;
//		free(head);
//		head = temp;
//	}
//	return head;
//}
//
//Node* list_sum(Node* head1, Node* head2)
//{
//	Node* head_sum = NULL;
//	Node* temp = NULL;
//	Node* new_node = NULL; //For adding new nodes to a new list
//
//	int sum1 = 0;
//	int num1 = 0;
//	int sum2 = 0;
//	int num2 = 0;
//	int length_of_list_1 = 0;
//	int length_of_list_2 = 0;
//	int total_sum = 0;
//	int total_sum_length = 0;
//
//	temp = head1;
//	//Calculate Head 1 Length
//	while (temp != NULL)
//	{
//		length_of_list_1++;
//		temp = temp->next;
//	}
//
//	//ADD HEAD 1
//	while (head1 != NULL)
//	{
//		length_of_list_1--; // VAL 2
//		num1 = head1->data;
//		sum1 += pow(10,length_of_list_1) * num1; 
//		head1 = head1->next;
//	}
//
//	temp = head2;
//	//Calculate Head 2 Length
//	while (temp != NULL)
//	{
//		length_of_list_2++;
//		temp = temp->next;
//	}
//
//	//ADD HEAD 2
//	while (head2 != NULL)
//	{
//		length_of_list_2--; // VAL 1
//		num2 = head2->data;
//		sum2 += pow(10, length_of_list_2) * num2;
//		head2 = head2->next;
//	}
//
//	//SUM UP BOTH HEADS (Integers)
//	total_sum = sum1 + sum2;
//
//	//CONVERT Integer total TO LINKED LIST
//	total_sum_length = 1 + (int)log10(total_sum);
//
//	int x = total_sum_length; // X = 3
//
//	total_sum_length--; // 3 - 1 = 2
//
//	
//	int i;
//	for (i = 0; i < x; i++)
//	{
//		int number = 0;
//		int remainder = 0;
//		
//		new_node = (Node*)malloc(sizeof(Node));
//		if (new_node == NULL)
//		{
//			printf("out of memory?\n");
//		}
//
//		number = total_sum / pow(10, total_sum_length); // 2 = 200 / 10^2
//		remainder = total_sum % (int)pow(10, total_sum_length); // 0 = 200 % 10^2
//		total_sum_length--;
//		
//		new_node->data = number;
//		new_node->next = head_sum;
//		head_sum = new_node;
//
//		total_sum = remainder;
//	}
//	
//
//	head_sum = reverse_list(new_node);
//	free(temp);
//	return head_sum; //Return the head of the new list
//}
//
//Node* reverse_list(Node* head)
//{
//	Node* previous = NULL; // Previous Hand is empty
//	Node* current = head; //First one is the Head
//	Node* next; //Next one
//
//	while (current != NULL)
//	{
//		next = current->next;
//
//		current->next = previous;
//
//		previous = current;
//
//		current = next;
//
//		head = previous;
//
//	}
//	return head;
//}