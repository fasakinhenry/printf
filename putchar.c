#include "main.h"

/**
 * _putchar - A custom putchar function to print characters
 * @c: Character to be printed
 * Return: Character to be prnted
*/

int _putchar(char c)
{
	char buffer[1024];

	buffer[0] = c;
	if ((write(STDOUT_FILENO, buffer, 1) == -1))
	{
		return (-1);
	}

	return (1);
}
