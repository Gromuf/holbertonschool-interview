#include "palindrome.h"

/**
 * is_palindrome - Checks if a given unsigned long integer is a palindrome.
 * @n: The number to check.
 *
 * Description:
 * A palindrome number reads the same backward and forward.
 * This function reverses the digits of the given number
 * and compares the reversed value with the original one.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;
	unsigned long reminder;

	while (n!=0)
	{
		reminder = n % 10;
		reversed = reversed * 10 + reminder;
		n /= 10;
	}

	if (original == reversed)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}