#include "monty.h"
#include <stdio.h>

/**
 * rotr - Rotates the stack so the last element becomes the top.
 * @stack: Pointer to the stack (head node).
 * @line_number: The line number of the current opcode in the script.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}
