#include "main.h"
#include <unistd.h>

/**
 * print_percent - Prints a percent sign.
 * @args: A va_list (unused).
 *
 * Return: Always 1 (the percent sign).
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
