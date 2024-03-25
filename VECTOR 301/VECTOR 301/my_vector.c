#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

struct my_vector	//Known Type
{
	int size;	// Number of elements we CURRENTLY HOLD
	int capacity; // Number of elements we can hold without resizing
	int* data;
};

typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void)
{
	My_vector* pVector = (My_vector*)malloc(sizeof(My_vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = malloc(sizeof(int) * pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
	}
	return pVector;
}

int my_vector_get_size(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector;
	return pVector->size;
}
int my_vector_get_capacity(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector;
	return pVector->capacity;
}

Status my_vector_push_back(MY_VECTOR hVector, int value)
{
	My_vector* pVector = (My_vector*)hVector;
	int* temp; 
	int i;

	if (pVector->size >= pVector->capacity) //If there is no room, make room
	{
		temp = malloc(sizeof(int) * pVector->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		free(pVector->data); //Free old array
		pVector->data = temp; // temp and data refer to the array.
		pVector->capacity *= 2;
		// Resizing is "expensive"
	}
	pVector->data[pVector->size] = value;
	pVector->size++;
	return SUCCESS;
}

Boolean my_vector_is_empty(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector;
	//Turnary Operator
	//()?():()
	return (pVector->size <= 0) ? TRUE : FALSE;
}

Status my_vector_pop_back(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector;
	if (my_vector_is_empty(hVector) == TRUE)
	{
		return FAILURE;
	}
	pVector->size--;
	
	return SUCCESS;
}

int* my_vector_at(MY_VECTOR hVector, int index)
{
	My_vector* pVector = (My_vector*)hVector;
	if (index >= pVector->size || index < 0)
	{
		return NULL;
	}
	return &(pVector->data[index]);
	// SAME AS ABOVE^^^^ return pVector->data + index;
}

void my_vector_destroy(MY_VECTOR* phVector)
{
	My_vector* pVector = (My_vector*)*phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
	printf("Destroyification complete!\n");
}
