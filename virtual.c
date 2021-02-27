#include "shell.h"

/**
 * VIRTUAL_ENV - entry to VIRTUAL ENV
 * Desc: VIRTUAL_ENV creates a virtual static memory but dynamic heap.
 * Variables can be obtained from Linux but also its own space to
 * __environ. New variables will be added that will no affect external
 * systems, everything happens inside the static memory of the program.
 * @n: int type number of read variables
 * @flag: const char type option that will execute to manage VE (virtual env)
 * @cmd: pointer to buf
 * Return: new virtual environment
 */
char **VIRTUAL_ENV(size_t *n, const char *flag, cmdbuf_t *cmd)
{
	static char **virtual_env;
	static size_t num;

	if (!__environ)
		return (NULL);

	/* Search for flag options */
	switch (_env_option((char *)flag))
	{
		case 1:
			if (!virtual_env)
				virtual_env = _init_env(&num);
			return (virtual_env);
		case 2:
			_free_env(virtual_env);
			return (NULL);
		case 3:
			virtual_env = push_env(virtual_env, cmd->argv[1], num);
			drop(cmd);
			break;
		case 4:
			break;
	}
	if (n)
		*n = num;
	return (virtual_env);
}

/**
 * _env_option - entry to env option
 * Desc: _env_option function that handles ids
 * @str: pointer to char to string id handler
 * Return: return handler id
 */
int _env_option(char *str)
{
	int handler_id = 0;

	if (!str)
		return (handler_id);

	if (eq(str, "init"))
		handler_id = 1;
	else if (eq(str, "free"))
		handler_id = 2;
	else if (eq(str, "set"))
		handler_id = 3;
	else if (eq(str, "get"))
		handler_id = 4;

	return (handler_id);
}

/**
 * _free_env - entry to free env
 * Desc: _free_env function that frees memory
 * @virtual_env: double pointer to char type to virtual env
 * Return: free virtual env memory
 */
void _free_env(char **virtual_env)
{
	size_t i;

	if (virtual_env)
	{
		for (i = 0; virtual_env[i] != NULL; i++)
			free(virtual_env[i]);
		free(virtual_env);
	}
}

/**
 * _init_env - entry to inti env
 * Desc: _init_env function that clones environment
 * @n: size_t pointer type to n
 * Return: return virtual environmenr
 */
char **_init_env(size_t *n)
{
	char **virtual_env = NULL;

	if (n)
	{
		virtual_env = clone_environ(n);
		return (virtual_env);
	}

	return (virtual_env);
}

/**
 * push_env - entry to push env
 * Desc: push_env function to print key and value
 * @virtual_env: double pointer to char to virtual env
 * @value: pointer char to value
 * @n: size_t type size of n
 * Return: returns virtual env
 */
char **push_env(char **virtual_env, char *value, size_t n)
{
	//char **new_vr_env = NULL;
	char *value_key = get_key(value);
	//char *value_val = get_value(value);
	char *tmp = NULL, *value_val;
	char tmp_buff[3000];

	if (!value || !value_key)
	{
		fprintf(stderr, "setenv: no valid value to set\n");
		return (virtual_env);
	}
	value_val = get_value(value);
	for (size_t i = 0; i < n; i++)
	{
		if (!virtual_env[i])
			break;
		tmp = get_key(virtual_env[i]);
		if (!tmp)
			break;
		if (eq(tmp, value_key))
		{
			free(virtual_env[i]);
			sprintf(tmp_buff, "%s=%s", value_key, value_val);
			virtual_env[i] = _strdup(tmp_buff);
			free(tmp);
			break;
		}
	}
	free(value_key);
	free(value_val);
	return (virtual_env);
}
