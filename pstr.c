#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode in the bytecode file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (current == NULL)
	{
		printf("\n");
		return;
	}

	while (current != NULL && current->n != 0 
			&& current->n >= 0 && current->n <= 127)
	{
		if (current->n >= 32 && current->n <= 126)
			putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
