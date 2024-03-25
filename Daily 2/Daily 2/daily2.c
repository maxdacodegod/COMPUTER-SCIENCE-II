/***********************************************************
Author: Maxim Simakoff
Date: 1/19/24
Effort: 5 minutes
Purpose: The purpose of this program is to left shift a variable x that is assigned the value of 1
at the start of the program and then stop left shifting x when x is 0.

Questions:
What mathematical operation is a left shift by 1 equivalent to?
Similar to *2 operator except left shift is faster than *2 when compiling.

Why does it make no sense to left shift by a number greater than 32 for 32 bit numbers?
It doesnt make any sense because you are trying to shift a 32 bit number beyond its boundaries.
***********************************************************/
/*
#include <stdio.h>

int main(int argc, char* argv[])
{
	int x = 1;
	int i = 0;
	for (i = 0; x!= 0; i++)
	{
		printf("%d:%u\n", i, x);
		x = x << 1;
	}
	return 0;
}
*/