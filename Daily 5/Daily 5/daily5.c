/***********************************************************
Author: Maxim Simakoff
Date: 1/28/24
Effort: 3 Hours
Purpose: The purpose of this program is slightly different than daily 4, this program changed
from singular bits to storing a long array of bits. We have 5 total lines, 32 bits per line, 
which totals to 160 different "Light Switchs" or Flags you can turn on/off by passing in the 
index to the set_flag function.
***********************************************************/
/***********************************************************
You may want to be careful about how you call your check_flag function from inside 
the display_flags_as_array function since that function receives an integer and check_flag 
is expecting an array. How can you overcome this obstacle ?

Display flags function passes flag_holder[i] or flag_holder at the i index.
Next the display_flags_as_array accepts that flag_holder and then passes the address of 
the flagholder as well as the index into the check_flag function.
***********************************************************/
#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

const int integer_size = sizeof(int) * 8; //Magic Number 32

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

void set_flag(unsigned int flag_holder[], int flag_position)
{
	flag_holder[flag_position / integer_size] |= (1 << (flag_position % integer_size));
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
	flag_holder[flag_position / integer_size] &= ~(1 << (flag_position % integer_size));
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
	return (flag_holder[flag_position / integer_size] >> flag_position % integer_size) & 1;
}

void display_flags_as_array(unsigned int flag_holder)
{
	int i;
	for (i = 0; i < integer_size; i++)
	{
		printf("%d", check_flag(&flag_holder, i));
		if ((i+1) % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		display_flags_as_array(flag_holder[i]);
	}
	printf("\n");
}