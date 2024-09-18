#include "monty.h"

/**
 * is_integer - Checks if a string is a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_integer(char *str)
{
	int i = 0;

	if (!str || *str == '\0')
	       	return (0);

	if (str[0] == '-' || str[0] == '+')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
