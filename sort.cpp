#include <assert.h>
#include <stdio.h>

#include "Onegin.h"

int cmp_end (const LI l1, const LI l2)
{
    enum cmp {
        less   = -1,
        equal  = 0,
        bigger = 1
    };

    if (l1.lenth != l2.lenth)
    {
        if (l1.lenth > l2.lenth)
            return bigger;
        else 
            return less;
    }

    int curr_char = l1.lenth;
     
    while (l1.text[curr_char] == l2.text[curr_char])
    {
        if (curr_char == 0)
            return equal;

        curr_char--;
    }
    
    if (l1.text[curr_char] > l2.text[curr_char])
        return bigger;

    return less;    
}

int cmp_beg (const LI l1, const LI l2)
{
    int curr_char = 0;
    enum cmp {
        less   = -1,
        equal  = 0,
        bigger = 1
    };
     
    while (l1.text[curr_char] == l2.text[curr_char])
    {
        if (l1.text[curr_char] == '\0')
            return equal;

        curr_char++;
    }
    
    if (l1.text[curr_char] > l2.text[curr_char])
        return bigger;

    return less;    
}

void swap (LI *lines, int i, int j)
{
    LI tmp = lines[i];

    lines[i] = lines[j];
    lines[j] = tmp;
}

int partition (LI *lines, int low, int high, int (*func) (LI l1, LI l2))
{
    LI pivot = lines[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (func(lines[j], pivot) == -1)
        {
            i++;
            swap(lines, i, j);
        }
    }

    swap(lines, i + 1, high);

    return i + 1;
}

void quick_sort (LI *lines, int low, int high, int (*func) (LI l1, LI l2))
{
    if (low < high)
    {
        int pivot = partition(lines, low, high, func);

        quick_sort(lines, low, pivot - 1, func);
        quick_sort(lines, pivot + 1, high, func);
    }
}

void unsort (LI *lines, int number_of_lines)
{
    for (int curr_line = 0; curr_line < number_of_lines; ++curr_line)
    {
        if (lines[curr_line].number != curr_line)
        {
            swap(lines, curr_line, lines[curr_line].number);
        }
    }
}
