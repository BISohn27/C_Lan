#include <stdio.h>

#define N_PRIME 400
#define PRIME 1223

void arr_prime(unsigned int arr[], unsigned int num);
int binary_search(unsigned int arr[], int arr_num, int prime);

int main()
{
	unsigned int arr[N_PRIME];

	arr_prime(arr, N_PRIME);

	for (int i = 0; i < N_PRIME; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

	int index = binary_search(arr, N_PRIME, PRIME);

	if (index != -1)
		printf("\n\narr[%d] = %d\n", index, PRIME);
	else
		printf("\n%d is not a prime or not one of the array,\n", PRIME);


	return 0;
}

void arr_prime(unsigned int arr[], unsigned int n)
{
	int count = 0;
	int num = 2;
	int divider = 2;

	while (1)
	{
		int isprime = 1;

		if (num >= divider * divider)
			divider = divider + 1;

		for (int i = 2; i <= divider; ++i)
		{
			if (num % i == 0 && num != 2)
			{
				isprime = 0;
				break;
			}
		}

		if (isprime == 1)
		{
			arr[count++] = num;
		}
			
		if (count > n-1)
			break;

		num++;
	}
}

int binary_search(unsigned int arr[], int arr_num, int prime)
{
	int index = 0;
	int min = 0;
	int max = arr_num - 1;
	int count = 1;

	while (max >= min)
	{
		index = (max + min) / 2;

		if (prime == arr[index])
		{
			printf("\nThe number of step: %d\n", count);
			return index;
		}
			

		else if (prime > arr[index])
			min = index + 1;

		else
			max = index - 1;

		count++;
	}

	return -1;
}
