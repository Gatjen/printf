#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...) 
{
va_list args;
va_start(args, format);

int count = 0;
const char *ptr = format;

while (*ptr)
{
if (*ptr == '%')
{
ptr++;
if (*ptr == 'c')
{
int c = va_arg(args, int);
putchar(c);
count++;
}
else if (*ptr == 's')
{
const char *str = va_arg(args, const char *
while (*str)
{
putchar(*str);
str++;
count++;
}
}
else if (*ptr == '%')
{
putchar('%');
count++;
}
}
 else
{
putchar(*ptr);
count++;
}
ptr++;
}
va_end(args);
return count;
}

