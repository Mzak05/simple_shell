#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;
/**
 * struct built_s - maghatfhmch
 * @name: nnsir
 * @p: ppc
 *
 * Description: glt lik sir 9lb
**/
typedef struct built_s
{
        char *name;
        int (*p)(void);
} built_s;
/**
 * struct list_s - don't cheat from me
 * @value: sir glbha
 * @next: wa sir glbha
 *
 * Description: sir 9lb 3liha
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

void getout(char **tikchbila, char *mahmoud, char *karim,int ahmed, char *samir);
void getoutmini(char **cmdtosend, unsigned int size);
void pro(struct stat trf, int lsp);
void noway(int discord);
void _puts(char *red);
int _strlen(char *data);
int _strcmp(char *fam, char *variable, unsigned int lsp);
int _strncmp(char *fam, char *variable, unsigned int lsp);
char *_getline(FILE *tpr);
char **splitcmd(char *chaimae);
char *_which(char *storemycmd, char *powerful, char *souka);
int forkpid(char *powerful, char **tikchbila);
int snb(built_s goku[]);
char *_getenvos(const char *fam);
char **cpenv(char **cpy, unsigned int leoenv);
list_s *pathlist(list_s *down, char *up);
char *_strcpy(char *dest, char *src);
int printenv(void);
int exitsh(void);
int blexe(char **tikchbila);
#endif
