#include <stdio.h>

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @size: Number of elements in @array.
 *
 * Description:
 * Function takes an array of integers & the size of the array as parameters
 * and prints the elements of the array. The elements are separated by commas,
 * and a newline character is printed at the end.
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	/* Iterate through the array and print each element */
	while ((array != NULL) && (i < size))
	{
		/* Print a comma and space before each element (except the first one) */
		if (i > 0)
			printf(", ");

		/* Print the current element */
		printf("%d", array[i]);

		/* Move to the next element */
		++i;
	}

	/* Print a newline character at the end */
	printf("\n");
}
