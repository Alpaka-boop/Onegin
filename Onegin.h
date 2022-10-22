#ifndef ONEGIN_H
#define ONEGIN_H

int  *cpy          (int *dest, const int *src, unsigned long count);
void swap          (char *str1, char *str2);
void swap_num      (int *n1, int *n2);
int  read          (char **lines, int *buffer, int text_size, int max_number_of_lines);
void mem_handler   (char **lines, int *max_number_of_lines, int line_num);
int  str_cmp       (const char *str1, const char *str2);
int  is_bigger_end (const char *str1, const char *str2);
void print         (char **lines, int *number, int line_num);
void sort          (char **lines, int *number, int line_num, int start);
void unsort        (char **lines, int *number, int line_num);
int  lines_counter ();


typedef struct LINE_INFO{
    char *text;
    int  lenth;
}LI;

#endif 
