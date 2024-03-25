#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"
int main(int argc, char* argv[])
{
	MY_VECTOR hVector;
	int i;

	hVector = my_vector_init_default();
	if (hVector == NULL)
	{
		printf("Failed to allocate space for MY_Vector Object\n");
		exit(1);
	}
	for (i = 0; i < 10; i++)
	{
		if (my_vector_push_back(hVector, i) == FAILURE)
		{
			printf("failed to push back value %d\n", i);
			exit(1);
		}
		printf("%d/%d\n", my_vector_get_size(hVector), my_vector_get_capacity(hVector));
	}
	*my_vector_at(hVector, 3) = 42;
	while (my_vector_is_empty(hVector) == FALSE)
	{
		printf("Pop! %d\n", *my_vector_at(hVector, my_vector_get_size(hVector) - 1 ));
		my_vector_pop_back(hVector);
	}
	my_vector_destroy(&hVector);
	return 0;
}
