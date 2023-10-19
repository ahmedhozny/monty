#include "monty.h"

/**
 * mod - gets the remainder of dividing second top element by the top element
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		print_err(0, "L%u: can't mod, stack too short", line_number);
	if ((*stack)->n == 0)
		print_err(0, "L%u: division by zero", line_number);

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
