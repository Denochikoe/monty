#include "monty.h"
#include <stdio.h>

/**
 * queue - Sets the format to queue (FIFO).
 * @stack: Pointer to the stack (head node).
 * @line_number: The line number of the current opcode in the script.
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = 1;
}
