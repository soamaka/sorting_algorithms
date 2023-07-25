#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 *
 * Description: This function swaps the values at the specified indices
 *              in the given array.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_range_hoare - Sorts a sub array using the
 * quick sort algorithm and Hoare's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 *
 * Description: This function recursively sorts the sub-array using
 *              the quick sort algorithm with Hoare's partition scheme.
 *              It selects a pivot element and partitions the array into
 *              two parts, such that all elements to the left of the pivot
 *              are smaller and all elements to the right are larger. It then
 *              recursively applies the same process to the two sub-arrays.
 */
void quick_sort_range_hoare(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (TRUE)
	{
		/* Find element on the left side that should be on the right side */
		do {
			i++;
		} while (array[i] < pivot);

		/* Find element on the right side that should be on the left side */
		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			/* Swap the elements */
			swap_items(array, i, j);
			print_array(array, size);
		}
		else
		{
			/* Partitioning is complete */
			break;
		}
	}

	/* Recursively sort the two sub-arrays */
	quick_sort_range_hoare(array, low, j - (j == high), size);
	quick_sort_range_hoare(array, j - (j == high) + 1, high, size);
}

/**
 * quick_sort_hoare - Sorts an array using the quick sort algorithm
 * and Hoare's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 *
 * Description: This function sorts the given array using the quick sort
 *              algorithm with Hoare's partition scheme. It calls the
 *              quick_sort_range_hoare function to sort the entire array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if ((array != NULL) && (size > 1))
	{
		/* Sort the entire array */
		quick_sort_range_hoare(array, 0, size - 1, size);
	}
}
