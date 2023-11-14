#include "main.h"

/**
 * print_number - This is a custom function to print numbers
 * @num: The number to be printed
 * Return: value of the count
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

	return (count);
}

/**
 * print_binary - Print an unsigned integer in binary
 * @num: The unsigned integer to be printed
 * Return: returns the count of printed characters
 */
int print_binary(unsigned int num)
{
	int count = 0;

	if (num / 2 != 0)
	{
		count += print_binary(num / 2);
	}

	_putchar(num % 2 + '0');
	count++;

	return (count);
}

/**
 * print_number_unsign - Print an unsigned integer
 * @num: The unsigned integer to be printed
 * @base: The base for conversion
 * (8 for octal, 10 for decimal, 16 for hexadecimal)
 * @is_upper: Flag to indicate uppercase hexadecimal
 * (1 for uppercase, 0 for lowercase)
 * Return: returns the count of printed characters
 */
int print_number_unsign(unsigned int num, int base, int is_upper)
{
	int count = 0;
	int remainder = num % base;

	if (num / base != 0)
	{
		count += print_number_unsign(num / base, base, is_upper);
	}

	if (remainder < 10)
	{
		_putchar(remainder + '0');
	}
	else
	{
		_putchar(remainder - 10 + (is_upper ? 'A' : 'a'));
	}

	count++;

	return (count);
}

/**
 * print_non_printable - Print non-printable characters in the format \xHH
 * @c: The character to be printed
 * Return: returns the count of printed characters
 */
int print_non_printable(char c)
{
	int count = 0;
	char hex_digits[] = "0123456789ABCDEF";

	_putchar('\\');
	_putchar('x');
	_putchar(hex_digits[(c >> 4) & 0xF]);
	_putchar(hex_digits[c & 0xF]);
	count += 4;

	return (count);
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
					str = "null";
					count++;
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
			else if (*format == 'b')
			{
				unsigned int binary_num = va_arg(args, unsigned int);

				count += print_binary(binary_num);
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_number_unsign(num, 10, 0);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_number_unsign(num, 8, 0);
			}
			else if (*format == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_number_unsign(num, 16, 0);
			}
			else if (*format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_number_unsign(num, 16, 1);
			}
			else if (*format == 'S')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
				{
					char *nullStr = "(NULL)";

					while (*nullStr != '\0')
					{
						_putchar(*nullStr);
						nullStr++;
						count++;
					}
				}
				else
				{
					while (*str != '\0')
					{
						if (*str >= 32 && *str < 127)
						{
							_putchar(*str);
							count++;
						}
						else
						{
							count += print_non_printable(*str);
						}
						str++;
					}
				}
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);

				count += print_pointer(ptr);
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
