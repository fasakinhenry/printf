#include "main.h"

/**
 * hex_digit - Convert a decimal digit to its hexadecimal representation
 * @digit: The decimal digit (0-15)
 * Return: The corresponding hexadecimal character
 */
char hex_digit(int digit)
{
	if (digit >= 0 && digit <= 9)
	{
		return (digit + '0');
	}
	else
	{
		return (digit - 10 + 'a');
	}
}

/**
 * print_hex_address - Print the hexadecimal representation of an address
 * @address: The address to be printed
 * Return: returns the count of printed characters
 */
int print_hex_address(unsigned long int address)
{
	int count = 0;

	if (address == 0)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		count += 5;
	}
	else
	{
		unsigned long int divisor = 1;
		int leading_zeros = 0;

		_putchar('0');
		_putchar('x');
		count += 2;

		while (divisor <= address / 16)
		{
			divisor *= 16;
		}
		while (divisor > 0)
		{
			int digit = address / divisor;

			if (digit > 0 || leading_zeros || divisor == 1)
			{
				_putchar(hex_digit(digit));
				count++;
				leading_zeros = 1;
			}

			address %= divisor;
			divisor /= 16;
		}
	}
	return (count);
}

/**
 * print_pointer - Print a pointer address
 * @ptr: The pointer to be printed
 * Return: returns the count of printed characters
 */
int print_pointer(void *ptr)
{
	int count = 0;
	unsigned long int address = (unsigned long int)ptr;

	if (ptr == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		count += 5;
	}
	else
	{
		_putchar('0');
		_putchar('x');
		count += 2;
		count += print_hex_address(address);
	}

	return (count);
}
