#include "main.h"

/**
 * get_flags - Entry point
 * Description – ‘determines active flags’
 * @format: formatted string
 * @r: takes a parameter
 * Return: the active flag determined from format specifier
 */
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int get_flags(const char *format, int *r)
{

	int l, j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (j = *r + 1; format[j] != '\0'; j++)
	{
		for (l = 0; FLAGS_CH[l] != '\0'; l++)
			if (format[j] == FLAGS_CH[l])
			{
				flags |= FLAGS_ARR[l];
				break;
			}

		if (FLAGS_CH[l] == 0)
			break;
	}

	*r = j - 1;

	return (flags);
}
