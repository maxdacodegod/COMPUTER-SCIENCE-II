#include <stdio.h>

char* reverse(char* word);


char* reverse(char* word)
{
	int length = 0;

	while (word[length] != '\0') 
	{
		length++;
	}

	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = word[start];
		word[start] = word[end];
		word[end] = temp;
		start++;
		end--;
	}
	return word;
}