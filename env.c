#include "shell.h"

/**
 * parse_env - entry point
 * Desc: parse_env function that parses arguments if their present
 * @cmd: double pointer to struct CommandBuffer
 * Return: void function that parses
 */
void parse_env(cmdbuf_t **cmd)
{
	size_t i;
	cmdbuf_t *tmp = *cmd;
	char *tmp_str = NULL;

	if (!cmd)
		return;

	for (i = 0; i < tmp->size; i++)
	{
		if (*tmp->argv[i] == '$')
		{
			tmp_str = (tmp->argv[i] + 1);
			tmp_str = get_env(tmp_str, tmp->env);
			if (tmp_str)
			{
				free(tmp->argv[i]);
				tmp->argv[i] = _strdup(tmp_str);
				free(tmp_str);
			}
		}
	}
}

/**
 * print_env - prints
 * Desc: print_env function that prints parsed string
 * @cmd: pointer to struct buffer
 * @env: double pointer to char string
 * Return: prints if parsed string available, frees memory in buff
 */
void print_env(cmdbuf_t *cmd, char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
	destroy(cmd->argv, cmd->size);
	free(cmd);
}

/**
 * get_env - entry point
 * Desc: get_env function that compares strings
 * @varname: pointer char type to variable name
 * @env: double pointer to stored char
 * Return: returns pointer to new duplicate string or NULL
 */
char *get_env(char *varname, char **env)
{
	int i, x, z, y = 0;
	char tmp[1024];

	for (i = 0; env[i] != NULL; i++)
	{
		for (x = 0; x < _strlen(env[i]); x++)
		{
			if (env[i][x] == '=')
				break;
			tmp[x] = env[i][x];
		}
		tmp[x] = '\0';
		if (!strcmp(varname, tmp))
		{
			for (z = x + 1; env[i][z] != '\0'; z++)
				tmp[y++] = env[i][z];
			tmp[y] = '\0';
			return (_strdup(tmp));
		}
	}
	return (NULL);
}
