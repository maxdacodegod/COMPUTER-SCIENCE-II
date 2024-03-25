#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int numbers[], int size, int (*fpcompare)(int a, int b));
void my_swap(int* a, int* b);
int less_than(int a, int b);
int greater_than(int a, int b);
int favor_odds(int a, int b);
int i_love_prime_numbers(int a, int b);
int is_prime(int n);

int main(int argc, char* argv[])
{
	//int numbers[] = { 4, 7, 8, 9, 0, 3, 6, 2, 1, 5};
	int numbers[100];
	int n;
	for (n = 0; n < 100; n++)
	{
		numbers[n] = rand();
	}

	// BUBBLE SORT	
	int i;
	bubble_sort(numbers, 100, i_love_prime_numbers);

	//int (*fpcompare)(int a, int b); // Function pointer
	
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", numbers[i]);
	}
	return 0;
}
void bubble_sort(int numbers[], int size, int (*fpcompare)(int a, int b))
{
	int i;
	int j;
	for (i = 0; i < size - 1; i++) // n - 1
	{
		for (j = 0; j < size - 1; j++) // To not go out of bounds
		{
			//if (numbers[j + 1] < numbers[j]) // START HERE
			if(fpcompare(numbers[j+1], numbers[j]))
			{
				my_swap(&numbers[j], &numbers[j+1]);
			}
		}
	}
}
void my_swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int less_than(int a, int b)
{
	return a < b;
}
int greater_than(int a, int b)
{
	return a > b;
}
int favor_odds(int a, int b)
{
	if (a % 2 == b % 2)
	{
		return a < b;
	}
	else
	{
		return a % 2 == 1;
	}
}
int i_love_prime_numbers(int a, int b)
{
	int left_is_prime = is_prime(a);
	int right_is_prime = is_prime(b);
	if (left_is_prime == right_is_prime)
	{
		return a < b;
	}
	else
	{
		return left_is_prime;
	}
}
int is_prime(int n)
{
	int prime = 1;
	int i;
	if (n < 2)
	{
		return 0;
	}
	else
	{
		if (n == 2)
		{
			return 1;
		}
		else
		{
			for (i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					prime = 0;
				}
			}
		}
	}
	return prime;
}


/*
void say_hello(void);
void say_hola(void);
void say_bonjour(void);
void say_gutentag(void);
void say_privet(void);

void some_function(void (*fp_greeting)(void));

int sum(int a, int b);


int main(int argc, char* argv[])
{
	//Make an array of all of our greetings
	// Array of all unit test functions
	void (*fp_greeting[])(void) = { say_hello, say_hola, say_bonjour, say_gutentag, say_privet };
	int i;
	// TEST SPECIFICATIONS NOT CODE
	for (i = 0; i < sizeof(fp_greeting) / sizeof(*fp_greeting); i++)
	{
		fp_greeting[i]();
	}
	//some_function(say_hola);

	//printf("%p",say_hello); // ADDRESS of Function
	//void (*fp_greeting)(void); // fp_greeting is a pointer to a function that accepts void and that returns void

	//int (*fp_sum)(int, int); // Another Example with type int.

	//fp_greeting = say_aloha;
	//fp_greeting();

	return 0;
}

void say_hello(void)
{
	printf("Hello\n");
}
void say_hola(void)
{
	printf("Hola\n");
}
void say_bonjour(void)
{
	printf("bonjour\n");
}
void say_gutentag(void)
{
	printf("Gutentag\n");
}
void say_privet(void)
{
	printf("Privet\n");
}
void some_function(void (*fp_greeting)(void))
{
	fp_greeting();
	printf("work\n");
}
*/