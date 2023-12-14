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
char *_strncpy(char *dest, char *src, int n);
char *getenvos(char *data);
char *_strdup(const char *so);
void exitsh(char *storemycmd);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
#endif
