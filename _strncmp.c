#include "shell.h"
/**
 * _strncmp - ii
 * @s1: ii
 * @s2: ii
 * @n: ii
 * Return: ii
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
while (n && *s1 && (*s1 == *s2))
{
s1++;
s2++;
n--;
}
if (n == 0)
{
return (0);
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
