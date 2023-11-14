#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/* Function prototypes for format specifiers */
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
