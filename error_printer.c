#include "monty.h"

/**
 * print_err - prints an error message and optionally exit
 * @continues: 0 to exit, 1 to continue
 * @format: error message format and arguments
 */
void print_err(int continues, char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);

	fprintf(stderr, "\n");

	if (!continues)
		exit(EXIT_FAILURE);
}

/**
 * malloc_err - handles memory allocation failure
 * @continues: 0 to exit, 1 to continue
 */
void malloc_err(int continues)
{
	print_err(continues, "Error: malloc failed");
}
