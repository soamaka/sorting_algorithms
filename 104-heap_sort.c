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
 * Description: This function swaps the values of two items in the array.
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
 * sift_down - Moves the largest element in an array to its correct
 * sorted position in a max-heap sub-array.
 * @array: The array to sort.
 * @arr_size: The length of the array.
 * @size: The length of the max heap sub-array.
 * @pos: The position of the largest element in the max heap sub-array.
 *
 * Description: This function compares the element at the given position
 *              with its children and swaps it with the larger
 *              child if necessary,
 *              ensuring that the max-heap property is maintained.
 *              It continues this process until the element is in
 *              its correct sorted position.
 */
void sift_down(int *array, int arr_size, int size, int pos)
{
	int j, child;

	j = pos;
	while (j < (size / 2))
	{
		child = (2 * j) + 1;
		if ((child < (size - 1)) && (array[child] < array[child + 1]))
			child++;
		if (array[j] >= array[child])
			return;
		swap_items(array, j, child);
		print_array(array, arr_size);
		j = child;
	}
}

/**
 * build_max_heap - Builds a max heap binary tree with the given array.
 * @array: The array to convert to a max heap binary tree.
 * @size: The length of the array.
 *
 * Description: This function converts the given array into a max
 * .......heap binary tree
 *              by repeatedly calling sift_down on each parent
 *              ......node starting from
 *              the last non-leaf node up to the root.
 */
void build_max_heap(int *array, int size)
{
	int a;

	for (a = (size / 2) - 1; a >= 0; a--)
	{
		sift_down(array, size, size, a);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 *
 * Description: This function sorts the array using the heap sort algorithm.
 *              It first builds a max heap from the array, ensuring that the
 *              largest element is at the root. It then repeatedly swaps the
 *              root element with the last unsorted element, reduces the size
 *              of the heap, and calls sift_down to restore the
 *              max heap property.
 *              The process continues until the entire array is sorted.
 */
void heap_sort(int *array, size_t size)
{
	int i, n;

	build_max_heap(array, size);
	n = size;
	for (i = 0; i < (int)size; i++)
	{
		swap_items(array, --n, 0);
		if (n != 0)
		{
			print_array(array, size);
			sift_down(array, size, n, 0);
		}
	}
}
