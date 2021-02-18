#include "shell.h"
#include <stdio.h>
#include <unistd.h>

input_t *get_input()
{
    //Buffer que va a contener lo que voy a leer del stdin
    char stack[READ_SIZE];
    input_t *input = NULL;
    char *inp = NULL;
    int n, x;

    n = read(STDIN_FILENO, stack, 1024);
    if (n < 1)
      exit(0);
    inp = malloc(1024);
    for (x = 0; x < n; x++)
    {
      inp[x] = stack[x];
    }
    if (x > 1)
      inp[x - 1] = '\0';
    else
      inp[x] = '\0';
    input = malloc(sizeof(input_t));
    input->buffer = _strdup(inp);
    input->size = (size_t)n;
    free(inp);
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
  char curr_p[1000];
  time_t rawtime;
  struct tm *i;
  char buff[2000];

  getcwd(curr_p, sizeof(curr_p));
  time( &rawtime );
  i = localtime( &rawtime );
  sprintf(buff, "(%d:%d:%d)~(%s)-> ", i->tm_hour, i->tm_min, i->tm_sec, curr_p);
  write(0, buff, _strlen(buff));
}
