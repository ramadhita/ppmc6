#ifndef FUNCTION_H
#define FUNCTION_H
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Praktikum
{
    int matkul;
    int group;
} praktikum;

char* getGroup(int matkul, int index);
char* getAsisten(char as[2]);
char* getMatkul(int index);
char* getHari(int index);

#endif // FUNCTION_H
