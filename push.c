#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the opcode occurs.
 * @arg: The argument to be pushed.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int num;

    if (!arg || !is_integer(arg)) /* Validate the argument */
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    num = atoi(arg);  /* Convert argument to integer */
    new_node = malloc(sizeof(stack_t));  /* Allocate memory for new node */
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;  /* Update the top of the stack */
}

