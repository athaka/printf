#include "main.h"

/**
 * print_int - Prints an integer
 * @output: List of arguments
 * @buffer: Buffer array to handle print
 * @alignment: Calculates active alignment
 * @output_width: Width of the output
 * @output_precision: Precision specification for the output
 * @output_size: Size specifier for the output
 * Return: Number of characters printed.
 */
int print_int(va_list output, char buffer[],
		int alignment, int output_width, int output_precision, int output_size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(output, long int);
	unsigned long int num;

	n = convert_size_number(n, output_size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_number(is_negative, i, buffer, alignment,
			output_width, output_precision, output_size));
}
