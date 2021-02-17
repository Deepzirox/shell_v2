#include "shell.h"
/** FUNCIONES CUSTOM QUE AYUDARAN EN EL MANEJO DE LOS ARGUMENTOS **/

/**
 * counttok - get number of tokens in string
 * @buff: buffer to process
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
 * generate_tokens - generate array of strings
 * @count_tok: counter of tokens
 * @tokened: buffer for get tokens
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
// liberar array de strings
void destroy(char **ar, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(ar[i]);
	}
	free(ar);
}
