#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number in the bytecode file.
 * @arg: The argument (integer) to push onto the stack.
 *
 * Description: If the argument is not a valid integer or is missing,
 * prints an error message and exits with EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    int num;
    unsigned int i;

    if (!arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (i = 0; arg[i] != '\0'; i++)
    {
        if (i == 0 && arg[i] == '-')
            continue;
        if (!isdigit(arg[i]))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    num = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
