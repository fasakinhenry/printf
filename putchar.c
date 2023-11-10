#include "main.h"

/**
 * _putchar - A custom putchar function to print characters
 * @c: Character to be printed
 * Return: Character to be prnted
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
