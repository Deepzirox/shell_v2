#include "shell.h"

/**
		Crea un entorno virtual en memoria estatica pero dinamica (heap)
		Acá se podran obtener las variables desde Linux y, pero tambien creara
		su propio espacio totalmente ajeno a __environ GNU y se podran agregar
		variables totalmente nuevas que no afecten sistemas externos.
		ya que todo sucede en la memoria estatica del programa.

		@flag -> opcion que se ejecutara para manejar enviroment virtual
		@n -> numero de variables leidas
**/
char **VIRTUAL_ENV(size_t *n, const char *flag, cmdbuf_t *cmd) 
{
	static char **virtual_env = NULL;
	static size_t num = 0;

	if (!__environ)
		return NULL;

	/** Search for flag options **/
	switch (_env_option((char *)flag)) 
	{
		case 1:
			if (!virtual_env)
				virtual_env = _init_env(&num);
			return (virtual_env);
			break;
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

char **_init_env(size_t *n) 
{
	char ** virtual_env = NULL;

	if (n) 
	{
	  virtual_env = clone_environ(n);
	  return (virtual_env);
	} 

	return (virtual_env);
}


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
