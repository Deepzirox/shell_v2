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


/**
 * struct CommandBuffer - struct for command buffer
 * @env: first member
 * @argv: second member
 * @err_name: third member
 * @pre_alias: fourth member
 * @size: fifth member
 * @size_env: sixth member
 * @raw_text: eighth member
 * Description: stores argument string size, pointers to string arguments
 * and pointers to environment arguments
 */
typedef struct CommandBuffer
{
	char **env;
	char **argv;
	char *err_name;
	char *pre_alias;
	char *raw_text;
	size_t size;
	size_t size_env;
} cmdbuf_t;

/**
 * struct InputBuffer - struct buffer for stdin input
 * @buffer: first member
 * @size: second member
 *
 * Description: buffer that stores stdin in a buffer with size
 * to be handled by functions
 */
typedef struct InputBuffer
{
	char *buffer;
	size_t size;
} input_t;

char **VIRTUAL_ENV(size_t *n, const char *flag, cmdbuf_t *cmd);
void _free_env(char **virtual_env);
char **_init_env(size_t *n);
int _env_option(char *str);
char **push_env(char **virtual_env, char *value, size_t *n);
char **add_value(char **virtual, char *value, size_t *n);
char *get_key(char *var);
char *get_value(char *var);

input_t *get_input(int proc_result);
cmdbuf_t *parse_input(input_t *input);
cmdbuf_t *parse_command_buffer(int proc_result, char *errname);
size_t n_argv_allocate(input_t *input);
int counttok(char *buff);
int check_handlers(char *str);
int char_toint(char *arg);
char **get_arguments(int count_tok, char *buff);
char *parse_raw(cmdbuf_t *cmd);
char **clone_environ(size_t *var_num);
void destroy(char **ar, int count);
void history(char *new_history, const char *flag);
void exit_handler(cmdbuf_t *cmd, int *exit_var_addr);
void print_env(cmdbuf_t *cmd, char **env);
void change_dir(cmdbuf_t *cmd);
void parse_env(cmdbuf_t **cmd);
void drop(cmdbuf_t *cmd);
void prompt(void);
void help();
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *parse_alias(char *exe);
char *get_env(char *varname, char **env);
int forking(cmdbuf_t *cmd);
int eq(char *str1, char *str2);
int run_shell(char *errname);
int is_valid_key(char *str);
#endif
