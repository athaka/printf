#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function to handle %c, %s, and %%
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...) {
    va_list args;
    int count = 0; 

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            switch (*(format + 1)) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar(*format);
                    count++;
                    break;
            }
            format += 2; 
        } else {
            putchar(*format);
            count++;
            format++;
        }
    }

    va_end(args);
    return count;
}
