#include "shell.h"
#include <stdio.h>
/* Functions to child processes */

/**
 * drop - delete all contained in cmd
 * @cmd: command buffer
 */
void drop(cmdbuf_t *cmd)
{
	destroy(cmd->argv, cmd->size);
	/* destroy(cmd->env, cmd->size_env); */
	free(cmd->pre_alias);
	free(cmd->raw_text);
	free(cmd);
}

/**
 * forking - entry point
 * Desc: function that manages child processes
 * @cmd: pointer to buffer
 * Return: 0 status is child process is correct
 */
int forking(cmdbuf_t *cmd)
{
	pid_t child;
	int wgstatus;
	int quit = 0;

	child = fork();
	if (child == -1)
		return (1);

	if (child == 0)
	{
		if (cmd->argv[0])
		{
			quit = execve(cmd->argv[0], cmd->argv, NULL);
			if (quit == -1)
			{
				quit = 127;
				fprintf(stderr, "%s: %d: %s: not found\n",
					cmd->err_name, 1, cmd->pre_alias);
				drop(cmd);
				exit(quit);
			}
		}
		drop(cmd);
		exit(quit);
	}
	else
	{
		wait(&wgstatus);
		drop(cmd);
		quit = WEXITSTATUS(wgstatus);
		return (quit);
	}
	return (0);
}
