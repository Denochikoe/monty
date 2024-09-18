#include "monty.h"

/**
 * custom_getline - Reads a line from a file and stores it in a buffer.
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: Number of characters read, or -1 on failure.
 */
int custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf;
	int c;
	size_t i = 0;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	buf = *lineptr;

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			buf = realloc(buf, *n);
			if (buf == NULL)
				return (-1);
			*lineptr = buf;
		}
		buf[i++] = c;
		if (c == '\n')
			break;
	}

	if (i == 0 && c == EOF)
		return (-1);

	buf[i] = '\0';
	return (i);
}

/**
 * handle_error - Handles cleanup during error conditions
 * @stack: Pointer to the stack
 * @line: Pointer to the line buffer
 * @file: File pointer to close
 */
void handle_error(stack_t **stack, char *line, FILE *file)
{
	free(line);
	free_stack(stack);
	fclose(file);
}

/**
 * process_file - Processes the bytecode file line by line
 * @file: Pointer to the open file to be read
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int process_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode, *arg;

	while (custom_getline(&line, &len, file) != -1)
	{
		line_number++;
		if (line[0] == '#' || line[0] == '\n' || line[0] == '\0')
			continue;
		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;
		arg = strtok(NULL, " \t\n");
		if (execute_opcode(&stack, opcode
					, line_number, arg) != 0)
		{
			handle_error(&stack, line, file);
			return (EXIT_FAILURE);
		}
	}

	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * main - Entry point of the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	if (process_file(file) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	fclose(file);
	return (EXIT_SUCCESS);
}
