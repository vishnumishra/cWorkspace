#include <stdio.h>
int fibo(int,int **);
int concat(int*,int,int*,int,int**);
int filter(int*,int,int,int**);
int reverse(int*, int, int**);
int slice(int*,int,int, int, int**);
int primeNumber(int,int ,int**);
int my_strcmp(char*,char*);

int forEach(int *,int,int(*fun)(int));
int char_forEach(char *,int,int (*fun)(char));
int myFilter(int *,int,int (*fun)(int), int **);
