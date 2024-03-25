#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "generic.h"
struct generic_vector
{
	int size;
	int capacity;
	ITEM* data;
	void (*fp_destroy)(ITEM* phItem);
	ITEM(*fp_init_copy)(ITEM hItem);
};
typedef struct generic_vector Generic_vector;
GENERIC_VECTOR generic_vector_init_default(
	void (*fp_destroy)(ITEM* phItem),
	ITEM(*fp_init_copy)(ITEM hItem))
{
	Generic_vector* pVector = (Generic_vector*)malloc(sizeof(Generic_vector));

	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->fp_init_copy = fp_init_copy;
		pVector->fp_destroy = fp_destroy;
		pVector->data = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
	}
	return pVector;
}
int generic_vector_get_size(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->size;
}
int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->capacity;
}
Boolean generic_vector_is_empty(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return (pVector->size <= 0) ? TRUE : FALSE;
}

ITEM generic_vector_at(GENERIC_VECTOR hVector, int index)
{
	Generic_vector* pVector = (Generic_vector*)hVector;

	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}
	return pVector->data[index];
	
}
Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM hItem)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	ITEM* temp;
	int i;
	if (pVector->size >= pVector->capacity)//if there is no room make room
	{
		temp = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity * 2);
		if(temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];//Shallow copy
		}
		free(pVector->data);
		pVector->data = temp;
		pVector->capacity *= 2;
	}
	//pVector->data[pVector->size] = hItem; //Old way...NOT SAFE
	pVector->data[pVector->size] = pVector->fp_init_copy(hItem);//DEEP COPY - Delegating a request to allocate memory
	if (pVector->data[pVector->size] == NULL)
	{
		return FAILURE;
	}
	pVector->size++;
	return SUCCESS;
}
Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (generic_vector_is_empty(hVector))
	{
		return FAILURE;
	}
	//pVector->fp_destroy(&(pVector->data[pVector->size - 1])); // same as one below, preference based.
	pVector->fp_destroy(pVector->data + pVector->size - 1);
	pVector->size--;
	return SUCCESS;
}
void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
	Generic_vector* pVector = (Generic_vector*)*phVector; 
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
	printf("Destroyification complete!\n");
}