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

/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		print_err(0, "L%u: can't pchar, stack empty", line_number);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		print_err(0, "L%u: can't pchar, value out of range", line_number);

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void) line_number;
	while (ptr)
	{
		if ((ptr)->n < 1 || (ptr)->n > 127)
			break;
		fprintf(stdout, "%c", ptr->n), ptr = ptr->next;
	}

	fprintf(stdout, "\n");
}

/**
 * rotl - rotates the stack to the top.
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	(*stack)->next->prev = NULL;
	ptr = (*stack)->next;
	(*stack)->next = NULL;
	*stack = ptr;
}

/**
 * rotr - rotates the stack to the bottom.
 *
 * @stack: pointer to the stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *ptr = NULL;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (*stack)
	{
		ptr = malloc(sizeof(stack_t));
		if (ptr == NULL)
			malloc_err(0);
		ptr->n = (*stack)->n;
		ptr->next = new;
		if (new != NULL)
			new->prev = ptr;
		new = ptr;

		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
	}

	free(*stack);
	*stack = new;
}
