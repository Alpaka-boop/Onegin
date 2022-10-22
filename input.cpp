#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "Onegin.h"

#define MAX_LINE 300

void mem_handler (char **lines, int *max_number_of_lines, int line_num)
{
    if (line_num == *max_number_of_lines)
    {
        lines = (char **) realloc(lines, *max_number_of_lines * 2);
        *max_number_of_lines *= 2;
    }
    else if (line_num < *max_number_of_lines)
    {
        lines = (char **) realloc(lines, line_num);
    }
}

int read (char **lines, int *buffer, int text_size, int max_number_of_lines)
{
    int  buf_char = 0;
    int  line_num = 0;
    char curr_line[MAX_LINE] = {};
    int  curr_line_char = 0;

    assert(buffer);
    assert(lines);
    assert(text_size);

    for (buf_char = 0; buf_char < text_size; ++buf_char)
    {
        curr_line[curr_line_char] = buffer[buf_char];

        if (buffer[buf_char] == '\n' || buffer[buf_char] == '\0')
        {
            curr_line[curr_line_char] = '\n';

            lines[line_num] = (char *) calloc(curr_line_char, sizeof(char));
            strncpy(lines[line_num], curr_line, curr_line_char);
            line_num++;
            
            for (curr_line_char = 0; curr_line_char < MAX_LINE; ++curr_line_char)
                curr_line[curr_line_char] = 0;

            curr_line_char = 0;

            mem_handler(lines, &max_number_of_lines, line_num);
        }
    }

    mem_handler(lines, &max_number_of_lines, line_num);

    assert(lines);

    free(buffer);

    return line_num;
}

// void read (int **lines, int line_num)
// {
//     int ch       = 0;
//     int i        = 0;
//     int j        = 0;
//     FILE *onegin = fopen(FILE_NAME, "r");

//     assert(onegin);

//     for (ch = getc(onegin), i = 0; i < line_num; ++i)
//     {
//         for (j = 0; ch != EOF && ch != '\n' && ch != '\0' && j < MAX_LINE; ++j)
//         {
//             lines[i][j] = ch;
//             ch = getc(onegin);
//         }

//         lines[i][j] = '\n';
//         ch = getc(onegin);
//     }

//     lines[i - 1][j - 1] = EOF;
//     fclose(onegin);
// }

void print (char **lines, int *number, int line_num)
{
    for (int i = 0; i < line_num; ++i)
    {
        if (number[i] < 10)
            printf("%i.   ", number[i]);
        else if (number[i] < 100)
            printf("%i.  ", number[i]);
        else 
            printf("%i. ", number[i]);

        for (int j = 0; j < MAX_LINE; ++j)
        {
            int ch = lines[i][j];
            
            if (ch == EOF)
                return;

            printf("%c", ch);
        }
    }
    printf("\n=====================================\n");
}

// int lines_counter ()
// {
//     FILE *onegin  = fopen(FILE_NAME, "r");
//     int  ch       = 0;
//     int  line_num = 0;

//     for (ch = fgetc(onegin); ch != EOF; ch = fgetc(onegin))
//         if (ch == '\n')
//             line_num++;
    
//     line_num++;

//     fclose(onegin);

//     return line_num;
// }