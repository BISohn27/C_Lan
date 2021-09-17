#include <stdio.h>

void greatest_common_denominator(void);

int main()
{
	greatest_common_denominator();

	return 0;
}

void greatest_common_denominator(void)
{
	int num1=0, num2=0, denominator=0;

	printf("Input two numbers: ");
	scanf("%d %d", &num1, &num2);

	if (num1 > num2)
	{
		for (int i = 1; i <= num2; i++)
		{
			if ((num1 % i == 0) && (num2 % i == 0))
				denominator = i;
			else
				continue;
		}
	}

	else
	{
		for (int i = 1; i <= num1; i++)
		{
			if ((num1 % i == 0) && (num2 % i == 0))
				denominator = i;
			else
				continue;
		}
	}

	printf("The greatest common denominator is %d.", denominator);

}