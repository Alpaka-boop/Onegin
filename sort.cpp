#include <assert.h>
#include <stdio.h>

#include "Onegin.h"

int *cpy( int *dest, const int *src, unsigned long count )
{
    assert(dest);
    assert(src);

    unsigned long num_ch = 0;

    while (num_ch < count && (dest[num_ch] = src[num_ch]))
        num_ch++;

    if (!src[num_ch] && count == num_ch)
        return dest;

    while (num_ch < count)
        dest[num_ch++] = '\0';

    return dest;
}

void swap (int *str1, int *str2)
{
    assert(str1);
    assert(str2);

    int tmp[MAX_LINE] = {};

    cpy(tmp, str1, MAX_LINE);
    cpy(str1, str2, MAX_LINE);
    cpy(str2, tmp, MAX_LINE);
}

void swap_num (int *n1, int *n2)
{
    int tmp = 0; 

    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp; 
}

int is_bigger (int *str1, int *str2)
{
    int i = 0; 

    while (i < MAX_LINE)
    {
        if (str1[i] != str2[i])
            return str1[i] > str2[i];

        i++;
    }
    
    return IS_BIGGER;
}

int is_bigger_end (int *str1, int *str2)
{
    int i = MAX_LINE - 1;
    int j = MAX_LINE - 1;

    while (str1[i] == 0) 
        i--;

    while (str2[j] == 0) 
        j--;

    while (j >= 0 && i >= 0)
    {
        if (str1[i] != str2[j])
            return str1[i] > str2[j];

        i--;
        j--;
    }

    if (i > 0)
        return IS_BIGGER;

    if (j > 0)
        return IS_SMALLER;
    
    return IS_BIGGER;
}

void sort (int **lines, int *number, int line_num, int start, const char* /* data */)
{

    int (*fun[])(int *, int *) = {&is_bigger, &is_bigger_end};

    for (int i = 0; i < line_num; ++i)
        for (int j = i + 1; j < line_num - 1; ++j)
            if (lines[j][0] != EOF && fun[start](lines[i], lines[j]))
            {
                swap(lines[i], lines[j]);
                swap_num(&(number[i]), &(number[j]));
            }
}

void unsort (int **lines, int *number, int line_num, int /* start */, const char* /* data */)
{
    for (int i = 0; i < line_num; ++i)
        for (int j = i + 1; j < line_num - 1; ++j)
            if (number[j] == i)
            {
                swap(lines[i], lines[j]);
                swap_num(&(number[i]), &(number[j]));
            }
}
