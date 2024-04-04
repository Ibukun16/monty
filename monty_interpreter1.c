#include "monty.h"

/**
 * opcode_add - A function that add up the 2 topmost
 * elements on the stack.
 * @head: The head of the stack list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_add(stack_t **head, unsigned int c)
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
		fprintf(stderr, "L%ud can't add, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n += (*head)->n;
	opcode_pop(head, c);
}

/**
 * opcode_nop - A function that does nothing
 * @head: Thge head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_nop(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
}

/**
 * opcode_sub - A function that subtracts the top element from the second
 * element at the top of the stack
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_sub(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}
	if (v < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n -= (*head)->n;
	opcode_pop(head, c);
}


/**
 * opcode_queue - A function that set the data format to a queue
 * (FIFO)
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void opcode_queue(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;

	global_var.quest = 0;
}

/**
 * opcode_stack - A function that set the data format to a stack
 * (LIFO)
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return nothing
 */
void opcode_stack(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;

	global_var.quest = 1;
}
