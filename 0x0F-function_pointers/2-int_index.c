#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array
 * @array: target array
 * @size: size of the array
 * @cmp: function for comparing values
 * Return: index of the first element that has the integer,
 * if integer is not in the array, return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		if (size <= 0)
			return (-1);

		for (i = 0; i < size; i++)
			if (cmp(array[i]))
				return (i);
	}

	return (-1);
}
