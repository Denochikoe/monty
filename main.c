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
            return -1;
    }

    buf = *lineptr;

    while ((c = fgetc(stream)) != EOF)
    {
        if (i >= *n - 1)
        {
            *n *= 2;
            buf = realloc(buf, *n);
            if (buf == NULL)
                return -1;
            *lineptr = buf;
        }
        buf[i++] = c;
        if (c == '\n')
            break;
    }

    if (i == 0 && c == EOF)
        return -1;

    buf[i] = '\0';
    return i;
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of arguments (including the file name).
 *
 * Description: The Monty interpreter reads a bytecode file and executes
 * the specified opcodes. If the file cannot be opened, or if an error
 * occurs while reading, appropriate error messages are printed.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode, *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (custom_getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;
        arg = strtok(NULL, " \t\n");
	if (execute_opcode(&stack, opcode, line_number, arg) != 0)
	{
		free(line);
		free_stack(&stack);
		fclose(file);
		return (EXIT_FAILURE);
	}
    }

    free(line);
    free_stack(&stack);
    fclose(file);
    return (EXIT_SUCCESS);
}
