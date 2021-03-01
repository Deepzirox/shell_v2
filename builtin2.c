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
