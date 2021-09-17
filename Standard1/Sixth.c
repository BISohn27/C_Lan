#include <stdio.h>

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	int arr[] = { 64,25,12,22,11,100,10,3 };
	selectionSort(arr, 8);
	printArray(arr, 8);
	return 0;
}

void swap(int* xp, int* yp)
{
	int temp= *xp;
	*xp = *yp;
	*yp = temp;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

void selectionSort(int arr[], int n)
{
	int min_idx;

	for (int i = 0; i < n-1; ++i)
	{
		min_idx = i;

		for (int j = i+1; j < n; ++j)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
	}
}

