#include "shell.h"

/**
 * sig - handle signal
 * @n: signum
 */
void _signal(int n)
{
	exit(n);
}

input_t *get_input()
{
    //Buffer que va a contener lo que voy a leer del stdin
    char stack[READ_SIZE];
    input_t *input = NULL;
    int n;

    signal(SIGINT, _signal);
    n = read(STDIN_FILENO, stack, READ_SIZE);
    if (n < 1)
      exit(0);
    stack[n - 1] = '\0';
    input = malloc(sizeof(input_t));
    input->buffer = _strdup(stack);
    input->size = (size_t)n;

    return input;
}

/*
Funcion que se encarga de convertir un string: "ls -al /holberton"
en ["ls", "-al", "/holberton"]
ya que la funcion execve (que se encarga de ejecutar programas nos va a recibir ese array)
execve(char *bin, char **arguments, NULL)
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

void prompt()
{
  time_t rawtime;
  struct tm *i;
  char buff[2000], curr_p[1000];

  getcwd(curr_p, sizeof(curr_p));
  time( &rawtime );
  i = localtime(&rawtime);
  sprintf(buff, "%s(%d:%d:%d)~%s(%s)\n>>> %s ", 
    KRED, i->tm_hour, i->tm_min, i->tm_sec, KBLU, curr_p, KGRN);
  write(0, buff, _strlen(buff));
}
