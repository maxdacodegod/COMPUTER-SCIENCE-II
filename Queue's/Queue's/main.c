/**********************************************************************
Program: Program 2 - Ferry Loading
Author: Maxim Simakoff
Date: 3/11/24
Time spent: 9 Hours
Purpose: The purpose of this program is to properly transport cars from one side of a bridge to another
(Left and Right). The test case provides the boat length in meters and then car lengths in centimeters 
which are taken into the boat as long as they do not pass the maximum length of the boat. The result is how
many trips/passes the boat does "under" the bridge.
***********************************************************************/


//Problem 11034
// c = Number of Test Cases
// l = length in centimeters
// m = how many cars

// Boat starts on Left side FOR EVERY CASE
// 4 - Number of Test cases
// 20 4 - Boat is 20 Meters and How many lines are after this statement
// 380 left - 380 CM Starting on left
// 720 left - 720 CM Starting on left
// 1340 right - 1340 CM Starting on right
// 1040 left - 1040 CM Starting on left
// 
// This cross 3 times
// M to CM = *100

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	int results[10];
	int result_index = 0;
	QUEUE left_hQ;
	QUEUE right_hQ;
	Status status = SUCCESS;
	int c;
	int i = 0;

	scanf("%d", &c); //Test case read

	for (i = c; i > 0; i--) // Per test case, Runs 4 times
	{
		int trips = 0;
		int boat_length = 0;
		scanf("%d", &boat_length);
		boat_length = boat_length * 100; // Convert to CM

		int lines_in_case = 0;
		scanf("%d", &lines_in_case); // 4 Lines

		left_hQ = queue_init_default();
		right_hQ = queue_init_default();

		if (left_hQ == NULL || right_hQ == NULL)
		{
			printf("Failed to allocate memory");
			exit(1);
		}

		int j = 0;
		for (j = 0; j < lines_in_case; j++)
		{
			int car_length = 0;
			char str[6];
			char left[] = "left";
			scanf("%d ", &car_length);

			scanf("%s", str);

			//add to queue
			int same = 1;
			int k = 0;
			for (k = 0; k < 4; k++)
			{
				if (str[k] != left[k])
				{
					same = 0;
					break;
				}
			}
			if (same)
			{
				queue_insert(left_hQ, car_length);
			}
			else
			{
				queue_insert(right_hQ, car_length);
			}
			str[0] = '\0'; // Reset String
		}

		int original_boat_length = boat_length;
		int side = 0; // 0 is Left and 1 is Right

		while (!queue_is_empty(left_hQ) || !queue_is_empty(right_hQ)) // Run while both queues are not empty
		{
			int car_length = 0;

			if (side == 0 && !queue_is_empty(left_hQ))
			{
				while (!queue_is_empty(left_hQ) && boat_length >= (car_length + queue_front(left_hQ, &status))) //Pick up as many boats as possible
				{
					// Account of total car length and remove that car from the road and add to boat
					car_length += queue_front(left_hQ, &status);
					queue_service(left_hQ);
				}
				trips++; // Account for trip
				side = 1; // Move to the right side
			}
			else if (side == 1 && !queue_is_empty(right_hQ))
			{
				while (!queue_is_empty(right_hQ) && boat_length >= (car_length + queue_front(right_hQ, &status))) //Pick up as many boats as possible
				{
					// Account of total car length and remove that car from the road and add to boat
					car_length += queue_front(right_hQ, &status);
					queue_service(right_hQ);
				}
				trips++; // Account for trip
				side = 0; // Move to the left side
			}
			else
			{
				trips++;
				if (side == 0)
				{
					side = 1; // Move to the right side
				}
				else
				{
					side = 0; // Move to the left side
				}
			}
			boat_length = original_boat_length; // Reset boat length to original after each trip
		}
		results[result_index++] = trips;
		queue_destroy(&right_hQ);
		queue_destroy(&left_hQ);
	}
	printf("\n");
	for(i = 0; i < result_index; i++) 
	{
		printf("%d\n", results[i]);
	}
	return 0;
}