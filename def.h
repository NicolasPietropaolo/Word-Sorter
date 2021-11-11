#include <stdio.h>
#include <stdlib.h>

// definitions and prototypes

char **read_words(const char *input_filename, int *nPtr);
void sort_words(char **words, int size);
void sort2_words(char **words, int size);
int compare_str(const char *str1,const char *str2);