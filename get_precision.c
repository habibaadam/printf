#include "main.h"

/**
  * get_precision - Entry point
  * Description – ‘calculates precision for printing’
  * @format: format string containing specifier
  * @i: pointer to current position in format string
  * @list: list of arguments to be printed
  * Return: Precision.
  */
int get_precision(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int precision = -1;

	/* Check if precision if specified */
	if (format[j] != '.')
		return (precision);

	precision = 0;

	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			precision *= 10;
			precision += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (precision);
}
