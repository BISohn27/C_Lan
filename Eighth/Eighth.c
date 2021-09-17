#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book *books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main()
{
	int temp;
	int n = 3;

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

	if (!my_books)
	{
		printf("Malloc failed");
		exit(1);
	}
	
	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, 3);

	printf("\nWriting to a file.\n");
	write_books("books.dat", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	my_books = read_books("books.dat", &n);
	print_books(my_books, 3);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book *books, int n)
{
	for (int i = 0; i < n; ++i){
		printf("Book %d: \"%s\" written by \"%s\"\n", 
			i+1,books[i].name, books[i].author);
	}
}

void write_books(const char* filename, const struct book* books, int n)
{
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Failed");
		exit(1);
	}

	fprintf(fp, "%bd\n", n);
	for (int i = 0; i < n; ++i)
		fprintf(fp, "%bs\n%bs\n", books[i].name, books[i].author);

	fclose(fp);
}

struct book* read_books(const char* filename, int* n) 
{
	
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Failed");
		exit(1);
	}

	fscanf(fp, "%bd%*bc", n);

	struct book* temp = (struct book*)calloc(*n * sizeof(struct book));

	for (int i = 0; i < *n; ++i){
		fscanf(fp, "%b[^\n]%*bc", temp[i].name);
		fscanf(fp, "%b[^\n]%*bc", temp[i].author);
	}

	return temp;
}

void read_books2(const char* filename, struct book** books_dptr, int* n)
{
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Failed");
		exit(1);
	}

	fscanf(fp, "%[^\n]%*c", n);

	struct book* books= (struct book*)malloc(*n*sizeof(struct book));

	for (int i = 0; i < *n; ++i) {
		fscanf(fp, "%[^\n]%*c", books[i].name);
		fscanf(fp, "%[^\n]%*c", books[i].author);
	}
	fclose(fp);

	*books_dptr = books;
}