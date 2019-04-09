#include <stdio.h>

int tampilkanAsisten (){
	int i, j, k, l;
	printf ("\n\n\t|--------------------|----------|----------|----------|----------|\n");
	printf ("\t|   Ruang Praktikum   |   Lab 1  |   Lab 2  |   Lab 3  |    LSS   |\n");
	printf ("\t|---------------------|----------|----------|----------|----------|\n");
	printf ("\t|  Minggu  |   Hari   |----------|----------|----------|----------|\n");
	printf ("\t|----------|----------|----------|----------|----------|----------|\n");
	for (i=0 ; i<12 ; i++)
		{
			for (j=0 ; j<5 ; j++)
			{
				printf ("\t|\t%d\t|", [i+3]);
				printf ("\t%s\t|", getHari(j));
				for (k=1 ; k=4 ; k++)
				{
					for (l=1 ; l=14 ; l++)
					{
						printf ("\t%s\t|", listAsisten[i][j][k][l]);
					}
				}
				printf ("\n");
			}
			printf ("\t|-----------------------------------------------------------------|\n");
		}
	}
