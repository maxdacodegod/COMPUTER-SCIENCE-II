#include <stdio.h>
#include <stdlib.h>
#include "bitflags.h"

typedef struct bit_flags Bit_flags;
struct bit_flags {
	int size;
	int capacity;
	int* flags;
};

const int BITS_IN_INT = sizeof(int) * 8; //Magic Number 32

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	Bit_flags* pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	int num_ints = (number_of_bits + BITS_IN_INT - 1) / BITS_IN_INT;
	int i;
	if (pBit_flags != NULL)
	{
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = num_ints * BITS_IN_INT;
		pBit_flags->flags = (int*)malloc(num_ints * sizeof(int));;

		if (pBit_flags->flags == NULL)
		{
			free(pBit_flags);
			return NULL;
		}
		for (i = 0; i < num_ints; i++)
		{
			pBit_flags->flags[i] = 0;
		}
	}
	return pBit_flags;
}
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index = flag_position / (BITS_IN_INT);
	int bit_position = flag_position % (BITS_IN_INT);
	int* temp = NULL;
	int i;
	if (flag_position >= pBit_flags->capacity)
	{
		int new_capacity = ((flag_position / BITS_IN_INT) + 1) * BITS_IN_INT;
		temp = (int*)realloc(pBit_flags->flags, sizeof(int) * new_capacity / BITS_IN_INT);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = pBit_flags->capacity / BITS_IN_INT; i < new_capacity / BITS_IN_INT; i++)
		{
			temp[i] = 0;
		}
		pBit_flags->flags = temp;
		pBit_flags->capacity = new_capacity;
	}
	if (flag_position >= pBit_flags->size)
	{
		pBit_flags->size = flag_position + 1;
	}
	pBit_flags->flags[index] |= (1 << bit_position);
	return SUCCESS;
}
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index = flag_position / (BITS_IN_INT);
	int bit_position = flag_position % (BITS_IN_INT);
	int* temp = NULL;
	int i;
	if (flag_position >= pBit_flags->capacity)
	{
		int new_capacity = ((flag_position / BITS_IN_INT) + 1) * BITS_IN_INT;
		temp = (int*)realloc(pBit_flags->flags, sizeof(int) * new_capacity / BITS_IN_INT);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = pBit_flags->capacity / BITS_IN_INT; i < new_capacity / BITS_IN_INT; i++)
		{
			temp[i] = 0;
		}
		pBit_flags->flags = temp; // Set the data
		pBit_flags->capacity = new_capacity; // Set the new capacity
	}
	if (flag_position >= pBit_flags->size)
	{
		pBit_flags->size = flag_position + 1;
	}
	pBit_flags->flags[index] &= ~(1 << bit_position);
	return SUCCESS;
}
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index = flag_position / (BITS_IN_INT);
	int bit_position = flag_position % (BITS_IN_INT);
	if (flag_position < pBit_flags->size)
	{
		return (pBit_flags->flags[index] >> bit_position) & 1;
	}
	else
	{
		return -1;
	}
}
int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->size;
}
int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->capacity;
}
void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
	if (pBit_flags->flags != NULL)
	{
		free(pBit_flags->flags);
	}
	if (pBit_flags != NULL)
	{
		free(pBit_flags);
		*phBit_flags = NULL;
	}
	printf("Destroyification complete! \n");
}