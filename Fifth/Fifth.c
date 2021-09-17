#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float price;
};


int main()
{
    struct book library[MAXBKS];
    
    int count = 0;
    int index, filecount;
    FILE* pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        printf("Can't open book.dat.\n");
        exit(1);
    }

    rewind(pbooks);

    while (count < MAXBKS && fread(&library[count], sizeof(struct book), 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].price);
        count++;
    }

    filecount = count;

    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.\n",stderr);
        exit(2);
    }

    puts("Please add new book titles.\n");
    puts("Press [enter] at the start of a line to stop.\n");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the price.");
        scanf("%f", &library[count++].price);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    if (count > 0)
    {
        puts("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: %.2f\n", library[index].title, library[index].author, library[index].price);

        fwrite(&library[filecount], size, count - filecount, pbooks);
    }

    else
        put("No books? Too bad.\n");

    fclose(pbooks);

	return 0;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}