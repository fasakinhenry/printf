#include "main.h"

/**
 * print_number - This is a custom function to print numbers
 * @num: The number to be printed
*/
void print_number(int num)
{
	int digits = 1;
	int temp = num;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	while (temp /= 10)
	{
		digits *= 10;
	}

	while (digits >= 1)
	{
		_putchar((num / digits) + '0');
		num %= digits;
		digits /= 10;
	}
}

int _printf(const char *format, ...);

/**
 * _printf - A custom printf function
 * @format: This is the format of the text to be printed
 * Return: returns the value of the word count
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				int temp = num;

				print_number(num);
				while (temp != 0)
				{
					count++;
					temp /= 10;
				}
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
