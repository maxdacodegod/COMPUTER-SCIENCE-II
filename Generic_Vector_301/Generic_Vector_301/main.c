#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

//STEP 1 void destroy_function(void** phItem);
void integer_destroy(ITEM* phItem); //STEP 2 

ITEM integer_init_copy(ITEM hItem); //returns handle to object we made

int main(int argc, char* argv[])
{
	GENERIC_VECTOR hVector;
	int i;
	int j;

	hVector = generic_vector_init_default(integer_init_copy, integer_destroy);
	if (hVector == NULL)
	{
		printf("FAIL");
		exit(1);
	}
	for (i = 0; i < 10; i++)
	{
		generic_vector_push_back(hVector, &i);
		printf("%d/%d\n", generic_vector_get_size(hVector), generic_vector_get_capacity(hVector));
	}
	generic_vector_at(hVector, 42);
	for (j = 0; j < 10; j++)
	{
		printf("%d\n", *(int*)generic_vector_at(hVector, j));
	}
	generic_vector_destroy(&hVector);
}

void integer_destroy(ITEM* phItem)
{
	int* pInt = (int*)*phItem;
	free(pInt);
	*phItem = NULL;
	printf("INTEGER Destroyification complete!\n");
}

ITEM integer_init_copy(ITEM hItem)
{
	int* pInt;
	int* pArg = (int*)hItem; //Cast to known type

	pInt = (int*)malloc(sizeof(int));
	if (pInt != NULL)
	{
		*pInt = *pArg;
	}
	return pInt;
}