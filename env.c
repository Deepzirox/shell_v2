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
	drop(cmd);
}

/**
 * get_env - entry point
 * Desc: get_env funcion that gets value of env
 * @varname: pointer char type to variable name
 * @env: double pointer to the enviroment
 * Return: returns pointer to the value of the variable
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

/**
 * clone_environ - entry to clone environ
 * Desc: clone_environ function that counts number of variables
 * @var_num: size_t type pointer to variable
 * Return: returns the number of variables in new environment
 */
char **clone_environ(size_t *var_num)
{
	size_t var_number = 0, i;
	char **new_env = NULL;
	char **_env = NULL;

	F_LOCK;

	/*
	 * We need to get the pointer now that
	 * we have the lock and not earlier, since
	 * another thread might have created a
	 * new environment.
	 */
	_env = __environ;

	for (; _env[var_number] != NULL; var_number++)
		;

	new_env = malloc(sizeof(char *) * var_number);

	for (i = 0; i < var_number - 1; i++)
		new_env[i] = _strdup(_env[i]);

	new_env[var_number - 1] = NULL;
	*var_num = var_number - 1;

	/* Unlock region */
	F_ULOCK;
	return (new_env);
}
