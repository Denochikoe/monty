/* add.c */
#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: The current line number of the bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	(*stack)->next->n = sum;

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}
