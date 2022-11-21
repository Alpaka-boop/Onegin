#include <stdlib.h>
#include <locale.h>
#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

#include "Onegin.h"

#define INPUT_FILE "Onegin.txt"

void print (LI *lines, int num_of_lines)
{
    assert(lines);

    printf("=============================\n");
    
    for (int i = 0; i < num_of_lines; i++)
    {
        printf("%s", lines[i].text);
    }

    printf("=============================\n");
}

void free_lines(LI **lines, int number_of_lines)
{
    for (int i = 0; i < number_of_lines; ++i)
    {
        free((*lines)[i].text);
    }

    free(*lines);
}

int main ()
{
    setlocale(LC_ALL, "Rus");

    LI *lines = NULL; 

    struct stat st = {};
    FILE *onegin = fopen(INPUT_FILE, "r");

    if (!onegin)
    {
        printf("No such file %s\n", INPUT_FILE);
        printf("Please, change the file name in main.cpp line -- 9\n");

        return 1;
    }

    stat(INPUT_FILE, &st);

    int number_of_characters = st.st_size / sizeof(char);
    int *buffer  = (int *) calloc(number_of_characters + 1, sizeof(int));
    int i = 0;

    while ((buffer[i++] = fgetc(onegin)) != EOF) {;}

    int number_of_lines = read(&lines, &buffer, number_of_characters);

    print(lines, number_of_lines);
    quick_sort(lines, 0, number_of_lines - 1, cmp_beg);
    print(lines, number_of_lines);
    quick_sort(lines, 0, number_of_lines - 1, cmp_end);
    print(lines, number_of_lines);
    unsort(lines, number_of_lines);
    print(lines, number_of_lines);

    free_lines(&lines, number_of_lines);

    fclose(onegin);

    return 0;
}
