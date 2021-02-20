#include "shell.h"
#include <stdio.h>

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
	UNUSED(env);
	exit_code = run_shell(argv[0]);
	return (exit_code);
}
