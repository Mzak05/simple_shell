#include "shell.h"
/**
* *_strncat - give concact
* @dest: pointer
* @src: pointer
* @n: number
* Return: result
*/
char *_strncat(char *dest, char *src, int n)
{
int a;
int r;
r = 0;
a = 0;
while (src[a] != '\0')
{
a++;
}
while (dest[r] != '\0')
{
r++;
}
if (a > r)
{
r = 0;
while (r < n && dest[r] != '\0')
{
src[a] = dest[r];
r++;
a++;
}
src[a] = '\0';
return (src);
}
else
{
a = 0;
while (a < n && src[a] != '\0')
{
dest[r] = src[a];
a++;
r++;
}
dest[r] = '\0';
return (dest);
}
}
