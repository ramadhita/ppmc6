#include "filehandler.h"


void savePraktikum(praktikum listPraktikum[12][5][4])
{
    FILE *filePointer;
    int i, j, k;
    filePointer = fopen("Jadwal_Praktikum_Semester_2_rombongan.csv", "w");
    fputs("Ruang Praktikum|LAB1|LAB2|LAB3|LSS\n", filePointer);
    fputs("Minggu|Hari\n", filePointer);
    for(i=0; i < 12; i++)
    {
        for (j=0; j < 5; j++)
        {
            fprintf(filePointer, "%d|%s|", i + 3, getHari(j));
            for (k=0; k < 4; k++)
            {
                fprintf(filePointer, "%s%s|", getMatkul(listPraktikum[i][j][k].matkul), getGroup(listPraktikum[i][j][k].matkul, listPraktikum[i][j][k].group));
            }
            fputs("\n", filePointer);
        }
    }
    fclose(filePointer);
}

void saveAsisten(char listAsisten[12][5][4][2])
{
    FILE *filePointer;
    int i, j, k;
    filePointer = fopen("Jadwal_Praktikum_Semester_2_asisten.csv", "w");
    fputs("Ruang Praktikum|LAB1|LAB2|LAB3|LSS\n", filePointer);
    fputs("Minggu|Hari\n", filePointer);
    for(i=0; i < 12; i++)
    {
        for (j=0; j < 5; j++)
        {
            fprintf(filePointer, "%d|%s|", i + 3, getHari(j));
            for (k=0; k < 4; k++)
            {
                fprintf(filePointer, "%s|", getAsisten(listAsisten[i][j][k]));
            }
            fputs("\n", filePointer);
        }

    }
    fclose(filePointer);
}
