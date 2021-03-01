#include "shell.h"

/**
 * parse_alias - entry point
 * Desc: parse_alias function that parses a string and adds /bin/ at the
 * beggining of the command.
 * @exe: char pointer to string
 * Return: returns a string with "/bin/" at the beginning, e.g. /bin/ls
 * and/or frees memory of the block
 */
char *parse_alias(char *exe)
{
	char tmp[] = {"/bin/\0"};
	char *new_str = NULL;
	size_t s;

	if (*exe != '/')
	{
		s = (_strlen(tmp) + _strlen(exe));
		new_str = malloc(sizeof(char) * s + 1);
		new_str[0] = '\0';
		_strcat(new_str, tmp);
		_strcat(new_str, exe);
		free(exe);
		return (new_str);
	}
	return (exe);
}

void history(char *new_history, const char *flag)
{
	static char **h = NULL;
	static int h_added = 0;
	int i;

	if (eq((char *)flag, "init"))
	{
		h = malloc(sizeof(char *) * 4069);
	}
	else if (eq((char *)flag, "free") || !(h_added < 4069))
	{
		destroy(h, h_added);
		h_added = 0;
	}
	else if (eq((char *)flag, "print"))
		for (i = 0; i < h_added; i++)
			printf("%d: %s\n", i, h[i]);
	else if (eq((char *)flag, "push"))
		if (new_history)
		{
			h[h_added++] = _strdup(new_history);
			h[h_added] = NULL;
		}
}

void help()
{
	printf("\n\
	HSH help menu\n\
	======================\n\
	The shell is an interactive interface that allows users to execute commands and utilities in\n\
	Linux and other UNIX based operatin systems\n\
	\n\
	built in functions:\n\
		cd <path> - navegate to the given path\n\
		history - show history of all commands typed\n\
		env - list environmets variables\n\
		setenv - set or add an environment variable\n\
	\
	manage programs:\n\
		put your program in /bin folder and you can use it in the shell\n\
		\
	\n\
	");
}
