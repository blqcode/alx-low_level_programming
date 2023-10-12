#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - sums all its parameters
 * @n: number of parameters passed
 * Return: sum of all its parameters, 0 if no parameter passed
 */
int sum_them_all(const unsigned int n, ...)
{
	int total = 0;
	va_list args;
	int arg;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		arg = va_arg(args, int);
		total += arg;
	}
	va_end(args);

	return (total);

}
