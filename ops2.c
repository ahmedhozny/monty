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

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		print_err(0, "L%u: can't sub, stack too short", line_number);

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		print_err(0, "L%u: can't div, stack too short", line_number);
	if ((*stack)->n == 0)
		print_err(0, "L%u: division by zero", line_number);

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		print_err(0, "L%u: can't mul, stack too short", line_number);

	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}
