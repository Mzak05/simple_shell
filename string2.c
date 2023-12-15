#include "shell.h"
/**
 * *_strcpy - pppp
 * @dest: spf
 * @src: fr
 * Return: rfr
 */
char *_strcpy(char *dest, char *src)
{
int i;
int j = _strlen(src);
for (i = 0; i <= j; i++)
dest[i] = src[i];
return (dest);
}
/**
 * _strlen - rr
 * @data: vfvf
 * Return: cdcf
 */
int _strlen(char *data)
{
int i = 0;
while (data[i] != '\0')
i++;
return (i);
}
