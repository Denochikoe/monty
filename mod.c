#include "monty.h"

/**
 * _mod - Computes the remainder of the division of the second top element
 *        by the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number of the bytecode file.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
