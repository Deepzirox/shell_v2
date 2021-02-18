#include "shell.h"
#include <stdio.h>
#include <string.h>
// funciones que se encargan de manejar los comandos especiales como cd o exit

// se encarga de deducir si el string es un comando especial
// Return 1: es el comando especial exit
// Return 2: es el comando especial cd
int check_handlers(char *str)
{
  int handler_id = 0;

  if (!str)
    return (handler_id);

  if (!strcmp(str, "exit"))
    handler_id = 1;
  else if (!strcmp(str, "cd"))
    handler_id = 2;
  else if (!strcmp(str, "env"))
    handler_id = 3;

  return handler_id;
}

// se encarga de manejar el comando de salida con argumento (o sin)
// rompe cualquier ciclo de input cambiando la variable exit_var_addr
// libera todo la memoria del buffer cmdbuf_t
void exit_handler(cmdbuf_t *cmd, int *exit_var_addr)
{

  if (!cmd->argv)
    return;
  
  printf("exit\n");
  if (cmd->argv[1] != NULL)
  {
    *exit_var_addr = char_toint(cmd->argv[1]);
    destroy(cmd->argv, cmd->size);
    free(cmd);
    return;
  }
  *exit_var_addr = 0;
  destroy(cmd->argv, cmd->size);
  free(cmd);
}

void change_dir(cmdbuf_t *cmd)
{
  int err_handler;
  char *home_ptr = NULL;

  if (!cmd->argv)
    return;
  
  if (cmd->argv[1] != NULL)
  {
    err_handler = chdir(cmd->argv[1]);
    if (err_handler < 0)
      perror("cd");
  }
  else
  {
    home_ptr = get_env("HOME", cmd->env);
    if (chdir(home_ptr) < 0)
      printf("HOME VARIABLE DOES NOT EXIST\n");
  }
  free(home_ptr);
  destroy(cmd->argv, cmd->size);
  free(cmd);
}
