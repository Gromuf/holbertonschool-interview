#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

void print_error(void)
{
	printf("Error\n");
	exit(98);
}

int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, carry, n1, n2;
	int *result;

	if (argc != 3)
		print_error();
	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit(num1) || !is_digit(num2))
		print_error();
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = malloc(sizeof(int) * (len1 + len2));
	if (!result)
		return (1);
	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}
	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;
	if (i == len1 + len2)
		_putchar('0');
	
	for (; i < len1 + len2; i++)
		_putchar(result[i] + '0');
	_putchar('\n');
	free(result);
	return (0);
}
