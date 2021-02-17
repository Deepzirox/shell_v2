#include "shell.h"
// funciones para el manejo de strings

/*
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

/*
 * _strlen - entry to _strlen
 * Desc: _strlen calculates a length of a string
 * @s: pointer char type
 * Return: returns int, length of string 
*/
int _strlen(char *s)
{
  int x = 0;

  while(*s != '\0')
  {
    s++;
    x++;
  }
  return (x);
}

// convertir char * numerico a integer
int char_toint(char *arg)
{
  int i, val = -1;

  for (i = 0; i < _strlen(arg); i++)
  {
    if (val == -1)
    {
      val = ((int)arg[i] - 48);
      continue;
    }
    val *= 10;
    val += ((int)arg[i] - 48);
  }

  return (val);
}


// convertir numero entero a string
/**
char *num_tochar(int num)
{
  char buff[11];
  int idx = 0;
  while(num)
  {
      int dig = num % 10;
      char ch = (dig + '0');
      buff[idx++] = ch;
      num /= 10;
  }
  buff[idx] = '\0';

  return _strdup(buff);
}

// reversa string eliminando el bloque de memoria del anterior
char *rev(char *str)
{
  char *new_str = NULL;
  int size, it = 0;

  if (!str)
    return (NULL);

  size = _strlen(str);
  new_str = malloc(sizeof(char) * (size + 1));
  while (size > 0)
  {
    new_str[it++] = str[--size];
  }

  new_str[it] = '\0';
  free(str);
  return (new_str);
}
**/
