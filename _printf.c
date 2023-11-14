#include "main.h"

/**
<<<<<<< HEAD
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
=======
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
>>>>>>> j-printf
	{
		if (*format != '%')
		{
			write(1, format, 1);
<<<<<<< HEAD
			to_print++;
=======
			count++;
>>>>>>> j-printf
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
<<<<<<< HEAD
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
=======
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
>>>>>>> j-printf
			}
		}
		format++;
	}
<<<<<<< HEAD
	va_end(list_p);
	return (to_print);
=======
	va_end(args);
	return (count);
>>>>>>> j-printf
}
