#include "palindrome.h"

/**
 * get_last - Find the amount ten elevated to digits in the number.
 * @number: number to  calculate lenght.
 *
 * Return: ten elevated to the number of digits in the number.
 */
unsigned long get_last(unsigned long number)
{
	unsigned long counter = 1;

	while (number / 10 != 0)
	{
		counter = counter * 10;
		number = number / 10;
	}

	return (counter);
}


/**
 * is_palindrome - check if a number it's a palindrome.
 * @n: Number to check.
 *
 * Return: 1 if it's a palindrome, 0 if doesn't.
 */
int is_palindrome(unsigned long n)
{
	unsigned long first = 1, last = get_last(n);
	int flag = 0;

	while (last > first)
	{
		if ((n / last) % 10 == (n % (first * 10)) / first && flag)
		{
			first = first * 10;
			last = last / 10;
		}
		else if ((n / last) / first == (n % (first * 10)) / first && flag == 0)
		{
			flag = 1;
			first = first * 10;
			last = last / 10;
		}
		else
		{
			return (0);
		}
	}

	return (1);
}
