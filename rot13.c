#include "main.h"

/**
 * rot13 - Apply rot13 encryption to a string
 * @str: The string to be rot13'ed
 * Return: returns the count of printed characters
 */
int rot13(const char *str)
{
	int count = 0;
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		char c = str[i];

		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			char base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';

			_putchar((c - base + 13) % 26 + base);
			count++;
		}
		else
		{
			_putchar(c);
			count++;
		}
	}

	return (count);
}
