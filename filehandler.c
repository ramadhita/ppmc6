#include "filehandler.h"

void loadPraktikum(praktikum listPraktikum[12][5][4])
{
    FILE *filePointer;
    int  m, o, l, i, j, k, line, minggu, hari, prak, grup, co;
    char c;
    char gn[10], gi[10], t;
    char str[512], *tok;
    //hapusHeader(); //hapus bagian 2 line awal (header)

    //validasi file eksternal
    if(access("Jadwal_Praktikum_Semester_2_rombongan.csv", F_OK ) != -1)
    {
        filePointer = fopen("Jadwal_Praktikum_Semester_2_rombongan.csv", "r");
        i = 0;
        j = 0;
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
                        //printf("%s-%d|", tok, j);
                        switch(j)
                        {
                            case 0:
                                minggu = getMingguIndex(tok);
                                //printf("Minggu %d - ", minggu);
                            break;
                            case 1:
                                hari = getHariIndex(1, 1, tok);
                                //printf("%d - % d | ", minggu, hari);
                                for (k = 0; k < 4; k++)
                                {
                                    listPraktikum[minggu][hari - 1][k].matkul = 0;
                                    listPraktikum[minggu][hari - 1][k].group = 0;
                                }

                            break;
                            default:

                                //{
                                //char *temp;
                                //strcpy(temp, tok);
                                co = strcmp(tok, " ");
                                if (co != 0)
                                {
                                    l = 0;
                                    o = 0;
                                    m = 0;
                                    strcpy(gn, "");
                                    strcpy(gi, "");
                                    while((t = tok[l])!= '\0')
                                    {
                                        //printf("%c", t);
                                        if (t == '-')
                                        {
                                            m = l;
                                            //gn[m + 1] = '\0';

                                            o = 1;
                                        }
                                        else
                                        {
                                            if (o == 0)
                                            {
                                                gn[l] = t;
                                            }
                                            else
                                            {
                                                gi[l-m - 1] = t;
                                            }
                                        }

                                        l += 1;

                                    }
                                    gi[l-m-1] = '\0';
                                    //gi[l] = '\0';
                                    //printf("%s-%s", gn, gi);
                                    gn[m] = '\0';
                                    prak = getPrakIndex(gn);
                                    grup = getGroupIndex(prak, gi);
                                    //printf("%d - %d : ", prak, grup);
                                    //grup = getGroupIndex(prak, gi);
                                    listPraktikum[minggu][hari - 1][j-2].matkul = prak;
                                    listPraktikum[minggu][hari - 1][j-2].group = grup;

                                }
                                //printf("", prak);
                                //}
                            break;
                        }
                        j += 1;
                        tok = strtok(NULL, "|");

                    }
                    //printf("\n");
                }
                i = 0;
                //printf("\n");
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
            fprintf(filePointer, "%d|%s|", i + 3, getHari(j+1));
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
