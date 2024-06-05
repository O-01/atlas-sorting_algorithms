#include "sort.h"

static void sort_merge(int *array, size_t lo, size_t hi);
static void merge(int *array, size_t lo, size_t mid, size_t hi);

/**
 * merge_sort - sorts array of integers in ascending order using merge sort
 *              algorithm
 * @array: integer array to be sorted in ascending order
 * @size: length of array to be sorted
*/
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_merge(array, 0, size - 1);
}

/**
 * merge - merge
 * @array: incompletely sorted integer array
 * @lo: first index of input array
 * @hi: last index of input array
*/
static void sort_merge(int *array, size_t lo, size_t hi)
{
	size_t mid = lo + (hi - lo - 1) / 2;

	if (lo < hi)
	{
		sort_merge(array, lo, mid);
		sort_merge(array, mid + 1, hi);
		merge(array, lo, mid, hi);
	}
}

/**
 * merge - .
 * @array:
 * @lo:
 * @mid:
 * @hi:
*/
static void merge(int *array, size_t lo, size_t mid, size_t hi)
{
	size_t lo_len = mid - lo + 1, hi_len = hi - mid;
	int in_lo[1024], in_hi[1024];
	size_t iter = 0, jter = 0, pos = lo;

	write(1, "Merging...\n", 11);
	for (; iter < lo_len; ++iter)
		in_lo[iter] = array[lo + iter];
	write(1, "[left]: ", 8), print_array(in_lo, lo_len);
	for (iter = 0; iter < hi_len; ++iter)
		in_hi[iter] = array[mid + 1 + iter];
	write(1, "[right]: ", 9), print_array(in_hi, hi_len);
	for (iter = 0; pos <= hi; ++pos)
	{
		if (iter < lo_len && (jter >= hi_len || in_lo[iter] <= in_hi[jter]))
			array[pos] = in_lo[iter], iter++;
		else
			array[pos] = in_hi[jter], jter++;
	}
	write(1, "[Done]: ", 8), print_array(&array[lo], hi - lo + 1);
}
