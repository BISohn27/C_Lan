#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

void multiplication_table(void);

int main()
{
	
	multiplication_table();

	return 0;
}

void multiplication_table(void)
{
	int num1 = 0, num2 = 0;

	printf("Input two numbers: ");
	scanf("%d %d", &num1, &num2);

	if (num1 < num2)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int n = num1; n <= num2; n++)
			{
				printf("%d * %d = %-5d", n, i, n * i);
			}
			printf("\n");
		}
	}

	else
	{
		for (int i = 1; i < 10; i++)
		{
			for (int n = num2; n <= num1; n++)
			{
				printf("%d * %d = %-5d", n, i, n * i);
			}
			printf("\n");
		}
	}

}