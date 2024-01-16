#include "sort.h"

/**
 * selection_sort - sort an array on integers
 * @array: an array of integers
 * @size: the length of the array
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, jMin, temp;

	for (i = 0 ; i < size ; i++)
	{
		jMin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
				continue;
			}
		}

		if (jMin != i)
		{
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
			print_array(array, size);
		}
	}
}
