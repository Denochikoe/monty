#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number of the bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
