#include "shell.h"
#include <stdio.h>
#include <unistd.h>

input_t *get_input()
{
    //Buffer que va a contener lo que voy a leer del stdin
    char stack[READ_SIZE];
    char curr_p[1000];
    time_t rawtime;
    struct tm *i;
    input_t *input = NULL;
    int n;

    getcwd(curr_p, sizeof(curr_p));
    time( &rawtime );
    i = localtime( &rawtime );
    printf("(%d:%d:%d)~(%s)-> ", i->tm_hour, i->tm_min, i->tm_sec, curr_p);
    input = malloc(sizeof(input_t));
    fflush(0);
    n = read(STDIN, stack, READ_SIZE);
    stack[n - 1] = '\0';
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
