#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: an array of integers
 * @size: the length of th array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int tmp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
