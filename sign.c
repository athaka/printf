#include "main.h"

/**
 * print_percent - Prints a percent sign
 * @output: List of arguments
 * @buffer: Buffer array to handle print
 * @active_flags: Calculates active alignment
 * @output_width: Width of the output
 * @output_precision: Precision specification for the output
 * @output_size: Size specifier for the output
 * Return: Number of characters printed.
 */
int print_percent(va_list output, char buffer[],
		int active_flags, int output_width, int output_precision, int output_size)

{
	UNUSED(output);
	UNUSED(buffer);
	UNUSED(active_flags);
	UNUSED(output_width);
	UNUSED(output_precision);
	UNUSED(output_size);
	return (write(1, "%%", 1));
}
