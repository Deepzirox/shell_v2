#include "shell.h"
/* Functions to manage strings */

/**
 * _strcat - entry to _strcat
 * Desc: _strcat function thar appends strings
 * @dest: pointer char type
 * @src: pointer char type
 * Return: returns concatenated string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, e = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[e] != '\0')
	{
		dest[i] = src[e];
		e++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Entry point
 * Desc: _strdup function that duplicates a string
 * @str: char type
 * Return: Pointer to a new string
 **/
char *_strdup(char *str)
{
	int i = 0;
	char *j;
	int x;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	i++;
	j = malloc(sizeof(char) * i);
	if (j == NULL)
		return (NULL);
	for (x = 0; x < i; x++)
	{
		j[x] = str[x];
	}
	return (j);
}

/**
 * _strlen - entry to _strlen
 * Desc: _strlen calculates a length of a string
 * @s: pointer char type
 * Return: returns int, length of string
*/
int _strlen(char *s)
{
	int x = 0;

	while (*s != '\0')
	{
		s++;
		x++;
	}
	return (x);
}

// compara 2 strings si son iguales 0 falso 1 verdadero
int eq(char *str1, char* str2)
{
	int i;

	if (_strlen(str1) != _strlen(str2))
		return (0);
	
	for (i = 0; i < _strlen(str1); i++)
		if (str1[i] != str2[i])
			return (0);

	return (1);
}
