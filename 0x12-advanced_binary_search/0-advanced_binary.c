#include "search_algos.h"

/**
 * binarySearch - advanced binary search, recursively
 * @arr: the array
 * @l: the size of the array
 * @r: the value being searched for
 * @x: the offset for the array
 * Return: -1 if value not found, or the index of the first instance found
 */

int binarySearch(int arr[], int l, int r, int x)
{
	int i, mid;

	if (r >= l)
	{
		printf("Searching in array: %d", arr[l]);
		for (i = l + 1; i <= r; i++)
			printf(", %d", arr[i]);
		printf("\n");

		mid = l + (r - l) / 2;

		if (arr[mid] == x)
		{
			if (arr[mid - 1] == x && mid != 0)
				return (binarySearch(arr, l, mid, x));
			return (mid);
		}
		if (arr[mid] > x)
			return (binarySearch(arr, l, mid, x));

		return (binarySearch(arr, mid + 1, r, x));
	}

	return (-1);
}

/**
 * advanced_binary - entrance function for an advanced binary search algo
 * @array: the array being searched
 * @size: the size of the array
 * @value: the value being searched for
 * Return: the index where the value is found, -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binarySearch(array, 0, size - 1, value));
}
