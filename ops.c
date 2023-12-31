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

/**
 * pop - remove the top element from the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (*stack == NULL)
		print_err(0, "L%u: can't pop an empty stack", line_number);
	cur = (*stack)->next;
	if (cur != NULL)
		cur->prev = NULL;
	free((*stack));
	*stack = cur;
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		print_err(0, "L%u: can't swap, stack too short", line_number);

	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	(*stack)->prev = ptr;
	ptr->next = (*stack);
	ptr->prev = NULL;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack);
	*stack = ptr;
}
