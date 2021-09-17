#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LITERAL 30

struct name_count
{
	char first[MAX_LITERAL];
	char last[MAX_LITERAL];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);

	if (ret_val)
	{
		find = strchr(ret_val, '\n');
		
		if (find)
			*find = '\0';

		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

void receive_input(struct name_count* st)
{
	printf("Input your first name:\n>>");
	s_gets(st->first, MAX_LITERAL);

	printf("Input your last name:\n>>");
	s_gets(st->last, MAX_LITERAL);
}

void count_characters(struct name_count* st)
{
	st->num = strlen(st->first) + strlen(st->last);
	/*for (int i = 0; i < MAX_LITERAL; ++i)
	{
		if (st->first[i] == '\0')
		{
			for (int j = 0; j < MAX_LITERAL; ++j)
			{
				if (st->last[j] == '\0')
				{
					st->num = i + j;
					break;
				}
			}
			break;
		}
	}*/
}

void show_result(const struct name_count* st)
{
	printf("Hi, %s %s. Your name has %d characters.", 
		st->first, st->last, st->num);
}