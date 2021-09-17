#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct movie
{
	char movie_name[40];
	float movie_evaluation;
};

void get_name(char arr[]);
void open_file(FILE** ptf,char* name,int* num);
void cpyMovie(FILE* ptf,struct movie* arr, int num);
void selectMenu(struct movie* arr, int num);
void printMenu(void);
void printItem(const struct movie* arr,int num);
void printanItem(const struct movie* arr, int num);
void editanItem(struct movie* arr);
void addanItem(struct movie* arr, int* num);
void insertanItem(struct movie* arr, int* num);
void deleteanItem(struct movie* arr, int* num);
void save(struct movie* arr, int* num);
void deleteallItem(struct movie* arr, int* num);
void searchName(struct movie* arr, int* num);

int main()
{
	char          file_name[20];
	int			  num = 0;
	FILE*		  ptf;
	struct movie  movies[15] = { 0, };

	get_name(file_name);
	
	open_file(&ptf, file_name, &num);

	cpyMovie(ptf, movies, num);
	
	fclose(ptf);

	selectMenu(movies, num);

	puts("Good bye.");

	return 0;
}

void cpyMovie(FILE* ptf,struct movie* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		fscanf(ptf, "%[^\n]%*c", (arr+i)->movie_name);
		fscanf(ptf, "%f%*c", &(arr + i)->movie_evaluation);

	/*	while (fgetc(ptf) == '\n')
			break;*/
	}
}

void open_file(FILE** ptf, char* name, int* num)
{
	if ((*ptf = fopen(name, "r")) == NULL)
	{
		printf("\nCan't open the file.");
		exit(2);
	}

	fscanf(*ptf, "%d%*c", num);

	/*while (fgetc(*ptf) != '\n')
		continue;*/

	printf("%d itmes have been read from the file.\n\n", *num);
}

void get_name(char arr[])
{
	puts("Please input a file name.");

	while (scanf("%[^\n]%*c", arr) == 0)
	{
		puts("Please input a file name again");
		while (getchar() != '\n')
			continue;
	}
}

void selectMenu(struct movie* arr, int num)
{
	int number = 0;
	bool flag = false;

	printMenu();

	while ((scanf("%d", &number) != 0) || (number == 'q'))
	{
		while (getchar() != '\n')
			continue;

		switch (number)
		{
		case 1:
			printItem(arr, num);
			break;
		case 2:
			printanItem(arr, num);
			break;
		case 3:
			editanItem(arr);
			break;
		case 4:
			addanItem(arr, &num);
			break;
		case 5:
			insertanItem(arr, &num);
			break;
		case 6:
			deleteanItem(arr, &num);
			break;
		case 7:
			deleteallItem(arr, &num);
			break;
		case 8:
			save(arr, &num);
		case 9:
			searchName(arr, &num);
			break;
		case 10:
			flag = true;
		}

		if (flag == true)
			break;
		printMenu();
	}
}

void printMenu(void)
{
	puts("Please select an option and press enter. (q to quit)\n\
1. Print all items\t2. Print an item\n\
3. Edit an item         4. Add an item\n\
5. Insert an item\t6. Delete an item\n\
7. Delete all items\t8. Save file\n\
9. Search by name\t10. Quit\n>>");
}

void printItem(const struct movie* arr,int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d : \"%s\"", i,arr[i].movie_name);
		printf("      %.1f\n\n", arr[i].movie_evaluation);
	}
}

void printanItem(const struct movie* arr, int num)
{
	int index;
	printf("\nInput a index. (0 ~ %d)\n>>", num-1);

	scanf("%d", &index);

	while ( (index < 0) || (index >num-1) )
	{
		printf("Input 0 ~ %d number.\n>>", num-1);
		while (getchar() != '\n')
			continue;
	}

	printf("%d : \"%s\"\n", index, arr[index].movie_name);
	printf("     %.1f\n\n", arr[index].movie_evaluation);
}

void editanItem(struct movie* arr)
{
	int index = 0;

	puts("Input the index that you want to edit.\n>>");

	scanf("%d", &index);

	while (getchar() != '\n')
		continue;

	puts("Input the name of the movie you want to enter.\n>>");
	scanf("%[^\n]%*c", arr[index].movie_name);
	puts("Input the evaluation of the movie you entered.\n>>");
	scanf("%f", &arr[index].movie_evaluation);

	while (getchar() != '\n')
		continue;
}

void addanItem(struct movie* arr, int* num)
{
	puts("Input the name of the movie you want to enter.\n>>");
	scanf("%[^\n]%*c", arr[*num].movie_name);
	puts("Input the evaluation of the movie you entered.\n>>");
	scanf("%f", &arr[*num].movie_evaluation);

	while (getchar() != '\n')
		continue;

	*num = *num + 1;
}

void insertanItem(struct movie* arr, int* num)
{
	int index = 0;
	puts("Input the index you want to insert.\n>>");
	scanf("%d", &index);

	while (getchar() != '\n')
		continue;

	for (int i = *num; i > index; i--)
	{
		strcpy(arr[i].movie_name, arr[i - 1].movie_name);
		arr[i].movie_evaluation = arr[i - 1].movie_evaluation;
	}

	puts("Input the name of the movie you want to enter.\n>>");
	scanf("%[^\n]%*c", arr[index].movie_name);
	puts("Input the evaluation of the movie you entered.\n>>");
	scanf("%f", &arr[index].movie_evaluation);

	while (getchar() != '\n')
		continue;

	*num = *num + 1;
}

void deleteanItem(struct movie* arr, int* num)
{
	int index = 0;
	puts("Input the index you want to delete.\n>>");
	scanf("%d", &index);

	while (getchar() != '\n')
		continue;

	for (int i = index; i < (*num-1); i++)
	{
		strcpy(arr[i].movie_name, arr[i + 1].movie_name);
		arr[i].movie_evaluation = arr[i + 1].movie_evaluation;
	}

	*num = *num - 1;
}

void deleteallItem(struct movie* arr, int* num)
{
	for (int i = 0; i < *num; i++)
	{
		strcpy(arr[i].movie_name, "\0");
		arr[i].movie_evaluation = 0.0f;
	}

	*num = 0;
}

void save(struct movie* arr, int* num)
{
	char file_name[40];

	scanf("%[^\n]%*c", file_name);

	FILE* ptf = fopen(file_name, "w+");

	fprintf(ptf, "%d\n", *num);

	for (int i = 0; i < *num; i++)
	{
		fprintf(ptf, "%s\n", arr[i].movie_name);
		fprintf(ptf, "%.1f\n", arr[i].movie_evaluation);
	}

	fclose(ptf);
}

void searchName(struct movie* arr, int* num)
{
	char name[40];
	bool flag = false;
	puts("Input the name you want to search.");
	scanf("%[^\n]%*c", name);

	for (int i = 0; i < *num; ++i)
	{
		if (strcmp(name, arr[i].movie_name) == 0)
		{
			printf("%d : %s\n", i, arr[i].movie_name);
			printf("     %.1f\n\n", arr[i].movie_evaluation);
			flag = true;
			break;
		}
	}

	if (flag == false)
		puts("I can't find the movie.\n");
}