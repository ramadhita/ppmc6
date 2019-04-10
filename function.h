//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : 
// Module            : Tugas Besar
// Problem           : header file function
// File Name         : function.h
// Dependency        : stdio.h, stdlib.h, string.h, math.h
//
// Status:
//		1.  Arief Himanto / 13217076
//		2.  Minangkara Ciandi Rengga / 13217087
//		3.  Kevin Sutardi / 13217088
//		4.  Ramadhita Umitaibatin / 18317008
//		5.  Muhammad Harun Al Rasyid / 18317009
// 
//***********************************************************//

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
void assignPraktikum(praktikum listPraktikum[12][5][4]);
int getRuangIndex (char *str);
int getHariIndex (int prak, int group, char *str);
int getMingguIndex(char *str);
int getGroupIndex(int prak, char *str);
int getPrakIndex(char *str);

int getHariIndex2(char* str)

int getIndexAsisten (char str);
int getIndexMinggu (char *str);
int getIndexLab (char *str);
int getIndexHari (char *str);
void AssignAsisten(char listAsisten[12][5][4][2], praktikum listPraktikum[12][5][4]);

int tampilkanSchedule ();
int tampilkanAsisten ();

#endif // FUNCTION_H
