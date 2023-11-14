#include "main.h"

/**
 * print_pointer - Print a pointer address in hexadecimal
 * @ptr: The pointer to be printed
 * Return: returns the count of printed characters
 */
int print_pointer(void *ptr)
{
	int count = 0;
	unsigned long int address = (unsigned long int)ptr;
	char hex_digits[] = "0123456789abcdef";

	_putchar('0');
	_putchar('x');
	count += 2;

	if (ptr == NULL)
	{
		_putchar('0');
		count++;
	}
	else
	{
		int i;

		for (i = (sizeof(void *) * 8) - 4; i >= 0; i -= 4)
		{
			_putchar(hex_digits[(address >> i) & 0xf]);
			count++;
		}
	}

	return (count);
}
