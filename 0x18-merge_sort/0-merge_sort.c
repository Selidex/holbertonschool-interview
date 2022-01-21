#include "sort.h"

/**
 * merge - merges the splits of the array
 * @arr: the array being merged into
 * @l: left of array
 * @m: middle of array
 * @r: right of array
 * Return: void, no return
 */

void merge(int arr[], int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;
	int L[100], R[100];

	for (i = 0; i < n1; i++)
	{	L[i] = arr[l + i];
		if (i != n1 - 1)
			printf("%d, ", L[i]);
		else
			printf("%d", L[i]);	}
	printf("\n[right]: ");
	for (j = 0; j < n2; j++)
	{	R[j] = arr[m + 1 + j];
		if (j != n2 - 1)
			printf("%d, ", R[j]);
		else
			printf("%d\n", R[j]); }
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{	arr[k] = L[i];
			i++;		}
		else
		{	arr[k] = R[j];
			j++; }
		k++;	}
	while (i < n1)
	{	arr[k] = L[i];
		i++;
		k++; }
	while (j < n2)
	{	arr[k] = R[j];
		j++;
		k++; }
	printf("[Done]: ");
	print_array(arr + l, n1 + n2); }

/**
 * helper - helper function for top down spliting an array
 * @arr: the array being split
 * @l: left side of the array
 * @r: right side of the array
 * Return: void, no return
 */

void helper(int arr[], int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		helper(arr, l, m);
		helper(arr, m + 1, r);
		printf("Merging...\n");
		printf("[left]: ");
		merge(arr, l, m, r);
	}
}

/**
 * merge_sort - performs a merge sort on the array
 * @array: the array being sorted
 * @size: the size of the array being sorted
 * Return: void, no return
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	if (size < 2)
		return;
	helper(array, 0, size - 1);
}
