/***********************************************************
Author: Maxim Simakoff
Date: 1/22/24
Effort: 45 minutes
Purpose: The purpose of this assignment is to use Bitwise operators
in order to output the correct flag position which is displayed as 1.
The actual order is 31 (Maximum) down to 0 (Minimum) and the idea is, that 
you can call the set_flag function and place a flag at any desired place.
***********************************************************/

/***********************************************************
QUESTIONS:
What happens if you take the integer 13 and AND it with the number 0 ? What is the result ? 
0 whenever you preform bitwise AND with 0 it will always be 0.

What happens if you take the integer 13 and AND it with the number 4 ? What is the result ? Why ? 
13 is 1101 and 4 is 0100 which gives you 0100 which is 4

What if you AND 13 with 9 ?
13 is 1101 and 9 is 0100, this output gives you 9 or 1001

What happens if you take the integer 13 and OR it with the number 0 ? What is the result ?
When bitwise OR is performed the result is the original number which is 13

What happens if you take the integer 13 and OR it with the number 2 ? What is the result ?
13 is 1101 and 2 is 0010, bitwise or will give you 1111 which is 15.

Which of the above operators based on your answers will be more useful for our set_flag
function ?
The OR and left shift operator are useful for the set_flag function.

***********************************************************/

#include <stdio.h>

void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

void set_flag(int* pFlag_holder, int flag_position)
{
	*pFlag_holder = *pFlag_holder | (1 << flag_position);
}
int check_flag(int flag_holder, int flag_position)
{
	return (flag_holder >> flag_position) & 1;
}

// Bitwise Operators: 
// & Bitwise AND
// | Bitwise OR
// << Left shift
// >> Right Shift