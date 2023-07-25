/*
 * File_Name: 2-selection_sort.c
 * Created: 29th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: sorting_algorithms
 * Status: Submitted.!
 */

#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 *
 * Description: This function swaps two items in an array by
 *              exchanging their values.
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
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: The array to sort.
 * @size: The number of elements in the array.
 *
 * Description: This function implements the selection sort algorithm
 *              to sort an array of integers in ascending order. It
 *              repeatedly finds the minimum element from the unsorted
 *              portion of the array and places it at the beginning.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, low_idx;

	if (array != NULL)
	{
		for (i = 0; i < size - 1; i++)
		{
			low_idx = i;
			for (j = size - 1; j > i; j--)
			{
				if (array[j] < array[low_idx])
				{
					low_idx = j;
				}
			}
			if (i != low_idx)
			{
				/* Swap the minimum element with the current element */
				swap_items(array, i, low_idx);

				/* Print the current state of the array */
				print_array(array, size);
			}
		}
	}
}

