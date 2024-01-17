#include "sort.h"

/**
 * power - calcul the power
 * @a: an integer
 * @b: an integer
 * Return: the number of a power b
 */

int power(int a, int b)
{
	int i, pow = 1;

	for (i = 1; i <= b; i++)
		pow = pow * a;
	return (pow);
}

/**
 * shell_sort - that sorts an array of integers in ascending order
 * @array: an array of integers
 * @size: the length of array
 */

void shell_sort(int *array, size_t size)
{
	int *gaps, tmp = 0, k;
	size_t i, j, l;


	if (array == NULL)
		return;

	gaps = malloc(sizeof(int) * size);

	for (i = 1, l = size; i <= size; i++, l--)
		gaps[i - 1] = (power(3, l) - 1) / 2;

	i = 0;
	while (gaps[i])
	{
		for (j = gaps[i]; j < size; j++)
		{
			tmp = array[j];
			for (k = j; (k >= gaps[i]) && (array[k - gaps[i]] > tmp); k -= gaps[i])
				array[k] = array[k - gaps[i]];
			array[k] = tmp;
		}
		if ((unsigned long int)gaps[i] < size)
			print_array(array, size);
		i++;
	}
	free(gaps);
}
