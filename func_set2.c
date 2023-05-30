#include "main.h"

/***************** PRINT POINTER ******************/
/**
  * print_pointer - output the value of a pointer variable
  * @types: lists of args
  * @buffer: buffer array to handle print
  * @flags: computes active flags
  * @width: get width
  * @precision: precision specifier
  * @size: size specifier
  * Return: Number of chars printed.
  */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1; /* len=2, for '0x' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[padd], BUFF_SIZE - padd - 1));*/
	return (write_pointer(buffer, ind, len, width,
				flags, padd, extra_c, padd_start));
}

/******************** PRINT NON PRINTABLE ********************/
/**
  * print_non_printable - Computes ascii codes in hexa of non-printable chars
  * @types: List of args
  * @buffer: buffer array to handle print
  * @flags: ccomputes active flags
  * @width: get width
  * @precision: precision specifier
  * @size: size specifier
  * Return: Number of chars printed.
  */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int q = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[q] != '\0')
	{
		if (is_printable(str[q]))
			buffer[q + offset] = str[q];
		else
			offset += append_hexa_code(str[q], buffer, q + offset);

		q++;
	}

	buffer[q + offset] = '\0';

	return (write(1, buffer, q + offset));
}

/******************** PRINT REVERSE ********************/
/**
  * print_reverse – Outputs reverse string
  * @types: list of arguments
  * @buffer: buffer array to handle print
  * @flags: computes active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * Return: Number of chars printed.
  */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int h, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (h = 0; str[h]; h++)
		;

	for (h = h - 1; h >= 0; h--)
	{
		char z = str[h];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/******************** PRINT A STRING IN ROT13 ********************/
/**
  * print_rot13string - Output a string in rot13
  * @types: List of args
  * @buffer: buffer array to hold print
  * @flags: computes active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * Return: Numbers of chars printed
  */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, k;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[i])
			{
				x = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
