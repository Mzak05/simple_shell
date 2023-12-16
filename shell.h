#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - deded
 *@arg: ded
 *@argv: dedede
 *@path: ad
 *@argc: the
 *@line_count: the
 *@err_num: the
 *@linecount_flag: if on cou
 *@fname: the
 *@env: linke
 *@environ: custom
 *@history: t
 *@alias: th
 *@env_changed: o
 *@status: the ret
 *@cmd_buf: addres
 *@cmd_buf_type: CMD
 *@readfd: the f
 *@histcount: th
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_type;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contain
 *@type: th
 *@func: edde
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_type *);
} builtin_table;

int shells(info_type *, char **);
int fbc(info_type *);
void fcmd(info_type *);
void fkcmd(info_type *);
int is_command(info_type *, char *);
char *dupli_chars(char *, int, int);
char *find_path(info_type *, char *, char *);
int loophsh(char **);
void _eput_str(char *);
int _eputchar(char);
int _put_fd(char c, int fd);
int _puts_fd(char *str, int fd);
int _strlength(char *achstr);
int _str_comp(char *fs, char *ss);
char *starts_with(const char *ssearch, const char *ssfind);
char *_str_cat(char *desti, char *sbuf);
char *_str_copy(char *desti, char *sbuf);
char *_str_dup(const char *dupstr);
void _puts(char *prstr);
int _putchar(char cp);
char *_strn_copy(char *desti, char *sstr, int cc);
char *_strncat(char *desti, char *sstr, int bu);
char *_str_chr(char *sp, char sc);
char **str_split(char *achstr, char *dli);
char **str_split2(char *achstr, char dli);
char *_memory_set(char *ptr, char by, unsigned int nb);
void str_free(char **sos);
void *_realloc(void *ptr, unsigned int oldsz, unsigned int newsz);
int ptr_free(void **);
int interactive(info_type *);
int is_delim(char, char *);
int _is_alpha(int);
int _sti(char *);
int errorst(char *);
void printerr(info_type *, char *);
int printdec(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(info_type *infffo);
int helpmy(info_type *infffo);

int _myhistory(info_type *infffo);
int _myalias(info_type *infffo);

ssize_t get_input(info_type *);
int _getline(info_type *, char **, size_t *);
void sigintHandler(int);
void clear_info(info_type *);
void set_info(info_type *, char **);
void free_info(info_type *, int);
char *_get_env(info_type *infffo, const char *envname);
int _myenvir(info_type *infffo);
int _mysetenv(info_type *infffo);
int _my_unsetenv(info_type *infffo);
int p_env_list(info_type *infffo);
char **get_env(info_type *);
int _unsetenv(info_type *, char *);
int _setenviro(info_type *, char *, char *);

char *get_history_f(info_type *info);
int write_history(info_type *info);
int read_hist(info_type *info);
int build_history_l(info_type *info, char *buf, int linecount);
int renumber_history(info_type *info);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t prt_list_str(const list_t *);
int delete_node(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *pt);
char **list_to_str(list_t *first);
size_t print_list(const list_t *pt);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node(list_t *first, list_t *node);
int is_chain_del(info_type *, char *, size_t *);
void check_chain(info_type *, char *, size_t *, size_t, size_t);
int replace_alias(info_type *);
int replace_vars_str(info_type *);
int replacestr(char **, char *);

#endif
