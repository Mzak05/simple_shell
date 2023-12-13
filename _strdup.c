#include "shell.h"
/**
 * _strdup - duplic
 * @so: info
 * Return: d
 */
char *_strdup(const char *so)
{
size_t le = 0;
char * du;
size_t i;
const char *te = so;
if (so == NULL)
{
return (NULL);
}
while (*te++)
{
le++;
}
du = (char *)malloc(le + 1);
if (du == NULL)
{
return (NULL);
}
for (i = 0; i <= le; i++)
{
du[i] = so[i];
}
return (du);
}
