#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - My personal printf function
 * @format: format by emtolalaa
 * Return: emto's chars that are printed.
 */
int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	va_list list;
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;


	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flag_emto(format, &i);
			width = get_width_emto(format, &i, list);
			precision = get_precision_emto(format, &i, list);
			size = get_size_emto(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
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
 * print_buffer - To only output existing buffers
 * @buffer: Characters in Array form
 * @buff_ind: This would represent the length and index for the chars.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
