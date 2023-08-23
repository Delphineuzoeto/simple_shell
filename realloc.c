#include "shell.h"


/**
* _memset - fill memory with a constant byte
* @pnter: pnter is the pointer to the memory area
* @ptr_b: the byte to fill the pointer (*s) with
* @n: amount of bytes filled
* Return: the pointer to the memory area (s)
*/
char *_memset(char *pnter, char ptr_b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
pnter[i] = ptr_b;
return (pnter);
}

/**
* ffree - free strings
* @strstr: string of strings
*/
void ffree(char **strstr)
{
char **a = strstr;

if (!strstr)
return;
while (*strstr)
free(*strstr++);
free(a);
}

/**
* _realloc -  function to reallocate block of memory
* @ptr: pointer to prev malloc block
* @old_size: byte size of prev malloc block
* @new_size: byte size of new malloc block
*
* Return: pointer to block name.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);

if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
