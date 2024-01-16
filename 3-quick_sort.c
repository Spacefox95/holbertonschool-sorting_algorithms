#include "sort.h"

/**
 * partition - divides array into two partitions
 * @array: an array of integers
 * @start_index: this is the lower bound of the portion to be sorted
 * @end_index: this is the end index of the portion to be sorted
 * @size: the length of array
 * Return: the final partition index
 */

int partition(int *array, int start_index, int end_index, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[end_index];
	i = start_index;

	for (j = start_index; j < end_index; j++)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[end_index];
	array[end_index] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}

/**
 * quicksort - that sorts an array of integers
 * @array: an array of integers
 * @start_index: this is the lower bound of the portion to be sorted
 * @end_index: this is the end index of the portion to be sorted
 * @size: the length of array
 */
void quicksort(int *array, int start_index, int end_index, size_t size)
{
	int p;

	if (start_index >= end_index || start_index < 0)
		return;

	p = partition(array, start_index, end_index, size);
	quicksort(array, start_index, p - 1, size);
	quicksort(array, p + 1, end_index, size);
}
/**
 * quick_sort - that sorts an array of integers
 * @array: an array of integers
 * @size: the lenght of array
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
