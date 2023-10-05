#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number to multiply
 * @num2: The second number to multiply
 */
void multiply(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int total_length = len1 + len2;
	char *result = allocate_memory(total_length + 1);
	int carry = 0;

	reverse_string(num1);
	reverse_string(num2);

	for (int i = 0; i < len1; i++)
	{
		carry = 0;

		for (int j = 0; j < len2; j++)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';

			int temp = (result[i + j] - '0') + (digit1 * digit2) + carry;
			result[i + j] = (temp % 10) + '0';
			carry = temp / 10;
		}

		result[i + len2] += carry;
	}

	reverse_string(result);
	printf("%s\n", result);

	free(result);
}

/**
 * is_positive_number - Checks if a string represents a positive number
 * @num: The string to check
 *
 * Return: 1 if the string represents a positive number, 0 otherwise
 */
int is_positive_number(const char *num)
{
	for (int i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * print_error_and_exit - Prints an error message and exits with status 98
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * reverse_string - Reverses a string in place
 * @str: The string to reverse
 */
void reverse_string(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;

	while (i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

/**
 * add_strings - Adds a number string to the result string
 * @result: The result string
 * @num: The number string to add
 */
void add_strings(char *result, char *num)
{
	int carry = 0;
	int len = strlen(num);

	for (int i = 0; i < len; i++)
	{
		int digit = result[i] - '0' + num[i] - '0' + carry;
		result[i] = (digit % 10) + '0';
		carry = digit / 10;
	}

	while (carry)
	{
		result[len] = (carry % 10) + '0';
		carry /= 10;
		len++;
	}

	result[len] = '\0';
}

/**
 * allocate_memory - Allocates memory dynamically
 * @size: The size of the memory to allocate
 *
 * Return: Pointer to the allocated memory
 */
char *allocate_memory(int size)
{
	char *ptr = malloc(size * sizeof(char));
	if (ptr == NULL)
	{
		print_error_and_exit();
	}
	return (ptr);
}
