#include "monty.h"
/**
 * add_endnode - A function that add node at the end of a
 * doubly linked list.
 * @head: The first position of the linked list
 * @n: The data to store
 *
 * Return: A doubly linked list
 */
stack_t *add_endnode(stack_t **head, const int n)
{
	stack_t *newnode, *buff;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;

	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (*head);
	}

	buff = *head;
	while (buff->next)
		buff = buff->next;
	newnode->next = buff->next;
	newnode->prev = buff;
	buff->next = newnode;
	return (buff->next);
}

/**
 * add_leadnode - A function that add a node at the beginning of
 * a doubly linked list
 * @head: The head of the doubly linked list
 * @n: The data to be stored
 *
 * Return: A doubly linked list
 */
stack_t *add_leadnode(stack_t **head, const int n)
{
	stack_t *newnode;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;

	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (*head);
	}
	(*head)->prev = newnode;
	newnode->next = (*head);
	newnode->prev = NULL;
	*head = newnode;
	return (*head);
}


/**
 * sel_func - A function that select the right function to perform
 * required operation on given opcode.
 * @code: The opcode passed to the function
 *
 * Return: A pointer to the function that executes the opcode
 */
void (*sel_func(char *code)) (stack_t **head, unsigned int c)
{
	instruction_t instruct[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"queue", opcode_queue},
		{"stack", opcode_stack},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"mul", opcode_mul},
		{"div", opcode_div},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{"rotr", opcode_rotr},
		{NULL, NULL}
	};
	int a;

	for (a = 0; instruct[a].opcode; a++)
		if (_strcmp(instruct[a].opcode, code) == 0)
			break;
	return (instruct[a].f);
}
