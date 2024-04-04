#include "monty.h"

global_t global_var;

/**
 * free_globalvar - A function that free up global variable
 *
 * Return: nothing
 */
void free_globalvar(void)
{
	free_node(global_var.head);
	free(global_var.buffer);
	fclose(global_var.fdes);
}

/**
 * free_node - A function that free the buffer of the doubly
 * linked list
 * @head: The head of the doubly linked list
 * 
 * Return: nothing
 */
void free_node (stack_t *head)
{
	stack_t *buff;

	while (head != NULL)
	{
		buff = head;
		head = head->next;
		free(buff);
	}
}
 /**
 * globalvar_init - A function that initialise the global variable
 *
 * @fdes: file descriptor
 *
 * Return: nothing
 */
void globalvar_init(FILE *fdes)
{
	global_var.quest = 1;
	global_var.line = 1;
	global_var.arg = NULL;
	global_var.head = NULL;
	global_var.fdes = fdes;
	global_var.buffer = NULL;
}

/**
 * check -  A function that check the input and confirm if file
 * exist and can be opened.
 * @argc: Count of the number of arguments
 * @argv: The array vector containing the arguments
 *
 * Result: nothing
 */
FILE *check(int argc, char *argv[])
{
	FILE *fdes;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fdes = fopen(argv[1], "r");

	if (fdes == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fdes);
}
/**
 * main - The main function
 *
 * @argc: Count of the argument(s)
 * @argv: Array of the argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fdes;
	size_t siz = 256;
	ssize_t line_no = 0;
	char *code[2] = {NULL, NULL};

	fdes = check(argc, argv);	

	globalvar_init(fdes);
	line_no = getline(&global_var.buffer, &siz, fdes);
	while (line_no != -1)
	{
		code[0] = _strngcut(global_var.buffer, " \t\r\n\a");
		if (code[0] && code[0][0] != '#')
		{
			f = sel_func(code[0]);
			if (!f)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n ", global_var.line, code[0]);
				free_globalvar();
				exit(EXIT_FAILURE);
			}
			global_var.arg = _strngcut(NULL, " \t\n");
			f(&global_var.head, global_var.line);
		}
		line_no = getline(&global_var.buffer, &siz, fdes);
		global_var.line++;
	}
	free_globalvar();
	return (0);
}
