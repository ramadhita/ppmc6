//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              : 
// Module            : Tugas Besar
// Problem           : Header file fungsi file handler
// File Name         : filehandler.h
// Dependency        : stdio.h, stdlib.h, unistd.h, "function.h", string.h
//
// Status:
//		1.  Arief Himanto / 13217076
//		2.  Minangkara Ciandi Rengga / 13217087
//		3.  Kevin Sutardi / 13217088
//		4.  Ramadhita Umitaibatin / 18317008
//		5.  Muhammad Harun Al Rasyid / 18317009
// 
//***********************************************************//

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
