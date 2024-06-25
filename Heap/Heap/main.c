#include <stdio.h>
#include <stdlib.h>

void heap_insert(int heap[], int* pSize , int value);
void fix_up(int heap[], int index);
void remove_max(int heap[], int* pSize);
void fix_down(int heap[],int size, int index);

int main(int argc, char* argv[])
{
	int heap[50];
	int size = 0;
	int i;
	//34 1 48 23 75 21 86 55

	heap_insert(heap, &size, 34);
	heap_insert(heap, &size, 1);
	heap_insert(heap, &size, 48);
	heap_insert(heap, &size, 23);
	heap_insert(heap, &size, 75);
	heap_insert(heap, &size, 21);
	heap_insert(heap, &size, 86);
	heap_insert(heap, &size, 55);

	for (i = 0; i < size; i++)
	{
		printf("%d\n", heap[i]);
	}
	printf("\n");
	while (size > 0)
	{
		printf("Removing %d\n", heap[0]);
		remove_max(heap, &size);
	}
	printf("\n");
	for (i = 0; i < 8; i++)
	{
		printf("%d\n", heap[i]);
	}
	printf("\n");
	return 0;
}

void heap_insert(int heap[], int* pSize, int value)
{
	heap[*pSize] = value;
	(*pSize)++;
	fix_up(heap, (*pSize - 1));
}
void fix_up(int heap[], int index)
{
	int index_of_parent;
	int temp;
	if (index > 0)
	{
		index_of_parent = (index - 1) / 2;
		if(heap[index] > heap[index_of_parent])
		{
			temp = heap[index];
			heap[index] = heap[index_of_parent];
			heap[index_of_parent] = temp;
			fix_up(heap, index_of_parent);
		}
	}
}

void remove_max(int heap[], int* pSize)
{
	// Swap root with last element
	// Call fix down on root
	int temp = heap[0];
	heap[0] = heap[*pSize - 1];
	heap[*pSize - 1] = temp;
	(*pSize)--;
	fix_down(heap, *pSize, 0);
}
void fix_down(int heap[], int size, int index)
{
	int index_of_left_child = index * 2 + 1;
	int index_of_right_child = index * 2 + 2;
	int index_of_largest_child;
	int temp;

	if (index_of_left_child < size) // At least 1 Child
	{
		if (index_of_right_child < size)// 2 Children
		{
			index_of_largest_child = (heap[index_of_left_child] > heap[index_of_right_child]) ? index_of_left_child : index_of_right_child;
		}
		else
		{
			index_of_largest_child = index_of_left_child;
		}
		if (heap[index_of_largest_child] > heap[index])
		{
			temp = heap[index_of_largest_child];
			heap[index_of_largest_child] = heap[index];
			heap[index] = temp;
			fix_down(heap, size, index_of_largest_child);
		}
	}
}
//			EXAM 2!
// Priority Queue, Heap, AVL Tree
// Add/Remove things from a tree
// Quiz on 15th
// Midnight Last day of April assignments
