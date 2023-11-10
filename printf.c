#include "main.h"

/**
 * _printf - A custom printf function
 * @format: This is the format of the text to be printed
 * Return: returns the value of the word count
*/

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

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

/**
 * main - main function to test our printf function
*/

int main()
{
	int characters_printed = _printf("The character is %c and the string is %s. This is a %% sign.\n", 'A', "Hello, World!");

	printf("\nTotal characters printed: %d\n", characters_printed);
	return (0);
}
