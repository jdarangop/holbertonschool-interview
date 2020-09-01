#include "sort.h"

/**
 * swap - swap two nodes.
 * @array: array to be sorted.
 * @size: size of the array.
 * @old: old index of the value.
 * @new: new index of the value.
 *
 * Return: void.
 */
void swap(int *array, size_t size, int old, int new)
{
	int tmp;

	tmp = array[old];
	array[old] = array[new];
	array[new] = tmp;
	print_array(array, size);
}

/**
 * reverse - compares with its leaves nodes.
 * @array: array to be sorted.
 * @size: size of the array.
 * @tmp_size: size of the subarray.
 * @index: index of the parent node for comparison.
 *
 * Return: void.
 */
void reverse(int *array, size_t size, int tmp_size, int index)
{
	int tmp, left, right;

	tmp = index;
	left = 2 * index;
	right = (2 * index) + 1;
	while (left <= tmp_size || right <= tmp_size)
	{
		if (left <= tmp_size && right <= tmp_size)
		{
			if (array[left - 1] > array[tmp - 1] || array[right - 1] > array[tmp - 1])
			{
				if (array[left - 1] > array[right - 1])
				{
					swap(array, size, tmp - 1, left - 1);
					tmp = left;
				}
				else
				{
					swap(array, size, tmp - 1, right - 1);
					tmp = right;
				}
			}
		}
		else if (left <= tmp_size && array[left - 1] > array[tmp - 1])
		{
			swap(array, size, tmp - 1, left - 1);
			tmp = left;
		}
		else if (right <= tmp_size && array[right - 1] > array[tmp - 1])
		{
			swap(array, size, tmp - 1, right - 1);
			tmp = right;
		}
		else
			break;
		left = 2 * tmp;
		right = (2 * tmp) + 1;
	}
}

/**
 * heap_max - build the data structure max-heap.
 * @array: array to be sorted.
 * @size: size of the array.
 * @tmp_size: size of the subarray.
 *
 * Return: void.
 */
void heap_max(int *array, size_t size, int tmp_size)
{
	int index, tmp, parent, left, right;

	index = tmp_size;
	while (index > 1)
	{
		tmp = index;
		while (tmp > 1)
		{
			parent = tmp / 2;
			left = 2 * parent;
			right = (2 * parent) + 1;
			if (right <= tmp_size && array[right - 1] > array[parent - 1])
			{
				if (array[left - 1] > array[right - 1])
				{
					swap(array, size, left - 1, parent - 1);
					reverse(array, size, tmp_size, left);
				}
				else
				{
					swap(array, size, right - 1, parent - 1);
					reverse(array, size, tmp_size, right);
				}
				tmp = parent;
			}
			else if (array[left - 1] > array[parent - 1])
			{
				swap(array, size, left - 1, parent - 1);
				reverse(array, size, tmp_size, left);
				tmp = parent;
			}
			else
				break;
		}
		index--;
	}
}

/**
 * heap_sort - sort an array of integers.
 * @array: array to be sorted.
 * @size: size of the array.
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL && size <= 1)
		return;
	heap_max(array, size, (int)size);
	for (i = (int)size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);
		heap_max(array, size, i);
	}
}
