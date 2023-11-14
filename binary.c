#include "main.h"

/**
 * print_binary - Prints an unsigned number in binary notation
 * @output: List of arguments
 * @buffer: Buffer array to handle print
 * @active_flags: Calculates active alignment
 * @output_width: Width of the output
 * @output_precision: Precision specification for the output
 * @output_size: Size specifier for the output
 * Return: Number of characters printed.
 */
int print_binary(va_list output, char buffer[],
		int active_flags, int output_width, int output_precision, int output_size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(active_flags);
	UNUSED(output_width);
	UNUSED(output_precision);
	UNUSED(output_size);

	n = va_arg(output, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}
