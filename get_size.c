#include "main.h"

/**
 * get_size - Calculates the size to cast argument
 * @format: string formatted to print the args
 * @h: list of arguments
 *
 * Return: Precision (Successful)
 */
int get_size(const char *format, int *h)
{
	int curr_h = *h + 1;
	int size = 0;

	if (format[curr_h] == 'l')
		size = S_LONG;
	else if (format[curr_h] == 'w')
		size = S_SHORT;

	if (size == 0)
		*h = curr_h - 1;
	else
		*h = curr_h;

	return (size);
}
