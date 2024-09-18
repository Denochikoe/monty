#include "monty.h"

/**
 * _mul - Multiplies the second top element of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number of the bytecode file.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
