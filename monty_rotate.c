#include "monty.h"

/**
 * opcode_rotl - A function that rotate the topmost element to the bottom
 * and rotate the second element to the top.
 * @head; The head of the doubly linked list
 * @c: The count of the number line
 *
 * Return: nothing
 */
void opcode_rotl(stack_t **head, unsigned int c)
{
	stack_t *buff = NULL;
	stack_t *buf = NULL;
	(void)c;

	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
		return;

	buff = (*head)->next;
	buf = *head;

	while (buf->next != NULL)
		buf = buf->next;

	buff->prev = NULL;
	buf->next = *head;
	(*head)->next = NULL;
	(*head)->prev = buf;
	*head = buff;
}

/**
 * opcode_rotr - A function that rotates the elements on the stack
 * in reverse order.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return:nothing
 */
void opcode_rotr(stack_t **head, unsigned int c)
{
	stack_t *node = NULL;
	(void)c;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	node = *head;

	while (node->next != NULL)
		node = node->next;

	node->prev->next = NULL;
	node->next = *head;
	node->prev = NULL;
	(*head)->prev = node;
	*head = node;
}
