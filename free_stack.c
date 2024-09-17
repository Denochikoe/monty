#include "monty.h"

/**
 * free_stack - Frees all nodes in the stack.
 * @stack: Double pointer to the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current, *next;

    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
