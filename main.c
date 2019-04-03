#include <stdio.h>
#include "function.h"
#include "filehandler.h"

int main()
{
	praktikum list[12][5][4];
    	char last[12][5][4][2];
    	list[0][0][0].matkul = 2;
    	list[0][0][0].group = 5;
    	last[0][0][0][0] = 'A';
    	last[0][0][0][1] = 'B';
    	saveAsisten(last);
    	savePraktikum(list);
	return 0;
}
