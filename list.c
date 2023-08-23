#include "shell.h"

/**
* add_node - funcion to add node to starting point of list
* @head: address of a pointer to head of the node
* @str: field of node
* @num: node index used by history
*
* Return: size of list
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *add_head;

if (!head)
return (NULL);
add_head = malloc(sizeof(list_t));
if (!add_head)
return (NULL);
_memset((void *)add_head, 0, sizeof(list_t));
add_head->num = num;
if (str)
{
add_head->str = _strdup(str);
if (!add_head->str)
{
free(add_head);
return (NULL);
}
}
add_head->next = *head;
*head = add_head;
return (add_head);
}

/**
* add_node_end - add a node to the last node in the list
* @head: address of a pointer to tail of the node
* @str: field of node
* @num: node index used by history
*
* Return: size of list
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *add_node, *node;

if (!head)
return (NULL);
node = *head;
add_node = malloc(sizeof(list_t));
if (!add_node)
return (NULL);
_memset((void *)add_node, 0, sizeof(list_t));
add_node->num = num;
if (str)
{
add_node->str = _strdup(str);
if (!add_node->str)
{
free(add_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = add_node;
}
else
*head = add_node;
return (add_node);
}

/**
* print_list_str - printing only the node(str) element of a list_t linked list
* @h: points to the first node
*
* Return: size of list
*/
size_t print_list_str(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}

/**
* delete_node_at_index - deletes node at given index
* @head: address of pointer to first node
* @index: index of node to delete
*
* Return: 1 on success, 0 on failure
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (!head || !*head)
return (0);
if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}

/**
* free_list - free all existing nodes in a list
* @head_pointer: stores the address of pointer to head node
*
* Return: void
*/
void free_list(list_t **head_pointer)
{
list_t *node, *next_node, *head;

if (!head_pointer || !*head_pointer)
return;
head = *head_pointer;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_pointer = NULL;
}
