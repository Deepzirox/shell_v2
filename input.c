#include "shell.h"

/**
 * _signal - handle signal
 * Desc: _signal handler function
 * @n: signum
 * Return: void function exit(n) int
 */
void _signal(int n)
{
	VIRTUAL_ENV(NULL, "free", NULL);
	exit(n);
}

/**
 * get_input - get input
 * Desc: get_input function that reads stdin
 * @proc_result: code result of the last command executed
 * Return: returns buffer stdin input
 */
input_t *get_input(int proc_result)
{
	/* Buffer that contains stdin input */
	char stack[READ_SIZE];
	input_t *input = NULL;
	int n;

	signal(SIGINT, _signal);
	signal(SIGPIPE, _signal);
	n = read(STDIN_FILENO, stack, READ_SIZE);
	if (n < 1)
	{
		VIRTUAL_ENV(NULL, "free", NULL);
		exit(proc_result);
	}
	stack[n - 1] = '\0';
	input = malloc(sizeof(input_t));
	input->buffer = _strdup(stack);
	input->size = (size_t)n;

	return (input);
}

/**
 * parse_input - convert string
 * Desc: parse_input function that converts a string
 * @input: pointer to input buffer
 * Return: buffer to converted string,
 * "ls -al /holberton" -> ["ls", "-al", "/holberton"]
 */
cmdbuf_t *parse_input(input_t *input)
{
	cmdbuf_t *cmd = NULL;

	if (!input)
		return (NULL);

	cmd = malloc(sizeof(cmdbuf_t));
	cmd->size = counttok(input->buffer);
	cmd->argv = get_arguments(cmd->size, input->buffer);
	cmd->env = NULL;

	return (cmd);
}

/**
 * prompt - entry point
 * Desc: prompt function that prompts time when hsh is executed
 * Return: writes time in prompt (HH:MM:SS)
 */
void prompt(void)
{
	time_t rawtime;
	struct tm *i;
	char buff[2000], curr_p[1000];

	getcwd(curr_p, sizeof(curr_p));
	time(&rawtime);
	i = localtime(&rawtime);
	sprintf(buff, "%s(%d:%d:%d)~%s(%s)\n>>> %s ",
		KRED, i->tm_hour, i->tm_min, i->tm_sec, KBLU, curr_p, KGRN);
	write(0, buff, _strlen(buff));
	fflush(STDIN_FILENO);
}
