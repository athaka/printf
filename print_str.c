#include "main.h"

/**
 * print_str - Prints a string.
 * @args: A va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	while (str[len] != '\0')
		len++;
	write(1, str, len);
	return (len);
}
