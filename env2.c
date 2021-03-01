#include "shell.h"

/**
 * get_key - entry to get key
 * Desc: get_key function that obtains key of an env variable
 * @var: char pointer to variable
 * Return: return duplicate or NULL
 */
char *get_key(char *var)
{
	int i;
	char tmp[1000];

	if (!var || !is_valid_key(var))
		return (NULL);

	for (i = 0; var[i] != '\0'; i++)
	{
		if (var[i] == '=')
		{
			tmp[i] = '\0';
			return (_strdup(tmp));
		}
		tmp[i] = var[i];
	}
	tmp[i] = '\0';
	return (_strdup(tmp));
}

/**
 * get_value - entry to get value
 * Desc: get_value function gets the value of a env variable
 * @var: char pointer to variable
 * Return: return duplicate or NULL
 */
char *get_value(char *var)
{
	int i, z, y = 0;
	char tmp[1000];

	for (i = 0; var[i] != '\0'; i++)
		if (var[i] == '=')
			break;

	if (i)
	{
		for (z = i + 1; var[z] != '\0'; z++)
			tmp[y++] = var[z];
		tmp[y] = '\0';
		return (_strdup(tmp));
	}

	return (NULL);
}

/**
 * is_valid_key - check if the variable is valid
 * @str: string
 * Return: int
 */
int is_valid_key(char *str)
{
	int i, res = 0;

	if (!str)
		return (res);

	for (i = 0; i < _strlen(str); i++)
		if (str[i] == '=' && str[i + 1] != '\0')
			res = 1;

	return (res);
}
