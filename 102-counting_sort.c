#include "sort.h"

/**
 * counting_sort - sorts array of integers in ascending order using counting
 *                 sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int max_val = 0, *counting = NULL, *output = NULL;
	size_t iter = 0;

	if (!array || size < 2)
		return;
	for (; iter < size; ++iter)
		if (array[iter] > max_val)
			max_val = array[iter];
	counting = calloc(max_val + 1, sizeof(int));
	if (!counting)
		return;
	for (iter = 0; iter < size; ++iter)
		counting[array[iter]]++;
	for (iter = 1; (int)iter < max_val + 1; ++iter)
		counting[iter] += counting[iter - 1];
	print_array(counting, max_val + 1);
	output = calloc(size, sizeof(int));
	if (!output)
		return;
	for (iter = 0; iter < size; ++iter)
	{
		output[counting[array[iter]] - 1] = array[iter];
		counting[array[iter]]--;
	}
	for (iter = 0; iter < size; ++iter)
		array[iter] = output[iter];
	free(counting), free(output);
}
