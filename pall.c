#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the bytecode file (unused).
 *
 * Description: If the stack is empty, nothing is printed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tail;

	(void)line_number;

	if (mode == 0)
	{
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
	else
	{
		tail = *stack;
		while (tail && tail->next)
			tail = tail->next;
		while (tail)
		{
			printf("%d\n", tail->n);
			tail = tail->prev;
		}
	}
}
