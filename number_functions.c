#include "monty.h"

/**
 * isInteger - checks if a string is actually a an integer
 * @str: string to be checked
 * Return: 1 if string is a valid number, 0 if not
 */
int isInteger(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
