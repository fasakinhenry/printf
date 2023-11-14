#include "main.h"

/**
 * string_handler - Handle the formatting of strings
 * @str: The string to be printed
 * @count: Pointer to the count variable to update
 */
void string_handler(char *str, int *count)
{
	if (str == NULL)
	{
		char *nullStr = "(NULL)";

		while (*nullStr != '\0')
		{
			_putchar(*nullStr);
			nullStr++;
			(*count)++;
		}
	}
	else
	{
		while (*str != '\0')
		{
			if (*str >= 32 && *str < 127)
			{
				_putchar(*str);
				(*count)++;
			}
			else
			{
				(*count) += print_non_printable(*str);
			}
			str++;
		}
	}
}
