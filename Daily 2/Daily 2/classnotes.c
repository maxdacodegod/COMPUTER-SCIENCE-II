#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main(int argc, char* argv[])
{
	//struct date today; //Instantiation

	DATE hToday;

	//Member selection
	hToday = date_init_default();

	if (hToday == NULL)
	{
		printf("Failed to allocate space for object.\n");
		exit(1);
	}

	date_output(hToday);
	date_destroy(&hToday); hToday = NULL;
	date_output(hToday);

	return 0;
}

// Object is a thing, has attributes and can have abilities/Features

//What is a date? How do I represent it in a computer?