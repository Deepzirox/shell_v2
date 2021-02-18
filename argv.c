#include "shell.h"
/* FUNCIONES CUSTOM QUE AYUDARAN EN EL MANEJO DE LOS ARGUMENTOS */

/**
 * counttok - count number of tokens
 * Desc: counttok function that gets number of tokens in string
 * @buff: char type buffer to process
 * Return: count of tokens
 */
int counttok(char *buff)
{
	int c;
	char *m = _strdup(buff);
	char *p = strtok(m, " ");

	for (c = 0; p != NULL; p = strtok(NULL, " "))
	{
		c++;
	}
	free(m);
	free(p);
	return (c);
}
/**
 * get_arguments - generate array
 * Desc: get_arguments function that generates an array of strings
 * @count_tok: int type counter of tokens
 * @buff: char type buffer to get tokens
 * Return: array of strings
 */
char **get_arguments(int count_tok, char *buff)
{
	char **tokens;
	char *aux = _strdup(buff);
	char *h;
	int i;

	tokens = malloc((count_tok + 1) * sizeof(char *));
	h = strtok(aux, " ");
	for (i = 0; h != NULL; h = strtok(NULL, " "))
	{
		tokens[i] = _strdup(h);
		i++;
	}
	tokens[i] = NULL;
	free(h);
	free(aux);
	return (tokens);
}

/**
 * destroy - entry point
 * Desc: destroy function to free array strings
 * @ar: char double pointer type to string
 * @count: int type counter
 * Return: free memory of string array
 */
void destroy(char **ar, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(ar[i]);
	}
	free(ar);
}
