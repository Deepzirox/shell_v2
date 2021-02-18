#include "shell.h"
/* Functions who manage special commands, cd or exit */

/**
 * check_handlers - entry point
 * Desc: check_handlers function that reduces the string if its a
 * special command
 * @str: pointer char type
 * Return: returns 1 if special command is exit and returns 2 when
 * cd identified.
 */
int check_handlers(char *str)
{
	int handler_id = 0;

	if (!str)
		return (handler_id);

	if (!strcmp(str, "exit"))
		handler_id = 1;
	else if (!strcmp(str, "cd"))
		handler_id = 2;
	else if (!strcmp(str, "env"))
		handler_id = 3;

	return (handler_id);
}

/**
 * exit_handler - entry point
 * Desc: exit_handler function that frees memory when input exit command
 * is placed.
 * @cmd: pointer to struct
 * @exit_var_addr: int type to exit
 * Return: returns frees all memory and 0 exit status
 */
void exit_handler(cmdbuf_t *cmd, int *exit_var_addr)
{

	if (!cmd->argv)
		return;

	printf("exit\n");
	if (cmd->argv[1] != NULL)
	{
		*exit_var_addr = char_toint(cmd->argv[1]);
		destroy(cmd->argv, cmd->size);
		free(cmd);
		return;
	}
	*exit_var_addr = 0;
	destroy(cmd->argv, cmd->size);
	free(cmd);
}

/**
 * change_dir - cd special command
 * Desc: change_dir function identifiying cd as special command
 * @cmd: pointer to buffer stored command
 * Return: returns error if directory not found
 */
void change_dir(cmdbuf_t *cmd)
{
	int err_handler;
	char *home_ptr = NULL;

	if (!cmd->argv)
		return;

	if (cmd->argv[1] != NULL)
	{
		err_handler = chdir(cmd->argv[1]);
		if (err_handler < 0)
			perror("cd");
	}
	else
	{
		home_ptr = get_env("HOME", cmd->env);
		if (chdir(home_ptr) < 0)
			printf("HOME VARIABLE DOES NOT EXIST\n");
	}
	free(home_ptr);
	destroy(cmd->argv, cmd->size);
	free(cmd);
}
