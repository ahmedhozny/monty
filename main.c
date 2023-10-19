#include "monty.h"

session_t session = {NULL, 0, NULL, NULL};

/**
 * main - Main block
 * @argc: number of arguments
 * @argv: the arguments
 * Return: 0 on success, otherwise on failure
 */
int main(int argc, char **argv)
{
	size_t i, flag;
	char buffer[120], *token, *temp;

	atexit(cleanup);
	init_session();
	if (argc != 2)
		print_err(0, "USAGE: monty file");
	session.file = fopen(argv[1], "r");
	if (session.file == NULL)
		print_err(0, "Error: Can't open file %s", argv[1]);
	session.line_num = 0;
	while (++session.line_num)
	{
		flag = 0;
		temp = fgets(buffer, sizeof(buffer), session.file);
		if (temp == NULL || *temp == '\0')
			break;
		token = strtok(buffer, " \t\n");
		if (token == NULL)
			continue;
		for (i = 0; i < 5 && !flag; i++)
		{
			if (!strcmp(session.instructions[i].opcode, token))
				session.instructions[i].f(&session.stack, session.line_num), flag = 1;
		}

		if (flag == 0)
			print_err(0, "L%li: unknown instruction %s", session.line_num, token);
	}

	return (0);
}

/**
 * init_session - initializes the session data structure
 */
void init_session(void)
{
	session.instructions = malloc(sizeof(instruction_t) * 5);
	if (session.instructions == NULL)
		malloc_err(0);
	session.instructions[0].opcode = "push", session.instructions[0].f = push;
	session.instructions[1].opcode = "pall", session.instructions[1].f = pall;
	session.instructions[2].opcode = "pint", session.instructions[2].f = pint;
	session.instructions[3].opcode = "pop", session.instructions[3].f = pop;
	session.instructions[4].opcode = "swap", session.instructions[4].f = swap;

}

/**
 * cleanup - cleans up resources and memory used by the program
 */
void cleanup(void)
{
	stack_t *node;

	free(session.instructions);
	if (session.file != NULL)
		fclose(session.file);
	node = session.stack;
	while (node)
		node = node->next, free(session.stack), session.stack = node;
}
