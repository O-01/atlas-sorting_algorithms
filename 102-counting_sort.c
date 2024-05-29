#include "sort.h"

/**
 * counting_sort - sorts array of integers in ascending order using counting
 *                 sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int max_val = 0, *thingy = NULL, *output = NULL;
	size_t iter = 0;

	if (!array || size < 2)
		return;
	for (; iter < size; ++iter)
		if (array[iter] > max_val)
			max_val = array[iter];
	thingy = calloc(max_val + 1, sizeof(int));
	if (!thingy)
		return;
	for (iter = 0; iter < size; ++iter)
		thingy[array[iter]]++;
	for (iter = 1; (int)iter < max_val + 1; ++iter)
		thingy[iter] += thingy[iter - 1];
	output = calloc(size, sizeof(int));
	if (!output)
		return;
	for (iter = 0; iter < size; ++iter)
		output[thingy[array[iter]] - 1] = array[iter];
	for (iter = 0; iter < size; ++iter)
		array[iter] = output[iter];
	print_array(thingy, max_val + 1);
	free(thingy), free(output);
}
