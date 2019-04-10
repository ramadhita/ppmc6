#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "function.h"

void buatProyek();
void loadPraktikum(praktikum listPraktikum[12][5][4]);
void loadAsisten(char list[12][5][4][2]);
void ruleCheck();
void savePraktikum(praktikum listPraktikum[12][5][4]);
void saveAsisten(char listAsisten[12][5][4][2]);

#endif // FILEHANDLER_H
