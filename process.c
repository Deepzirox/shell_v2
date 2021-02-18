#include "shell.h"
#include <stdio.h>
#include <unistd.h>
// funciones para manejar los child

int forking(cmdbuf_t *cmd)
{
  pid_t child;
  int wgstatus;
  int execve_code = 0;

  child = fork();
  if (child == -1)
  {
    perror("fork child error");
    return (1);
  }
  if (child == 0)
  {
    if (cmd->argv[0])
    {
      if ((execve_code = execve(cmd->argv[0], cmd->argv, NULL)) == -1)
      {
        destroy(cmd->argv, cmd->size);
        free(cmd);
        exit(execve_code);
      }
    }
    destroy(cmd->argv, cmd->size);
    free(cmd);
    exit(execve_code);
  }
  else
  {
    wait(&wgstatus);
    return (wgstatus);
  }
  return (0);
}
