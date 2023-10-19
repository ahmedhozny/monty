#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		print_err(0, "L%u: can't add, stack too short", line_number);

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * nop - doesn’t do anything :)
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
