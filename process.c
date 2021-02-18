#include "shell.h"
/* Functions to child processes */

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
	int execve_code = 0;

	child = fork();
	if (child == -1)
	{
		perror("fork child error");
		return (1);
	}
	if (child == 0)
	{
		if (cmd->argv[0])
		{
			execve_code = execve(cmd->argv[0], cmd->argv, NULL);
			if (execve_code == -1)
			{
				perror(cmd->argv[0]);
				destroy(cmd->argv, cmd->size);
				free(cmd);
				exit(execve_code);
			}
		}
		destroy(cmd->argv, cmd->size);
		free(cmd);
		exit(execve_code);
	}
	else
	{
		wait(&wgstatus);
		destroy(cmd->argv, cmd->size);
		free(cmd);
		return (wgstatus);
	}
	return (0);
}
