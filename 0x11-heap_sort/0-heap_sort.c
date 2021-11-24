#include "sort.h"

/**
 * max - find the max of the array
 * @a: the array
 * @n: a number
 * @i: another number
 * @j: a third number for finding max
 * @k: the final number used to find max
 * Return: the index for the max
 */

int max(int *a, int n, int i, int j, int k)
{
	int m = i;

	if (j < n && a[j] > a[m])
		m = j;
	if (k < n && a[k] > a[m])
		m = k;
	return (m);
}

/**
 * downsift - the downsift method for heap ort
 * @a: the array being heapified
 * @n: starting index for array
 * @i: ending index for array
 * @size: size for printing references
 * Return: void no return
 */

void downsift(int *a, int n, int i, size_t size)
{
	int j, t;

	while (1)
	{
		j = max(a, n, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		print_array(a, size);
		i = j;
	}
}

/**
 * heap_sort - performs the heap sort on an array
 * @array: The array being heap sorted
 * @size: the size of the array
 * Return: void, no return
 */

void heap_sort(int *array, size_t size)
{
	int i, t, n = size;

	for (i = (n - 2) / 2; i >= 0; i--)
		downsift(array, n, i, size);
	for (i = 0; i < n; i++)
	{
		t = array[n - i - 1];
		array[n - i - 1] = array[0];
		array[0] = t;
		print_array(array, n);
		downsift(array, n - i - 1, 0, size);
	}
}
