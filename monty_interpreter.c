#include "monty.h"

/**
 * opcode_push - An opcode that pushes an element to the stack
 * @head: The head of the linked list
 * @c: counter of the line number
 *
 * Return: nothing
 */
void opcode_push(stack_t **head, unsigned int c)
{
	int p, q = 0;

	if (!global_var.arg || !check_number(global_var.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n ", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	while (global_var.arg[q])
	{
		if (!isdigit(global_var.arg[q]) && global_var.arg[q] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			free_globalvar();
			exit(EXIT_FAILURE);
		}
		q++;
	}

	p = atoi(global_var.arg);

	if (global_var.quest == 1)
		add_leadnode(head, p);
	else
		add_endnode(head, p);
}

/**
 * opcode_pall - A function that prints the values on the stack
 *
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_pall(stack_t **head, unsigned int c)
{
	stack_t *current;
	(void)c;

	current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * opcode_pint - A function that prints the value of the element
 * at the top of the stack.
 *
 * @head: The head of the stack list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_pint(stack_t **head, unsigned int c)
{
	(void)c;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * opcode_pop - A function that removes the topmost element from the stack
 * @head: The head of the stack list
 * @c: The count of the line
 *
 * Return: nothing
 */
void opcode_pop(stack_t **head, unsigned int c)
{
	stack_t *buf;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	buf = *head;
	*head = (*head)->next;
	free(buf);
}

/**
 * opcode_swap - A function that swap the two topmost elements of a
 * given stack
 * @head: The head of the stack list
 * @c: The count of the line number
 * Return: nothing
 */
void opcode_swap(stack_t **head, unsigned int c)
{
	int n = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		n++;
	}

	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	(*head)->next = buf->next;

	if (buf->next != NULL)
		buf->next->prev = *head;
	buf->prev = NULL;
	buf->next = *head;
	(*head)->prev = buf;
	*head = buf;
}
