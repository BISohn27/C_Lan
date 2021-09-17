#include <stdio.h>
#include <string.h>

void swap(char** xp, char** yp);
void printArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple","Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("%d", strcmp(arr[1], arr[2]));

	printArray(arr, n);

	selectionSort(arr, n);

	printArray(arr, n);

	return 0;
}

void selectionSort(char* arr[], int n)
{
	int min_idx;

	for (int i = 0; i < n - 1; ++i)
	{
		min_idx = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(arr[j], arr[min_idx]) <0)
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
	}
}

void swap(char** xp, char** yp)
{
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printArray(char* arr[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%s ", arr[i]);
}