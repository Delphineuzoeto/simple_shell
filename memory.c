#include "shell.h"

/**
* free_pointer - free a pointer to NULLs the address
* @ptr: address of the pointer to be freed
*
* contributor - MUHAMMAD ABDULRAHMAN (mabdul.am25@gmail.com)
* DELPHINE UZOETO (delphineamaka@gmail.com)
*
* Return: if freed, return 1, otherwise, return 0.
*/
int free_pointer(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
