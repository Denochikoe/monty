#include "monty.h"

int execute_opcode(stack_t **stack, char *opcode, unsigned int line_number, char *arg)
{
    instruction_t instructions[] = {
        {"pall", pall},
        /* Add other non-arg opcodes here */
        {NULL, NULL}
    };
    int i;

    /* Special handling for 'push' which has an additional argument */
    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number, arg);  /* Pass the extra 'arg' argument */
        return 0;
    }

    /* Handle all other opcodes */
    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);  /* Call without 'arg' */
            return 0;
        }
    }

    /* If opcode is not found */
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    return (-1);
}
