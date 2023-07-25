/*
 * File_Name: 0-bubble_sort.c
 * Created: 29th June, 2023
 * Author: David James Taiye (Official0mega)
 * Size_Of_File: Undefined
 * Project_Title: sorting_algorithms
 * Status: Submitted.!
 */


#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the bubble sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: The number of elements in the array.
 *
 * Description: This function implements the bubble sort algorithm
 *              to sort an array of integers in ascending order.
 *              It compares adjacent elements and swaps them if they
 *              are in the wrong order until the entire array is sorted.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				/* Swap adjacent elements */
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/* Print the current state of the array */
				print_array(array, size);
			}
		}
	}
}
