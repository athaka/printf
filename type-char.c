#include "main.h"

/**
 * print_char - Prints a char
 * @output: List of arguments
 * @output_buffer: Buffer array to handle print
 * @active_flags: Calculates active flags
 * @output_width: Width of the output
 * @output_precision: Precision specification for the output
 * @output_size: Size specifier for the output
 * Return: Number of characters printed
 */
int print_char(va_list output, char output_buffer[],
		int active_flags, int output_width, int output_precision, int output_size)
{
	char character = va_arg(output, int);

	return (handle_write_char(character, output_buffer, active_flags,
				output_width, output_precision, output_size));
}
