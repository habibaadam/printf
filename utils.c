#include "main.h"

/**
 * isPrintable - Evaluates if a char is printable
 * @car: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int isPrintable(char car)
{
	if (car >= 32 && car < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @ind: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int ind)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[ind++] = '\\';
	buffer[ind++] = 'x';

	buffer[ind++] = map_to[ascii_code / 16];
	buffer[ind] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @car: Char to be evaluated
 *
 * Return: 1 if car is a digit, 0 otherwise
 */
int is_digit(char car)
{
	if (car >= '0' && car <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @numb: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of numb
 */
long int convert_size_number(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @nu: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of nu
 */
long int convert_size_unsgnd(unsigned long int nu, int size)
{
	if (size == S_LONG)
		return (nu);
	else if (size == S_SHORT)
		return ((unsigned short)nu);

	return ((unsigned int)nu);
}
