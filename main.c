#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "filehandler.h"

int main()
{
    //int i, j, k;
    praktikum list[12][5][4];
    //char last[12][5][4][2];
    //list[0][0][0].matkul = 2;
    //list[0][0][0].group = 5;
    //last[0][0][0][0] = 'A';
    //last[0][0][0][1] = 'B';
    //for (i=0; i< 12; i++)
    //{
        //for (j=0; j < 5; j++)
        //{
            //for (k=0; k< 4; k++)
            //{
                //list[i][j][k].matkul = 0;
               // list[i][j][k].group = 0;
            //}
        //}
    //}
    assignPraktikum(list);
//    saveAsisten(last);
    savePraktikum(list);
}


