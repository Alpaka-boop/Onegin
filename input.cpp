#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "Onegin.h"

const int MAX_LINE = 300;

int read (LI ***lines, int **buffer, int text_size)
{
    int  buf_char = 0;
    int  line_num = 0;
    char curr_line[MAX_LINE] = {};
    int  curr_line_char = 0;
    int  curr_line_num = 0;

    assert(*buffer);
    assert(text_size);

    for (buf_char = 0; buf_char < text_size; ++buf_char)
        if ((*buffer)[buf_char] == '\n')
            line_num++;
    
    if ((*buffer)[buf_char - 1] != '\n')
        line_num++;

    *lines = (LI **) calloc(line_num, sizeof(LI *));

    assert(*lines);

    for (buf_char = 0; buf_char < text_size; ++buf_char, ++curr_line_char)
    {
        curr_line[curr_line_char] = (*buffer)[buf_char];

        if ((*buffer)[buf_char] == '\n' || (*buffer)[buf_char] == '\0' || buf_char == text_size - 1)
        {
            curr_line[curr_line_char] = '\n';

            (*lines)[curr_line_num] = (LI *) calloc(1, sizeof(LI));                            // Выделение памяти под итую структуру 
            (*lines)[curr_line_num]->text = (char *) calloc(curr_line_char + 1, sizeof(char)); // Выделение памяти под строку в итой структуре 

            assert((*lines)[curr_line_num]);
            assert((*lines)[curr_line_num]->text);

            (*lines)[curr_line_num]->number = curr_line_num;
            (*lines)[curr_line_num]->lenth = curr_line_char;
            strncpy((*lines)[curr_line_num]->text, curr_line, curr_line_char + 1);

            curr_line_num++;
            
            for (curr_line_char = 0; curr_line_char < MAX_LINE; ++curr_line_char)
                curr_line[curr_line_char] = 0;

            curr_line_char = -1;
        }
    }

    assert(*lines);

    free(*buffer);

    return line_num;
}
