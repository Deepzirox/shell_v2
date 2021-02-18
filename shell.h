#ifndef _SHELL_
#define _SHELL_
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <limits.h>
#include <errno.h>

#define READ_SIZE 1024
#define UNUSED(x) (void)(x)

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


typedef struct CommandBuffer {
    char **env;
    char **argv;
    size_t size;
} cmdbuf_t;

typedef struct InputBuffer {
  char *buffer;
  size_t size;
} input_t;

//input handlers
input_t *get_input();
cmdbuf_t *parse_input(input_t *input);
// size handlers
size_t n_argv_allocate(input_t *input);
// string handlers
int counttok(char *buff);
int check_handlers(char *str);
int char_toint(char *arg);
char **get_arguments(int count_tok, char *buff);
void destroy(char **ar, int count);
void exit_handler(cmdbuf_t *cmd, int *exit_var_addr);
void print_env(cmdbuf_t *cmd, char **env);
void change_dir(cmdbuf_t *cmd);
void parse_env(cmdbuf_t **cmd);
void prompt();
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *parse_alias(char *exe);
char *get_env(char *varname, char **env);
int forking(cmdbuf_t *cmd);

#endif
