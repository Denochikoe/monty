#include "monty.h"
#include <stdio.h>

/**
 * stack - Sets the format to stack (LIFO).
 * @stack: Pointer to the stack (head node).
 * @line_number: The line number of the current opcode in the script.
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = 0;
}
