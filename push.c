#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * push - Pushes an integer onto the stack or queue.
 * @stack: Pointer to the stack (head node).
 * @line_number: The line number of the current opcode in the script.
 * @arg: The argument for the push operation (integer value as a string).
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int num;
	stack_t *temp;

	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (mode == 0)
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		if (*stack == NULL)
		{
			*stack = new_node;
		}
		else
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
	}
}
