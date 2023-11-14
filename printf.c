#include "main.h"

/**
 * print_number - This is a custom function to print numbers
 * @num: The number to be printed
 */
int print_number(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num / 10 != 0)
	{
		count += print_number(num / 10);
	}

	_putchar(num % 10 + '0');
	count++;

	return count;
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
	if (format == NULL)
		return (-1);
	if (!format || format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == ' ')
			{
				return (-1);
			}
			else if (*format == '\0')
			{
				return (-1);
			}
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
				{
					_putchar('(');
					_putchar('N');
					_putchar('U');
					_putchar('L');
					_putchar('L');
					_putchar(')');
					count += 6;
				}
				else
				{
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
						count++;
					}
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

				count += print_number(num);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
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
