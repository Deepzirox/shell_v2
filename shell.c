#include "shell.h"

/**
 * run_shell - entry point to shell
 * Desc: run_shell function that executes hsh
 * @env: double pointer to environment variables
 * @errname: program name for error msg
 * Return: returns a prompt to hsh shell v2
 */
int run_shell(char *errname)
{
	int exit_call = -1;
	int proc_result = 0;

	while (exit_call == -1)
	{
		cmdbuf_t *cmd = parse_command_buffer(proc_result, errname);
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
				print_env(cmd, cmd->env);
				continue;
			}
			cmd->argv[0] = parse_alias(cmd->argv[0]);
		}
		proc_result = forking(cmd);
	}
	return (proc_result);
}

cmdbuf_t *parse_command_buffer(int proc_result, char *errname)
{
    prompt();
	input_t *input = get_input(proc_result);
	cmdbuf_t *cmd = parse_input(input);
    size_t n_envs = 0;

	cmd->err_name = errname; /* inmutable */
	cmd->pre_alias = _strdup(cmd->argv[0]);
	cmd->env = VIRTUAL_ENV(&n_envs, "init");
    cmd->size_env = n_envs;
	free(input->buffer);
	free(input);
	parse_env(&cmd);
	return (cmd);
}
