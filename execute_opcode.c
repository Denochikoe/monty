#include "monty.h"

/**
 * execute_opcode - Executes the corresponding function for a given opcode.
 * @stack: Double pointer to the top of the stack.
 * @opcode: The operation code (command) to execute.
 * @line_number: Line number where the opcode was found.
 * @arg: Argument for the push opcode.
 *
 * Return: 0 on success, or -1 if the opcode is not found.
 */
int execute_opcode(stack_t **stack
		, char *opcode, unsigned int line_number, char *arg)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	/* Special handling for 'push' which has an additional argument */
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);  /* Pass the extra 'arg' argument */
		return (0);
	}

	/* Handle all other opcodes */
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);  /* Call without 'arg' */
			return (0);
		}
	}

	/* If opcode is not found */
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (-1);
}
