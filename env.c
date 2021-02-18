#include "shell.h"

// se encarga de parsear los argumentos si hay variable existente
void parse_env(cmdbuf_t **cmd)
{
  size_t i;
  cmdbuf_t *tmp = *cmd;
  char *tmp_str = NULL;

  if (!cmd)
    return;
  
  for (i = 0; i < tmp->size; i++)
  {
    if (*tmp->argv[i] == '$')
    {
      tmp_str = (tmp->argv[i] + 1);
      tmp_str = get_env(tmp_str, tmp->env);
      if (tmp_str)
      {
        free(tmp->argv[i]);
        tmp->argv[i] = _strdup(tmp_str);
        free(tmp_str);
      }
    }
  }
}

void print_env(cmdbuf_t *cmd, char **env)
{
  int i;

  for (i = 0; env[i] != NULL; i++)
  {
    printf("%s\n", env[i]);
  }
  destroy(cmd->argv, cmd->size);
  free(cmd);
}

char *get_env(char *varname, char **env)
{
  int i, x, z, y = 0;
  char tmp[1024];

  for (i = 0; env[i] != NULL; i++)
  {
    for (x = 0; x < _strlen(env[i]); x++)
    {
      if (env[i][x] == '=')
        break;
      tmp[x] = env[i][x];
    }
    tmp[x] = '\0';
    if (!strcmp(varname, tmp))
    {
      for (z = x + 1; env[i][z] != '\0'; z++)
        tmp[y++] = env[i][z];
      tmp[y] = '\0';
      return (_strdup(tmp));
    }
  }
  return (NULL);
}
