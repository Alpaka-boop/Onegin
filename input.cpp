#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "Onegin.h"

#define MAX_LINE 300

void mem_handler (LI ***lines, int max_number_of_lines, int line_num)
{
    if (line_num == max_number_of_lines)
    {
        lines = (LI ***) realloc(lines, max_number_of_lines * 2);
        max_number_of_lines *= 2;
    }
    else if (line_num < max_number_of_lines)
    {
        lines = (LI ***) realloc(lines, line_num);
    }
}

int read (LI ***lines, int **buffer, int text_size, int max_number_of_lines)
{
    int  buf_char = 0;
    int  line_num = 0;
    char curr_line[MAX_LINE] = {};
    int  curr_line_char = 0;

    assert(*buffer);
    assert(*lines);
    assert(text_size);

    for (buf_char = 0; buf_char < text_size; ++buf_char, ++curr_line_char)
    {
        curr_line[curr_line_char] = (*buffer)[buf_char];

        if ((*buffer)[buf_char] == '\n' || (*buffer)[buf_char] == '\0')
        {
            curr_line[curr_line_char] = '\n';

            printf("%s\n", curr_line);

            (**lines)[line_num]       = (LI *)   calloc(curr_line_char,     sizeof(LI));
            (**lines)[line_num]->text = (char *) calloc(curr_line_char + 1, sizeof(char));

            assert((*lines)[line_num]);
            assert(((*lines)[line_num]->text))

            (*lines)[line_num]->number = line_num;
            (*lines)[line_num]->lenth = curr_line_char;
            printf("lenth: %i\n", (*lines)[line_num]->lenth);
            strncpy((*lines)[line_num]->text, curr_line, curr_line_char);
            printf("%s\n", (*lines[line_num])->text);

            line_num++;
            
            for (curr_line_char = 0; curr_line_char < MAX_LINE; ++curr_line_char)
                curr_line[curr_line_char] = 0;

            curr_line_char = -1;

            mem_handler(lines, max_number_of_lines, line_num);
        }
    }

    mem_handler(lines, max_number_of_lines, line_num);

    assert((*lines));

    free(*buffer);

    return line_num;
}

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
