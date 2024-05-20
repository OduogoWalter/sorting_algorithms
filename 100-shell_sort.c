#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm with the Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Find max gap size using the Knuth sequence less than the array size */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	/* Start with the largest gap and reduce the gap */
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		/* Perform a gapped insertion sort */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}

		/* Print the array after each interval */
		print_array(array, size);
	}
}
