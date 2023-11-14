#include "main.h"

/**
 * _printf - A function that produces specific output
 * @format: A pointer to the desired output format
 *
 * Return: Always 0.
 */

int _printf(const char *format, ...)
{
	va_list list_p;
	int to_print;

	if (format == NULL)
		return (-1);
	va_start(list_p, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			to_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				to_print++;
			}
			if (*format == 'c')
			{
				char c = va_arg(list_p, int);

				write(1, &c, 1);
				to_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_p, char*);

				write(1, str, strlen(str));
				to_print++;
			}
		}
		format++;
	}
	va_end(list_p);
	return (to_print);
}
