#include "filehandler.h"

void loadPraktikum(praktikum listPraktikum[12][5][4])
{
    FILE *filePointer;
    int  i, j, k, line, minggu, hari, prak, grup;
    char c;
    char *gn, *gi;
    char str[512], *tok;
    //hapusHeader(); //hapus bagian 2 line awal (header)

    //validasi file eksternal
    if(access("Jadwal_Praktikum_Semester_2_rombongan.csv", F_OK ) != -1)
    {
        filePointer = fopen("Jadwal_Praktikum_Semester_2_rombongan.csv", "r");
        i = 0;
        j = 0;
        k = 0;
        line = 0;
        //strcpy(str, "");
        while ((c = fgetc(filePointer)) != EOF)
        {
            //printf("%c", c);
            if (c == '\n')
            {

                str[i] = '\0';
                //printf(" Line: %s\n", str);
                line += 1;
                if (line > 2)
                {
                    j = 0; // Token delimiter count
                    tok = strtok(str, "|");
                    while(tok != NULL)
                    {
                        //printf("Token %d : %s",k, tok);

                        switch(j)
                        {
                            case 0:
                                minggu = getMingguIndex(tok);
                                //printf("Minggu %d - ", minggu);
                            break;
                            case 1:
                                hari = getHariIndex(1, 1, tok);
                                //printf("%d - ", hari);
                                for (k = 0; k < 4; k++)
                                {
                                    listPraktikum[minggu][hari][k].matkul = 0;
                                    listPraktikum[minggu][hari][k].group = 0;
                                }

                            break;
                            default:
                                gn = strtok(tok, "-");
                                prak = getPrakIndex(gn);
                                //printf("%s-", gn);
                                gn = strtok(NULL, "-");
                                grup = getGroupIndex(prak, gn);
                                listPraktikum[minggu][hari][j-2].matkul = prak;
                                listPraktikum[minggu][hari][j-2].group = grup;
                                //printf("%s", gn);
                            break;
                        }
                        j += 1;
                        tok = strtok(NULL, "|");

                    }
                    //printf("\n");
                }
                i = 0;
                //printf("Line %d\n", i);
            }
            else
            {
                str[i] = c;
                i += 1;
                //printf("%c", c);

            }
        }
        //printf("File tidak tersedia.");
        fclose(filePointer);

    }
    else
    {
       printf("File does not exist.");
    }

}
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
