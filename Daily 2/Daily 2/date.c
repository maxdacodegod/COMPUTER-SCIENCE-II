//Implentation File
#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct date	//Known type
{
	int month;
	int day;
	int year;
};

typedef struct date Date;

DATE date_init_default(void)
{
	Date* pDate;
	pDate = (Date*)malloc(sizeof(Date));
	if (pDate != NULL)
	{
		pDate->month = 1;
		pDate->day = 1;
		pDate->year = 1970;
	}
	return (DATE)pDate;
}


void date_output(DATE hDate)
{
	Date* pDate = (Date*) hDate; // Casting to the Known Type
	printf("%d/%d/%d \n", pDate->month, pDate->day, pDate->year);
}

void date_destroy(DATE* phDate)
{
	Date* pDate = (Date*)*phDate; // Casting to the Known Type
	//Clean up any mess that the object made itself
	free(pDate);
	*phDate = NULL;
	printf("Destroyification Complete!\n");
}
