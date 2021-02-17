#include "shell.h"

//parsea el string entrante para agregarle la ruta /bin/ al principio
// si escribes "pwd" en el prompt de la consola
// esta funcion convertira "pwd" en "/bin/pwd"
// libera el bloque de memoria antiguo en caso que se necesite
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
