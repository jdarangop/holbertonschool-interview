#include "sort.h"

/**
 * radix_sort - Sorts integers using Radix sort algorithm.
 * @array: List of data
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int tmp_max, i, j;

	if (size < 2)
		return;
	tmp_max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > tmp_max)
			tmp_max = array[i];
	}
	for (j = 1; tmp_max / j > 0; j *= 10)
	{
		radix_count(array, size, j);
		print_array(array, size);
	}
}

/**
 * radix_count - Sorts integers using Radix sort algorithm.
 * @array: List of data
 * @size: Size of the array
 * @j: exponential
 */
void radix_count(int *array, int size, int j)
{
	int *result;
	int i;
	int counter[10] = {0};

	result = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
		counter[(array[i] / j) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		counter[i] += counter[i - 1];
	}
	for (i = (int)size - 1; i >= 0; i--)
	{
		result[counter[(array[i] / j) % 10] - 1] = array[i];
		counter[(array[i] / j) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = result[i];
	}
	free(result);
}
