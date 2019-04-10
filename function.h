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

int getIndexAsisten (char str);
int getIndexMinggu (char *str);
int getIndexLab (char *str);
int getIndexHari (char *str);
void AssignAsisten(char listAsisten[12][5][4][2], praktikum listPraktikum[12][5][4]);

int tampilkanSchedule ();
int tampilkanAsisten ();

#endif // FUNCTION_H
