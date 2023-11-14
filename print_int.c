#include "main.h"

/**
 * print_int - Prints an integer.
 * @args: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int len = sprintf(buffer, "%d", num);

	write(1, buffer, len);
	return (len);
}
