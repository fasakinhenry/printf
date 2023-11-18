#include "main.h"

/**
 * print_reverse - Print the reverse of a string
 * @str: The string to be printed in reverse
 * Return: returns the count of printed characters
 */
int print_reverse(const char *str)
{
	int count = 0;
	int i;

	if (str == NULL)
		return 0;
	while (str[count] != '\0')
		count++;
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(str[i]);
	}

	return (count);
}
