#include "shell.h"

int run_shell(char *errname, char **env);

/**
 * main - entry to main
 * Desc: main function that receives arguments
 * @argc: int type, number of arguments
 * @argv: double pointer char to argument string
 * @env: double pointer to environment list
 * Return: returns exit status code
 */
int main(int argc, char **argv, char **env)
{
	int exit_code = 0;

	UNUSED(argc);
	exit_code = run_shell(argv[0], env);
	return (exit_code);
}

/**
 * run_shell - entry point
 * Desc: run_shell function that executes hsh
 * @env: double pointer to environment variables
 * Return: returns a prompt to hsh shell v2
 */
int run_shell(char *errname, char **env)
{
	int exit_call = -1;
	int proc_result = 0;

	while (exit_call == -1)
	{
		prompt();
		fflush(STDIN_FILENO);
		input_t *input = get_input(proc_result);
		cmdbuf_t *cmd = parse_input(input);
		cmd->err_name = errname;
		cmd->pre_alias = _strdup(cmd->argv[0]);
		cmd->env = env;
		parse_env(&cmd);
		free(input->buffer);
		free(input);
		if (cmd->argv[0])
		{
			switch (check_handlers(cmd->argv[0]))
			{
			case 1:
				exit_handler(cmd, &exit_call);
				continue;
			case 2:
				change_dir(cmd);
				continue;
			case 3:
				print_env(cmd, env);
				continue;
			}
			cmd->argv[0] = parse_alias(cmd->argv[0]);
		}
		proc_result = forking(cmd);
	}
	return (proc_result);
}
