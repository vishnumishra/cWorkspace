#include <stdio.h>
int fibo(int numberOfTerms,int **arrayOfFibo);
int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int **result_array);
int filter(int *array, int length, int threshold, int **result_array);
int reverse(int *array, int length, int **result_array);
int slice(int *array,int len_of_array,int start_index, int end_index, int **result_array);
int primeNumber(int start,int end,int **array);
int my_strcmp(char *str1,char *str2);

int forEach(int *array,int length,int (*fun)(int));
int char_forEach(char *array,int length,int (*fun)(char));
int myFilter(int *array, int length, int (*fun)(int), int **result);
int floatFilter(float *array, int length, int (*fun)(float), float **result);
