#include "monty.h"

/* Other important Basic C functions for Opcode */

/**
 * _strcmp - A function that compares two strings
 * @s1: string 1 to be compared
 * @s2: string 2 to be compared
 *
 * Return: 0 if s1 and s2 are equals
 *	-other values if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s1[i] == s2[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}

/**
 * _search - A function that determines if a character is a string
 * @str:  The string in review
 * @cha: The character to find
 *
 * Return: 1 for success and 0 for failure
 */
int _search(char *str, char cha)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == cha)
			break;
		i++;
	}
	if (str[i] == cha)
		return (1);
	else
		return (0);
}

/**
 * _strngcut - A function that breaks a string into token
 * depending on the number of delimiters
 * @str: string to cut in parts
 * @de: Delimiter
 *
 * Return: first partition
 */
char *_strngcut(char *str, char *de)
{
	static char *ult;
	int x = 0, y = 0;

	if (!str)
		str = ult;
	while (str[x] != '\0')
	{
		if (_search(de, str[x]) == 0 && str[x + 1] == '\0')
		{
			ult = str + x + 1;
			*ult = '\0';
			str = str + y;
			return (str);
		}
		else if (_search(de, str[x]) == 0 && _search(de, str[x + 1]) == 0)
			x++;
		else if (_search(de, str[x]) == 0 && _search(de, str[x + 1]) == 1)
		{
			ult = str + x + 1;
				*ult = '\0';
				ult++;
				str = str + y;
				return (str);
		}
		else if (_search(de, str[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}

/**
 * check_number - A function that check if a string is a number
 * @str: The string to check
 *
 * Return: 1 if string is a number and 0 for otherwise
 */
int check_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if(*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
