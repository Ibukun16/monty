#include "monty.h"
/**
 * _calloc - A function that concatenate two strings specially
 * @nmemb: - number of elements
 * @type: type of element
 *
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int type)
{
	void *buf = NULL;
	unsigned int i;

	if (nmemb == 0 || type == 0)
		return (NULL);
	buf = malloc(nmemb * type);
	for (i = 0; i < (nmemb * type); i++)
		*((char *)buf + i) = 0;
	return (buf);
}

/**
 * _realloc - A function that change the memory size
 * and copy content into the memory
 * @p: A pointer to the reallocated memory
 * @old: previous size of the memory space
 * @new: The new size of the memory space
 *
 * Return: nothing
 */
void *_realloc(void *p, unsigned int old, unsigned int new)
{
	char *buf;
	unsigned int i;

	if (new == old)
		return (p);
	if (p == NULL)
	{
		buf = malloc(new);
		if (!buf)
			return (NULL);
		return (buf);
	}
	if (new == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	if (new > old)
	{
		buf = malloc(new);
		if (!buf)
			return (NULL);
		for (i = 0; i < old; i++)
			buf[i] = *((char *)p + i);
		free(p);
	}
	else
	{
		buf = malloc(new);
		if (!buf)
			return (NULL);
		for (i = 0; i < new; i++)
			buf[i] = *((char *)p + i);
		free(p);
	}
	return (buf);
}
