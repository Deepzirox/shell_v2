#include "shell.h"
#include <stdio.h>

int console_mode(char **env);

int main(int argc, char **argv, char **env)
{
  int test_console = 1;
  int exit_code = 0;

  if (test_console)
  {
    switch (argc)
    {
      case 1:
        exit_code = console_mode(env);
        break;
    }
    return (exit_code);
  }
  get_env("HOLA\0", env);
  return (exit_code);
}

int console_mode(char **env)
{
  int exit_call = -1;

  while (exit_call == -1)
  {
    input_t *input = get_input();
    cmdbuf_t *cmd = parse_input(input);

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
    forking(cmd);
    destroy(cmd->argv, cmd->size);
    free(cmd);
  }
  return (exit_call);
}
