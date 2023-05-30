#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculate active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, w;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (w = width - length; w > 0; w--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (w = width - length; w > 0; w--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints percent sign
 * @types: List of arguments
 * @buffer: Buffer array handle print
 * @flags:  Calculate active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars  to print
*/
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int o = BUFF_SIZE - 2;
	int is_negative = 0;
	long int q = va_arg(types, long int);
	unsigned long int num;

	q = convert_size_number(q, size);

	if (q == 0)
		buffer[o--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)q;

	if (q < 0)
	{
		num = (unsigned long int)((-1) * q);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[o--] = (num % 10) + '0';
		num /= 10;
	}

	o++;

	return (write_number(is_negative, o, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, p, y, sum;
	unsigned int j[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	j[0] = n / p;
	for (y = 1; y < 32; y++)
	{
		m /= 2;
		j[y] = (n / p) % 2;
	}
	for (y = 0, sum = 0, count = 0; y < 32; y++)
	{
		sum += j[y];
		if (sum || y == 31)
		{
			char z = '0' + j[y];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

