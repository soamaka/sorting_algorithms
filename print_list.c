#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers.
 * @list: The list to be printed.
 *
 * Description:
 * This function takes a linked list of integers as a parameter and prints the
 * elements of the list. The elements are separated by commas, and a newline
 * character is printed at the end.
 */
void print_list(const listint_t *list)
{
	int i = 0;

	/* Iterate through the list and print each element */
	while (list != NULL)
	{
		/* Print a comma and space before each element (except the first one) */
		if (i > 0)
			printf(", ");

		/* Print the current element */
		printf("%d", list->n);

		/* Move to the next node */
		list = list->next;

		/* Increment the counter */
		++i;
	}

	/* Print a newline character at the end */
	printf("\n");
}
