#include "shell.h"
/**
* _strcmp - compares
* @s1: pointer
* @s2: pointer
* Return: data
*/
int _strcmp(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
else
{
i++;
}
}
if (s1[i] == '\0' && s2[i] == '\0')
{
return (0);
}
else if (s1[i] == '\0')
{
return (-s2[i]);
}
else
{
return (s1[i]);
}
}
