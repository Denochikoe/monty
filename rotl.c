#include "monty.h"
#include <stdio.h>

/**
 * rotl - Rotates the stack so the top element becomes the last.
 * @stack: Pointer to the stack (head node).
 * @line_number: The line number of the current opcode in the script.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	top = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = top->next;
	(*stack)->prev = NULL;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}
