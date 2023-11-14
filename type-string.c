#include "main.h"

/**
 * print_string - Prints a string
 * @output: List of arguments
 * @buffer: Buffer array to handle print
 * @active_flags: Calculates active flags
 * @output_width: Width of the output
 * @output_precision: Precision specification for the output
 * @output_size: Size specifier for the output
 * Return: Number of characters printed
 */
int print_string(va_list output, char buffer[],
		int active_flags, int output_width, int output_precision, int output_size)
{
	int length = 0, i;
	char *str = va_arg(output, char *);

	UNUSED(buffer);
	UNUSED(active_flags);
	UNUSED(output_width);
	UNUSED(output_precision);
	UNUSED(output_size);

	if (str == NULL)
	{
		str = "(null)";
		if (output_precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (output_precision >= 0 && output_precision < length)
		length = output_precision;
	if (output_width > length)
	{
		if (active_flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = output_width - length; i > 0; i--)
				write(1, " ", 1);
			return (output_width);
		}
		else
		{
			for (i = output_width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (output_width);
		}
	}

	return (write(1, str, length));
}
