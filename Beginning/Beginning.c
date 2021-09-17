#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN 30

int main()
{
	char choice[LEN] = { 0, };
	enum spectrum color;
	bool color_is_found = false;

	while (1)
	{
		printf("Input a color name (empty line to quit):\n");

		if (scanf("%[^\n]%*c", choice) == 0)
			break;

		else
		{
			for (color = red; color <= blue; ++color)
			{
				if (strcmp(colors[color], choice) == 0)
				{
					switch (color)
					{
					case red:
						printf("Red roses\n");
						color_is_found = true;
						break;

					case orange:
						printf("Orange Melons\n");
						color_is_found = true;
						break;

					case yellow:
						printf("Yellow sunflowers\n");
						color_is_found = true;
						break;

					case green:
						printf("Green apples\n");
						color_is_found = true;
						break;

					case blue:
						printf("Blue ocean\n");
						color_is_found = true;
						break;
					}
				}
				else
					color_is_found = false;

			}
			if (color_is_found == false)
				printf("Please try different color %s\n", choice);
		}
	}
}
