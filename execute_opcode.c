#include "monty.h"

/**
 * execute_opcode - Executes an opcode by calling the corresponding function.
 * @stack: Double pointer to the head of the stack.
 * @opcode: The opcode to execute.
 * @line_number: The current line number in the bytecode file.
 * @arg: The argument (if any) for the opcode.
 *
 * Description: If the opcode is unknown, an error message is printed,
 * and the program exits with EXIT_FAILURE.
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number, char *arg)
{
    instruction_t instructions[] = {
        {"push", NULL},
        {"pall", pall},
        {NULL, NULL}
    };
    int i;

    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number, arg);
        return;
    }

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
