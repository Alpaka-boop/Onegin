#ifndef ONEGIN_H
#define ONEGIN_H

typedef struct LINE_INFO {
    int  number;
    char *text;
    int  lenth;
} LI;

int  read       (LI ***lines, int **buffer, int text_size);
void print      (LI **lines, int num_of_lines);

void quick_sort (LI **lines, int low, int high, int (*fun) (LI* l1, LI* l2));
void unsort     (LI **lines, int number_of_lines);
int  partition  (LI **lines, int low, int high, int (*fun) (LI* l1, LI* l2));
void swap       (LI **lines, int i, int j, int (*fun) (LI* l1, LI* l2));
int  cmp_beg    (LI *l1, LI *l2);
int  cmp_end    (LI *l1, LI *l2);

#endif 
