#include "sort.h"

/**
 * shell_sort - sorts array of integers in ascending order using shell sort
 *              algorithm, using Knuth sequence
 * @array: array of integers to be sorted
 * @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, iter, j;
	int tmp;

	if (!array || !size)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	for (gap /= 3; gap; gap /= 3)
	{
		for (iter = gap; iter < size; ++iter, array[j] = tmp)
		{
			tmp = array[iter];
			for (j = iter; j >= gap && tmp < array[j - gap]; j -= gap)
				array[j] = array[j - gap];
		}
		print_array(array, size);
	}
}
