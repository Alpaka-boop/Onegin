#include <stdio.h>
#include <assert.h>

#include "Onegin.h"

void read (int **lines, int line_num)
{
    int ch       = 0;
    int i        = 0;
    int j        = 0;
    FILE *onegin = fopen(FILE_NAME, "r");

    assert(onegin);

    for (ch = getc(onegin), i = 0; i < line_num; ++i)
    {
        for (j = 0; ch != EOF && ch != '\n' && ch != '\0' && j < MAX_LINE; ++j)
        {
            lines[i][j] = ch;
            ch = getc(onegin);
        }

        lines[i][j] = '\n';
        ch = getc(onegin);
    }

    lines[i - 1][j - 1] = EOF;
    fclose(onegin);
}

void print (int **lines, int *number, int line_num, int /* start */, const char* /* data */)
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

int lines_counter ()
{
    FILE *onegin  = fopen(FILE_NAME, "r");
    int  ch       = 0;
    int  line_num = 0;

    for (ch = fgetc(onegin); ch != EOF; ch = fgetc(onegin))
        if (ch == '\n')
            line_num++;
    
    line_num++;

    fclose(onegin);

    return line_num;
}