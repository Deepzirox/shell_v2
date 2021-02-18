#include "shell.h"


int run_shell(char **env);

int main(int argc, char **argv, char **env)
{
  int exit_code = 0;

  exit_code = run_shell(env);
  return (exit_code);
}

int run_shell(char **env)
{
  int exit_call = -1;

  while (exit_call == -1)
  {
    prompt();
    fflush(STDIN_FILENO);
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
  }
  return (exit_call);
}
