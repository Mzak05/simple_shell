#include "shell.h"
/**
* *_strncpy - give copy
* @dest: pointer
* @src: pointer
* @n: number
* Return: result
*/
char *_strncpy(char *dest, char *src, int n)
{
int i;
i = 0;
while (i < n && src[i] != '\0')
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
