#include "monty.h"

/**
 * nop - Doesn’t do anything.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number of the bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
