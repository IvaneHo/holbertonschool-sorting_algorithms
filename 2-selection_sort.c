#include "sort.h"

/**
 * selection_sort - Sort the elements of an array with "selection sort".
 *
 * Description: Repeatedly check for the smallest (or largest)
 *              number in an array.
 *
 * @array: The array to sort.
 * @size: The size of the array to sort.
 *
 * Return: Nothing (void).
 */

void selection_sort(int *array, size_t size)
{
	size_t index1, index2, index_temp;
	int temp, swapped;

	if (array == NULL || size < 2)
		return;

	for (index1 = 0; index1 < size - 1; index1++)
	{
		temp = array[index1];
		swapped = 0;
		for (index2 = index1; index2 < size; index2++)
		{
			if (array[index1] > array[index2] && temp > array[index2])
			{
				temp = array[index2];
				index_temp = index2;
				swapped = 1;
			}
		}
		if (swapped == 0)
			continue;

		array[index_temp] = array[index1];
		array[index1] = temp;
		print_array(array, size);
	}
}