/**********************************************************************
Program: Program 3
Author: Maxim Simakoff
Date: 4/17/24
Time spent: This program took roughly 6 hours combined to write
Purpose: The purpose of this program is to take random inputs from the keyboard of numbers, up to 2 billion inputs total.
The program ignores duplicated numbers and prints least to greatest. This is achieved by using the bit flags to solve.
***********************************************************************/

//	Write a program that will filter a list of non - negative integers such that all duplicate values are
//	removed.Integer values will come from standard input(the keyboard) and will range in value
//	from 0 up to 2, 000, 000, 000. Input will be terminated by the special value, -1.
//	Once the input is read in you should output(to the screen) the list of numbers as a sorted list
//	(smallest to largest) with one value listed per line where all duplicates have been removed.The
//	primary difficulty with this program is that there are an enormous number of input values and an
//	expected large number of duplicate numbers.
//	Hint: A tree cannot solve this problem if all 2 billion numbers are different since we will run out of RAM.

// SAMPLE INPUT
// Input -  4 4 4 3 3 3 2 2 2 1 1 1 -1
// Output - 1 2 3 4 
// Sorted Least to Greatest and duplicates ignored

//BITWISE OPERATORS to check if it is a duplicate

#include <stdio.h>
#include <stdlib.h>
#include "bitflags.h"

int main(int argc, char* argv[])
{
	BIT_FLAGS hBit_flags = NULL;
	int num;
	int i;
	hBit_flags = bit_flags_init_number_of_bits(2000000000);
	if (hBit_flags == NULL)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
	scanf("%d", &num);
	while (num != -1) // Take inputs until -1
	{
		bit_flags_set_flag(hBit_flags, num);
		scanf("%d", &num);
	}
	//print
	for (i = 0; i < bit_flags_get_size; i++)
	{
		if (bit_flags_check_flag(hBit_flags, i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}


/*
int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };
	//Set the first integer to zero and all others
	//to zero by default.

	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);
	display_flags(flag_holder, 5);

	printf("\n\n");

	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);
	display_flags(flag_holder, 5);

	return 0;
}
*/