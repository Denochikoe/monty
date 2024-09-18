#include "monty.h"

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number of the bytecode file.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

    /* Check for division by zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
