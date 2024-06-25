// Bubble Sort - Comparing Adjacent elements, Swap if out of order, Do N-1 times. 
// Selection Sort - For N-1 items, Find Min. Element setting to index i, swaps with i
// Vanilla Insertion Sort - Assume sorted, rest swap left until sorted.

// h-Sort or 3-Sort
// 7 3 4 2 9 5 1 8 6 0
// Check third "2"
// New list
// 2 3 4 7 9 5 1 8 6 0
// Look at 3-away from "9"
// Leave it, its fine, consider "5"
// 1 3 4 2 9 5 7 8 6 0
// 1 3 4 2 8 5 7 9 6 0
// 0 3 4 1 8 5 2 9 6 7
// 
// When h-sort is 1-sort, that is insertion sort 

// Shell Sort - Is where you do h-sort, at h = list length, decreasing h - 1 everytime until h = 1. 
// Heapify - definition
// Quicksort - 

// EXAM - Verbal Definition of all Sorting Algorithms
// Quiz - Friday - 4/5/24
#include <stdio.h>
#include <stdlib.h>

#define SIZE (1000)

void print_array(int numbers[], int size);

// BUBBLE SORT
void vanilla_bubble_sort(int numbers[], int size);

void bubble_sort(int numbers[], int size);

void my_swap(int* pNum1, int* pNum2);
// BUBBLE SORT

void reset_array(int numbers[], int copy[], int size);

// SELECTION SORT
void selection_sort(int numbers[], int size);
// SELECTION SORT

void vanilla_insertion_sort(int numbers[], int size);
// Insertion sort
void insertion_sort(int numbers[], int size);
void insertion_sort_with_shifting(int numbers[], int size);

// SHELL SORT
void shell_sort(int numbers[], int size);
// SHELL SORT

// HEAP SORT
void heap_sort(int numbers[], int size);
void heapify(int numbers[], int size);
void fix_down(int numbers[], int size, int index);
void remove_max(int numbers[], int* pSize);
// HEAP SORT

// QUICK SORT
void quick_sort(int numbers[], int size);
// QUICK SORT

int find_index_of_smallest(int numbers[], int size,int starting_index);


long long int number_of_comparisons;
long long int number_of_assignments;

int main(int argc, char* argv[])
{
	int* pNumbers;
	int* copy;
	int i;
	pNumbers = malloc(sizeof(int) * SIZE);
	if (pNumbers == NULL)
	{
		printf("Failed to allocate space for array.\n");
		exit(1);
	}
	copy = malloc(sizeof(int) * SIZE);
	if (copy == NULL)
	{
		printf("Failed to allocate space for copy.\n");
		exit(1);
	}
	for (i = 0; i < SIZE; i++)
	{
		copy[i] = pNumbers[i] = (rand() << 15) + rand();
	}

	printf("Initialization Done\n");
	
	number_of_assignments = 0;
	number_of_comparisons = 0;

	vanilla_bubble_sort(pNumbers,SIZE);

	printf("Vanilla Bubble Sort Done\n");
	printf("Number of assignments %lld\n", number_of_assignments);
	printf("Number of comparisons %lld\n", number_of_comparisons);
	
	reset_array(pNumbers, copy, SIZE);

	number_of_assignments = 0;
	number_of_comparisons = 0;

	bubble_sort(pNumbers, SIZE);

	printf("Bubble Sort Done\n");
	printf("Number of assignments %lld\n", number_of_assignments);
	printf("Number of comparisons %lld\n", number_of_comparisons);
	
	number_of_assignments = 0;
	number_of_comparisons = 0;

	selection_sort(pNumbers, SIZE);

	printf("Selection Sort Done\n");
	printf("Number of assignments %lld\n", number_of_assignments);
	printf("Number of comparisons %lld\n", number_of_comparisons);
	return 0;
}
void print_array(int numbers[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d\n", numbers[i]);
	}

}
void shell_sort(int numbers[], int size)
{
	int h;
	int i;
	int j;
	int temp;
	h = 2;
	while(h < size / 3)
	{
		h *= 2;
	}
	h--;
	while (h > 0)
	{
		
		for (i = h; i < size; i++)
		{
			j = i;
			temp = numbers[j];
			while (j >= h  && temp < numbers[j - h])
			{
				numbers[j] = numbers[j - h];
				j -= h;
			}
			numbers[j] = temp;
		}
		h = h / 2;
	}
}

void vanilla_bubble_sort(int numbers[], int size)
{
	int i;
	int j;

	number_of_assignments++; // I loop init
	for (i = 0; i < size - 1; i++)
	{
		number_of_comparisons++; //Condition
		number_of_assignments++; // J Loop init
		for (j = 0; j < size - 1; j++)
		{
			number_of_comparisons++; // J loop condition
			number_of_comparisons++; // if statement
			if (numbers[j] > numbers[j + 1])
			{
				my_swap(&numbers[j], &numbers[j + 1]);
				number_of_assignments += 3;
			}
			number_of_assignments++; // J loop increment
		}
		number_of_comparisons++; // Last condition for j
		number_of_assignments++; //Increment
	}
	number_of_comparisons++; // Last condition
}
void bubble_sort(int numbers[], int size)
{
	int i;
	int j;
	int something_swapped;
	number_of_assignments++; // I loop init
	for (i = 0; i < size - 1; i++)
	{
		something_swapped = 0;
		number_of_assignments++; // something swapped init
		number_of_comparisons++; //Condition
		number_of_assignments++; // J Loop init
		for (j = 0; j < size - 1 - i; j++)
		{
			number_of_comparisons++; // J loop condition
			number_of_comparisons++; // if statement
			if (numbers[j] > numbers[j + 1])
			{
				my_swap(&numbers[j], &numbers[j + 1]);
				number_of_assignments += 3;
				something_swapped = 1;
				number_of_assignments++;
			}
			number_of_assignments++; // J loop increment
			number_of_comparisons++; // If statement
			
		}
		if (!something_swapped)	
		{
			break;
		}
		number_of_comparisons++; // Last condition for j
		number_of_assignments++; //Increment
	}
	number_of_comparisons++; // Last condition
}

void my_swap(int* pNum1, int* pNum2)
{

	int temp = *pNum1;
	*pNum1 = *pNum2;
	*pNum2 = temp;
}

void reset_array(int numbers[], int copy[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		numbers[i] = copy[i];
	}
}

void selection_sort(int numbers[], int size)
{
	int i;
	int index_of_smallest;
	for (i = 0; i < size - 1; i++)
	{
		index_of_smallest = find_index_of_smallest(numbers, size, i);
		my_swap(&numbers[i], &numbers[index_of_smallest]);
	}
}
int find_index_of_smallest(int numbers[], int size, int starting_index)
{
	int index_of_smallest = starting_index;
	int i;
	for (i = starting_index + 1; i < size; i++)
	{
		if (numbers[i] < numbers[index_of_smallest])
		{
			index_of_smallest = i;
		}
	}
	return index_of_smallest;
}
void vanilla_insertion_sort(int numbers[], int size)
{
	int i;
	int j;
	int temp;
	for (i = 1; i < size; i++)
	{
		j = i;
		temp = numbers[j];
		while (j > 0 && temp < numbers[j - 1])
		{
			numbers[j] = numbers[j - 1];
			j--;
		}
		numbers[j] = temp;
	}
}
void insertion_sort(int numbers[], int size)
{

}
void insertion_sort_with_shifting(int numbers[], int size)
{

}


// Heapify - Linear in cost O ( N ), Fix-down Repeated
// Exam 2 - Fix-up and Fix-down heapify on exam
// Fix-down you want to heapify - 
// Heap-Sort = Heapify the array, remove the max N-1 Times.
// Heapify - We apply fix-down on every element starting from the back of the array 
void heap_sort(int numbers[], int size)
{
	int number_of_times = size - 1;
	int i;
	// Heapify array
	heapify(numbers, size);
	//call remove max n-1 times
	for (i = 0; i < number_of_times; i++)
	{
		remove_max(numbers, &size);
	}
}
void heapify(int numbers[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		fix_down(numbers, size, i);
	}

}
void fix_down(int numbers[], int size, int index)
{
	int index_of_left_child = 2 * index + 1;
	int index_of_right_child = 2 * index + 2;
	int index_of_largest_child;
	if (index_of_left_child < size) // At least one child
	{
		if (index_of_right_child) // two children
		{
			index_of_largest_child = (numbers[index_of_left_child] > numbers[index_of_right_child]) ?
				index_of_left_child : index_of_right_child;
		}
		else // one child
		{
			index_of_largest_child = index_of_left_child;
		}
		if (numbers[index_of_largest_child] > numbers[index])
		{
			my_swap(&numbers[index_of_largest_child], &numbers[index]);
			fix_down(numbers, size, index_of_largest_child);
		}
	}
}
void remove_max(int numbers[], int* pSize)
{
	// swap the root with the last element
	my_swap(&numbers[0], &numbers[*pSize - 1]);
	// remove the last element
	(*pSize--);
	// fix down on the root
	fix_down(numbers, *pSize, 0);
}

void quick_sort(int numbers[], int size)
{
	// Select a pivot
	int index_of_left = 0;
	int temp;
	int index_of_right = size - 1;

	int e1 = ((rand() >> 15) + rand()) % size;

	temp = numbers[0];
	numbers[0] = numbers[e1];
	numbers[e1] = temp;


	//Partition

	if (size > 1)
	{
		while (index_of_left < index_of_right)
		{

			//scan right
			while (numbers[index_of_right] >= numbers[0] && index_of_left < index_of_right)
			{
				index_of_right--;
			}
			//scan left
			while (numbers[index_of_left] <= numbers[0] && index_of_left < index_of_right)
			{
				index_of_left++;
			}
			if (index_of_left < index_of_right)
			{
				temp = numbers[index_of_left];
				numbers[index_of_left] = numbers[index_of_right];
				numbers[index_of_right] = temp;
			}
		}


		temp = numbers[0]; // Pivot
		numbers[0] = numbers[index_of_left]; // Either or index's, means they met
		numbers[index_of_left] = temp;

		// Quick sort the halves
		// We need address of first element, as well as the size of it, for both sides of the pivot
		if (index_of_left > 1)
		{
			quick_sort(&numbers[0], index_of_left); // Left of pivot
		}
		if (size - index_of_left - 1 > 1)
		{
			quick_sort(&numbers[index_of_left + 1], (size - index_of_left - 1)); // Right of Pivot
		}

		// Once both Left scanner and right scanner found a value out of place, they swap
		// When the scanners meet, We swap the pivot into that spot

		// 1 Select a pivot - Can be leftmost item, random item, doesn't matter
		// 2 Partition - Organize the list - Items that are less than or equal to the pivot left, opposite for right
		// 3 Scan from the right until something out of place, swap, do for left, swap, etc.

	}
}


/*
void vanilla_bubble_sort(int numbers[], int size)
{
	int i;
	int j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if(numbers[j] > numbers[j+1])
				{
					my_swap(&numbers[j], &numbers[j + 1]);
				}
		}
	}
}
*/

// EXAM STUDY GUIDE 3 
// 
// Bubble Sort - Compare adjacent elements swap if out of order n-1 times
// H-Sort - Insertion sort except looking H Apart 
// Selection Sort - Find Min and Put at First
// Insertion Sort - Split, move unsorted to other list
// Shell Sort - H-Sort with decreasing values until H=1
// Heap Sort - Heapify, Remove Max N-1 Times
// Quick Sort - Select Pivot, sort recursively on each side 
// Max-Heap - Root of subtree is greater in each subtree
// Heapify - Fix-down start from back ignore leaf nodes

// H-Sort - Insertion Sort except look H apart
// Selection Sort - Find min and put first
// Insertion Sort - Split, move unsorted to other list
// Shell Sort - H-Sort with decreasing values until H=1 
// Heap Sort - Heapify and remove max N-1 Times
// Quick Sort - Select a Pivot, sort recursively on each side.
// Max-Heap - Root in each subtree is greater in each subtree
// Heapify - Fix down start from back and ignore leaf nodes
// Full - 0 or 2 nodes
// Complete - L to R
// 
// H-Sort - 
// Selection Sort - 
// Insertion Sort - 
// Shell Sort - 
// Heap Sort - 
// Quick Sort - 
// Max-Heap - 
// Heapify - 

//  
// Build a Heap with Heapify and without
// Traversals, 1 preorder 2 postorder 3 inorder
// Priority Queue & Heap - Reproduce the table - All time complexities - Know/Clarify few elements on table
// Build a Binary Search Tree, Doesnt look like a tree, could be pathelogical