#include "main.h"

/**
 * _printf - A function that produces output according to a format.
 * @format: A pointer to the desired output format.
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_str(args);
					break;
				case '%':
					count += print_percent(args);
					break;
				case 'd':
				case 'i':
					count += print_int(args);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
