#include <stdlib.h>
#include <locale.h>

#include "Onegin.h"

int main ()
{
    setlocale(LC_ALL, "Rus");

    int line_num = lines_counter();
    int **lines  = (int **) calloc(line_num, sizeof(int *));
    int *number  = (int *)  calloc(line_num, sizeof(int));

    for (int i = 0; i < line_num; ++i) 
    {
        lines[i] = (int *) calloc(MAX_LINE, sizeof(int));
        number[i] = i;
    }

    read(lines, line_num);

    sort(lines, number, line_num, START_FRONT, NULL);
    print(lines, number, line_num, NULL, NULL);

    sort(lines, number, line_num, START_BACK, NULL);
    print(lines, number, line_num, NULL, NULL);

    unsort(lines, number, line_num, NULL, NULL);
    print(lines, number, line_num, NULL, NULL);

    for (int i = 0; i < line_num; ++i)
        free(lines[i]);
    free(lines);

    return 0;
}
