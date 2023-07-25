#include "sort.h"

/**
 * radix_sort - Sorts an array using the radix sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 *
 * Description: This function implements the radix sort algorithm to sort
 *              the array in ascending order. It uses the base-10 counting
 *              sort algorithm for each digit position from the least
 *              significant digit to the most significant digit.
 */
void radix_sort(int *array, size_t size)
{
	int digits = 0, i, j, max_val = 0, base = 10, pow_b;
	int *bins = NULL, *counts = NULL, sorted = FALSE;

	if ((array == NULL) || (size < 2))
		return;

	/* Find the maximum value in the array to determine the number of digits */
	for (i = 0; i < (int)size; i++)
		max_val = array[i] > max_val ? array[i] : max_val;

	/* Calculate the number of digits in the maximum value */
	while (max_val > 0)
		digits++, max_val /= 10;

	/* Allocate memory for the temporary arrays */
	bins = malloc(sizeof(int) * size);
	counts = malloc(sizeof(int) * base);
	digits = ((bins == NULL) || (counts == NULL) ? 0 : digits);

	/* Perform counting sort for each digit position */
	for (i = 0, pow_b = 1; i < digits; i++, pow_b *= base)
	{
		/* Initialize counts array with zeros */
		for (j = 0; j < base; j++)
			counts[j] = 0;

		/* Count the occurrences of each digit */
		for (j = 0; j < (int)size; j++)
			counts[(array[j] / pow_b) % base]++;

		/* Calculate cumulative counts */
		for (j = 1; j < base; j++)
			counts[j] += counts[j - 1];

		/* Place elements into bins array in sorted order based on the current digit */
		for (j = (int)size - 1; j >= 0; j--)
			bins[--counts[(array[j] / pow_b) % base]] = array[j];

		/* Copy elements back to the original array */
		for (j = 0; j < (int)size; j++)
			array[j] = bins[j];

		/* Print the array after each pass */
		print_array(array, size);
		sorted = TRUE;
	}

	/* Print the array if it is already sorted or contains all zeros */
	if ((!max_val && !sorted) && (size > 0))
		print_array(array, size);

	/* Free the allocated memory */
	if (bins != NULL)
		free(bins);
	if (counts != NULL)
		free(counts);
}
