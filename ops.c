#include "monty.h"

/**
 * push - pushes an integer onto the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	stack_t *node;

	token = strtok(NULL, " \t\n");
	if (!isInteger(token))
		print_err(0, "L%u: usage: push integer", line_number);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_err(0);
	node->n = atoi(token);
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}

/**
 * pall - prints stack elements
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;

	(void) line_number;
	while (cur)
		fprintf(stdout, "%d\n", cur->n), cur = cur->next;
}

/**
 * pint - prints the top of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		print_err(0, "L%u: can't pint, stack empty", line_number);
	fprintf(stdout, "%d\n", (*stack)->n);
}
