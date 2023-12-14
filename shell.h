#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
char *getppt(char *storemycmd);
char **splitCmd(char *storemycmd);
int _strncmp(const char *s1, const char *s2, size_t n);
void arrsfree(char **cmdtosend);
char *_strncpy(char *dest, char *src, int n);
char *getenvos(char *data);
void execs(char **cmdtosend);
char *_strdup(const char *so);
void exitsh(char *storemycmd);
void printvile(int *sta);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
#endif
