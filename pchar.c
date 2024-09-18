#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode in the bytecode file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
