#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void savePraktikum(praktikum listPraktikum[12][5][4]);
void saveAsisten(char listAsisten[12][5][4][2]);

#endif // FILEHANDLER_H

int getRuangIndex (char *str)
{
    int index;
    if (strcmp("Q", str) == 0 || strcmp("q", str) == 0)
    {
        index = -1;
    }
    else
    {
        index = 0;
        if (strcmp("LAB1", str) == 0) {index = 1;}
        else if (strcmp("LAB2", str) == 0) {index = 2;}
        else if (strcmp("LAB3", str) == 0) {index = 3;}
        else if (strcmp("LSS", str) == 0) {index = 4;}
    }
    return index;
}

int getHariIndex (int prak, int group, char *str)
{
    int index;
    if (strcmp("Q", str) == 0 || strcmp("q", str) == 0)
    {
        index = -1;
    }
    else
    {
        index = 0;
        if (strcmp("Senin", str) == 0) {index = 1;}
        else if (strcmp("Selasa", str) == 0) {index = 2;}
        else if (strcmp("Rabu", str) == 0) {index = 3;}
        else if (strcmp("Kamis", str) == 0) {index = 4;}
        else if (strcmp("Jumat", str) == 0) {index = 5;}
    }
    if (prak == 3 && index != 2 && index != 4)
    {
        index = 0;
    }
    if (index != 3 && group == 7)
    {
        index = 0;
    }
    return index;
}

int getMingguIndex(char *str)
{
    int index;
    if (strcmp("Q", str) == 0 || strcmp("q", str) == 0)
    {
        index = -1;
    }
    else
    {
        index = 0;
        if (atoi(str) > 2 && atoi(str) < 16)
        {
            index = atoi(str) - 2;
        }
    }
    return index;
}

int getGroupIndex(int prak, char *str)
{
    int index;
    if (strcmp("Q", str) == 0 || strcmp("q", str) == 0)
    {
        index = -1;
    }
    else
    {
        index = 0;
        switch(prak)
        {
        case 1:
            if (strcmp("A1", str) == 0) {index = 1;}
            else if (strcmp("A2", str) == 0) {index = 2;}
            else if (strcmp("B1", str) == 0) {index = 3;}
            else if (strcmp("B2", str) == 0) {index = 4;}
            else if (strcmp("C1", str) == 0) {index = 5;}
            else if (strcmp("C2", str) == 0) {index = 6;}
            break;
        case 2:
            if (strcmp("C", str) == 0){index = 7;}
            if (strcmp("A1", str) == 0) {index = 1;}
            else if (strcmp("A2", str) == 0) {index = 2;}
            else if (strcmp("A3", str) == 0) {index = 3;}
            else if (strcmp("B1", str) == 0) {index = 4;}
            else if (strcmp("B2", str) == 0) {index = 5;}
            else if (strcmp("B3", str) == 0) {index = 6;}
            break;
        case 3:
            if (strcmp("A", str) == 0){index = 1;}
            else if (strcmp("B", str) == 0){index = 2;}
            break;

        }
    }
    return index;
}
int getPrakIndex(char *str)
{
    int index;
    index  = 0;
    if (strcmp(str, "Q") == 0 || strcmp(str, "q") == 0)
    {
        index = -1;
    }
    else if (strcmp(str, "EL2205") == 0)
    {
        index = 1;
    }
    else if (strcmp(str, "EL2208") == 0)
    {
        index = 2;
    }
    else if (strcmp(str, "EB2200") == 0)
    {
        index = 3;
    }
    return index;
}