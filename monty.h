#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct session_s - struct to store session-related data
 * @file: file pointer
 * @line_num: current line number
 * @instructions: array of all instructions
 * @stack: pointer to a stack data structure
 */
typedef struct session_s
{
	FILE *file;
	size_t line_num;
	instruction_t *instructions;
	stack_t *stack;

} session_t;

extern session_t session;

void init_session(void);
void cleanup(void);

void print_err(int continues, char *format, ...);
void malloc_err(int continues);

int isInteger(const char *str);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

#endif
