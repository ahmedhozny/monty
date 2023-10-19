#include "monty.h"

session_t session = {NULL, 0, NULL};

/**
 * main - Main block
 * @argc: number of arguments
 * @argv: the arguments
 * Return: 0 on success, otherwise on failure
 */
int main(int argc, char **argv)
{
	char buffer[120], *token, *temp;

	atexit(cleanup);
	if (argc != 2)
		print_err(0, "USAGE: monty file");
	session.file = fopen(argv[1], "r");
	if (session.file == NULL)
		print_err(0, "Error: Can't open file %s", argv[1]);
	session.line_num = 0;
	while (++session.line_num)
	{
		temp = fgets(buffer, sizeof(buffer), session.file);
		if (temp == NULL || *temp == '\0')
			break;
		token = strtok(buffer, " \t\n");
		if (token == NULL || *token == '#')
			continue;

		if (exec(token) != 0)
			print_err(0, "L%li: unknown instruction %s", session.line_num, token);
	}

	return (0);
}

/**
 * exec - Execute an opcode
 * @opcode: The opcode to execute
 *
 * Return: 0 if the opcode is found and executed, 1 if not found.
 */
int exec(char *opcode)
{
	static instruction_t instructions[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", _div},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{"pstr", pstr},

	};
	unsigned int i;

	for (i = 0; i < (sizeof(instructions) / sizeof(instructions[0])); i++)
	{
		if (!strcmp(instructions[i].opcode, opcode))
		{
			instructions[i].f(&session.stack, session.line_num);
			return (0);
		}
	}

	return (1);
}

/**
 * cleanup - cleans up resources and memory used by the program
 */
void cleanup(void)
{
	stack_t *node;

	if (session.file != NULL)
		fclose(session.file);
	node = session.stack;
	while (node)
		node = node->next, free(session.stack), session.stack = node;
}
