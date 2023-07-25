#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef UNDEF
#define UNDEF -1
#endif

#ifndef SWAP
#define SWAP(array, a, b) \
	{                       \
		tmp = array[a];       \
		array[a] = array[b];  \
		array[b] = tmp;       \
	}
#endif

/**
 * struct listint_s - Represents a doubly linked list node.
 *
 * @n: The integer stored in the node.
 * @prev: Pointer to the previous element of the list.
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	/* The integer stored in the node. */
	const int n;

	/* Pointer to the previous element of the list. */
	struct listint_s *prev;

	/* Pointer to the next element of the list. */
	struct listint_s *next;
} listint_t;

/**
 * print_array - Prints an array of integers.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void print_array(const int *array, size_t size);

/**
 * print_list - Prints a doubly linked list of integers.
 *
 * @list: Pointer to the head of the list.
 */
void print_list(const listint_t *list);

/**
 * swap_items - Swaps two elements of an array.
 *
 * @array: Pointer to the array.
 * @l: Index of the left element.
 * @r: Index of the right element.
 */
void swap_items(int *array, size_t l, size_t r);

/**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the list.
 * @l: Pointer to the left node.
 * @r: Pointer to the right node.
 */
void swap_nodes(listint_t **list, listint_t *l, listint_t *r);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using
 *                        the insertion sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list2 - Sorts a doubly linked list of integers using
 *                         the insertion sort algorithm (optimized).
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list2(listint_t **list);

/**
 * selection_sort - Sorts an array of integers using the selection sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size);

/**
 * quick_sort_range_lomuto - Sorts a range of an array using the Lomuto partition
 *                            scheme and the quicksort algorithm.
 *
 * @array: Pointer to the array.
 * @low: The starting index of the range.
 * @high: The ending index of the range.
 * @size: Size of the array.
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size);

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size);

/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size);

/**
 * get_tail - Finds the tail node of a doubly linked list.
 *
 * @list: Pointer to the head of the list.
 *
 * Return: Pointer to the tail node.
 */
listint_t *get_tail(listint_t **list);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers using
 *                      the cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list);

/**
 * counting_sort - Sorts an array of integers using the counting sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size);

/**
 * top_down_merge - Merges two subarrays of an array in a top-down manner.
 *
 * @array: Pointer to the array.
 * @array_c: Auxiliary array for merging.
 * @l: Index of the left subarray.
 * @m: Index of the middle element.
 * @r: Index of the right subarray.
 */
void top_down_merge(int *array, int *array_c, size_t l, size_t m, size_t r);

/**
 * split_merge - Recursively splits and merges an array using the merge sort algorithm.
 *
 * @array: Pointer to the array.
 * @array_c: Auxiliary array for merging.
 * @size: Size of the array.
 * @l: Index of the leftmost element.
 * @r: Index of the rightmost element.
 */
void split_merge(int *array, int *array_c, size_t size, size_t l, size_t r);

/**
 * merge_sort - Sorts an array of integers using the merge sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size);

/**
 * sift_down - Performs sift-down operation on a heap.
 *
 * @array: Pointer to the heap array.
 * @arr_size: Size of the heap array.
 * @size: Size of the heap.
 * @pos: Position of the element to sift down.
 */
void sift_down(int *array, int arr_size, int size, int pos);

/**
 * build_max_heap - Builds a max heap from an array.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void build_max_heap(int *array, int size);

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size);

/**
 * radix_sort - Sorts an array of integers using the radix sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size);

/**
 * bitonic_merge - Merges two halves of an array in bitonic order.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @low: Index of the first element in the first half.
 * @n: Number of elements to merge.
 * @ascending: Indicates if sorting order is ascending (1) or descending (0).
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t n, char ascending);

/**
 * bitonic_sort_split - Recursively sorts a bitonic sequence in bitonic order.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @low: Index of the first element in the sequence.
 * @n: Number of elements in the sequence.
 * @ascending: Indicates if sorting order is ascending (1) or descending (0).
 */
void bitonic_sort_split(int *array, size_t size, size_t low, size_t n, char ascending);

/**
 * bitonic_sort - Sorts an array of integers using the bitonic sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size);

/**
 * quick_sort_range_hoare - Sorts a range of an array using the Hoare partition
 *                          scheme and the quicksort algorithm.
 *
 * @array: Pointer to the array.
 * @low: The starting index of the range.
 * @high: The ending index of the range.
 * @size: Size of the array.
 */
void quick_sort_range_hoare(int *array, size_t low, size_t high, size_t size);

/**
 * quick_sort_hoare - Sorts an array of integers using the quicksort algorithm
 *                    with the Hoare partition scheme.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
