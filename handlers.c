#include "shell.h"
#include <stdio.h>
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

	if (eq(str, "exit"))
		handler_id = 0x01;
	else if (eq(str, "cd"))
		handler_id = 0x02;
	else if (eq(str, "env"))
		handler_id = 0x03;
	else if (eq(str, "setenv"))
		handler_id = 0x04;

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
		*exit_var_addr = 0;
		drop(cmd);
		return;
	}
	*exit_var_addr = 0;
	drop(cmd);
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
			perror(cmd->err_name);
	}
	else
	{
		home_ptr = get_env("HOME", cmd->env);
		if (chdir(home_ptr) < 0)
			perror(cmd->err_name);
	}
	free(home_ptr);
	drop(cmd);
}
