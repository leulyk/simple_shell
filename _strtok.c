#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

/**
 * _strtok - a custom strtok function
 *
 * @str: the string to tokenize
 * @delim: set of delimiters
 *
 * Return: pointer to the next token
 */
char *_strtok(char *str, char *delim)
{
	static char *input;
	char *token;
	int i;

	if (str != NULL)
		input = str;

	if (input == NULL)
		return (NULL);

	token = malloc(_strlen(input) + 1);
	if (token == NULL)
		return (NULL);

	i = 0;
	while (input[i])
	{
		if (isdelim(input[i], delim))
		{
			token[i] = '\0';
			input = input + i + 1;
			return (token);
		}
		else
		{
			token[i] = input[i];
		}
		++i;
	}
	token[i] = '\0';
	input = NULL;

	return (token);
}

/**
 * isdelim - check if a character is from a set of delimiters
 *
 * @ch: character to check
 * @delim: an array of delimiters
 *
 * Return: 1 if found, otherwise 0
 */
int isdelim(char ch, char *delim)
{
	int i;

	i = 0;
	while (delim[i])
	{
		if (delim[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
