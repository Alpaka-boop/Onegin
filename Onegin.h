#ifndef ONEGIN_H
#define ONEGIN_H

#define MAX_LINE    300
#define FILE_NAME   "Onegin.txt"
#define IS_BIGGER   1
#define IS_SMALLER  0
#define START_FRONT 0
#define START_BACK  1

int  *cpy          (int *dest, const int *src, unsigned long count);
void swap          (int *str1, int *str2);
void swap_num      (int *n1, int *n2);
void read          (int **lines, int line_num);
int  is_bigger     (int *str1, int *str2);
int  is_bigger_end (int *str1, int *str2);
void print         (int **lines, int *number, int line_num, int /* start */, const char* /* data */);
void sort          (int **lines, int *number, int line_num, int start,       const char* /* data */);
void unsort        (int **lines, int *number, int line_num, int /* start */, const char* /* data */);
int  lines_counter ();

#endif 
