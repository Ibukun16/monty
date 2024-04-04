#include "monty.h"

/**
 * opcode_div - A function that divides the second element on the
 * stack by the topmost element on the stack
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_div(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}
	if (v < 2)
	{
		fprintf(stderr, "L%d: can't div, stack is too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n /= (*head)->n;
	opcode_pop(head, c);
}

/**
 * opcode_mul - A function that multiplies the topmost element on the
 * stack with the second element on the stack
 * @head: The head of the doubly linked list
 * @c; The count of the line number
 *
 * Return: nothing
 */
void opcode_mul(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}
	if (v < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n *= (*head)->n;
	opcode_pop(head, c);
}

/**
 * opcode_mod - A function that gives the reminder from a division of
 * of the second element on the stack with the first element.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_mod(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}

	if (v < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n %= (*head)->n;
	opcode_pop(head, c);
}

/**
 * opcode_pchar - A function that print the char value of the first
 * element on the stack.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_pchar(stack_t **head, unsigned int c)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * opcode_pstr - A function that prints the string on the stack
 *
 * @head: head of the doubly linked list
 * @c: The count of the line number(s)
 *
 * Return: nothing
 */
void opcode_pstr(stack_t **head, unsigned int c)
{
	stack_t *buf;
	(void)c;

	buf = *head;

	while (buf && buf->n > 0 && buf->n < 128)
	{
		printf("%c", buf->n);
		buf = buf->next;
	}
	printf("\n");
}
