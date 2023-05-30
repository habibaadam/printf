#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - custom Printf function
 * @formfier: the format specifier
 * Return: the number of characters Printed
 */
int _printf(const char *formfier, ...)
{
	int h, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (formfier == NULL)

		return (-1);
	va_start(list, formfier);
	for (h = 0; formfier && formfier[h] != '\0'; h++)
	{
		if (formfier[h] != '%')
		{
			buffer[buff_ind++] = form[h];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &formfier[h], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(formfier, &h);
			width = get_width(formfier, &h, list);
			precision = get_precision(formfier, &h, list);
			size = get_size(formfier, &h);
			++h;
			printed = handle_print(formfier, &h, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffray - Prints the contents of the buffer if it exist
 * @buffray: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffray(char buffray[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffray[0], *buff_ind);
	*buff_ind = 0;
}

