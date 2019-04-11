//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              :
// Module            : Tugas Besar
// Problem           : function file handler
// File Name         : filehandler.c
// Dependency        : "filehandler.h"
//
// Status:
//		1.  Arief Himanto / 13217076
//		2.  Minangkara Ciandi Rengga / 13217087
//		3.  Kevin Sutardi / 13217088
//		4.  Ramadhita Umitaibatin / 18317008
//		5.  Muhammad Harun Al Rasyid / 18317009
//
//***********************************************************//

#include "filehandler.h"

void newProject(char listAsisten[12][5][4][2], praktikum listPraktikum[12][5][4])
{
	int i,j,k,l;
	FILE *fP2, *fP1;
	fP1 = fopen("Jadwal_Praktikum_Semester_2_asisten.csv","w");
	fP2 = fopen("Jadwal_Praktikum_Semester_2_rombongan.csv","w");
	fclose(fP1);
	fclose(fP2);
	for (i = 0; i < 12; ++i)
    {
       for (j = 0; j < 5; ++j)
       {
           for (k = 0; k < 4; ++k)
            {
                listPraktikum[i][j][k].matkul = 0;
                listPraktikum[i][j][k].group = 0;
                for (l = 0; l < 2; ++l)
                {
                    listAsisten[i][j][k][l]='\0';
                }
            }
       }

    }
}

void loadPraktikum(praktikum listPraktikum[12][5][4])
{
    FILE *filePointer;
    int  m, o, l, i, j, k, line, minggu, hari, prak, grup, co;
    char c;
    char gn[10], gi[10], t;
    char str[512], *tok;
    if(access("Jadwal_Praktikum_Semester_2_rombongan.csv", F_OK ) != -1)
    {
        filePointer = fopen("Jadwal_Praktikum_Semester_2_rombongan.csv", "r");
        i = 0;
        j = 0;
        line = 0;
        while ((c = fgetc(filePointer)) != EOF)
        {
            if (c == '\n')
            {

                str[i] = '\0';
                line += 1;
                if (line > 2)
                {
                    j = 0;
                    tok = strtok(str, "|");
                    while(tok != NULL)
                    {
                        switch(j)
                        {
                            case 0:
                                minggu = getMingguIndex(tok);
                            break;
                            case 1:
                                hari = getHariIndex(1, 1, tok);
                                for (k = 0; k < 4; k++)
                                {
                                    listPraktikum[minggu][hari - 1][k].matkul = 0;
                                    listPraktikum[minggu][hari - 1][k].group = 0;
                                }

                            break;
                            default:
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
                                        if (t == '-')
                                        {
                                            m = l;
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
                                    gn[m] = '\0';
                                    prak = getPrakIndex(gn);
                                    grup = getGroupIndex(prak, gi);
                                    listPraktikum[minggu][hari - 1][j-2].matkul = prak;
                                    listPraktikum[minggu][hari - 1][j-2].group = grup;

                                }
                            break;
                        }
                        j += 1;
                        tok = strtok(NULL, "|");

                    }
                }
                i = 0;
            }
            else
            {
                str[i] = c;
                i += 1;

            }
        }
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


// HARAP DIBACA, fungsi loadAsisten masih banyak BUG. DITARO DISINI SUPAYA DISATUIN DULUAN
void loadAsisten(char listAsisten[12][5][4][2])
{
    char c, str[100], *tok;
    FILE *filePointer;
    int i,j,k,l, co, line, minggu, hari;
    for (i = 0; i < 12; ++i)
    {
       for (j = 0; j < 5; ++j)
       {
           for (k = 0; k < 4; ++k)
            {
                for (l = 0; l < 2; ++l)
                {
                    listAsisten[i][j][k][l]='\0';
                }
            }
       }

    }


    if(access("Jadwal_Praktikum_Semester_2_asisten.csv", F_OK ) != -1)
    {
        filePointer = fopen("Jadwal_Praktikum_Semester_2_asisten.csv", "r");
        i = 0;
        line = 0;
        while ((c = fgetc(filePointer)) != EOF)
        {
            if (c == '\n')
            {
                str[i] = '\0';
                line += 1;
                if (line > 2)
                {
                    j = 0;
                    tok = strtok(str, "|");
                    while(tok != NULL)
                    {
                        switch(j)
                        {
                            case 0:
                                minggu = getMingguIndex(tok);
                            break;
                            case 1:
                                hari = getHariIndex(1, 1, tok);
                            break;
                            default:
                                co = strcmp(tok, " ");
                                if (co != 0)
                                {
                                    if (tok[0] != ' ')
                                    {
                                        listAsisten[minggu][hari - 1][hari - 1][0] = tok[0];
                                    }
                                    if (tok[2] != ' ')
                                    {
                                        listAsisten[minggu][hari - 1][hari - 1][1] = tok[2];
                                    }
                                }
                            break;
                        }
                        j += 1;
                        tok = strtok(NULL, "|");

                    }
                }
                i = 0;
            }
            else
            {
                str[i] = c;
                i += 1;
            }
        }
        fclose(filePointer);
    }
    else
    {
       printf("File does not exist.");
    }

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
            fprintf(filePointer, "%d|%s|", i + 3, getHari(j + 1));
            for (k=0; k < 4; k++)
            {
                fprintf(filePointer, "%s|", getAsisten(listAsisten[i][j][k]));
            }
            fputs("\n", filePointer);
        }

    }
    fclose(filePointer);
}


void loadAsistenFile(asisten listData[14])
{
    FILE *filePointer;
    int i, j, k, count, line, l, m, o, co;
    char c, str[512], *tok, t, gn[10], gi[10];
    k = 0;
    count = 0;
    line = 0;
    for (i = 0; i< 14; i++)
    {
        strcpy(listData[i].nama, "");
        for (j = 0; j < 3; j++)
        {
            listData[i].prak[j] = 0;
        }
        for (j = 0; j < 5; j++)
        {
            listData[i].hari[j] = 0;
        }
    }
    if(access("Asisten.csv", F_OK ) != -1)
    {
        filePointer = fopen("Asisten.csv", "r");
        while ((c = fgetc(filePointer)) != EOF)
        {
            if (c == '\n')
            {
                str[k] = '\0';
                tok = strtok(str, "|");
                while(tok != NULL)
                {
                    switch(count)
                    {
                        case 0:
                            strcpy(listData[line].nama, tok);
                        break;
                        case 1:
                            l = 0;
                            o = 0;
                            m = 0;
                            strcpy(gn, "");
                                while((t = tok[l])!= '\0')
                                {
                                    if (t == ',')
                                    {

                                        if (m != l && o > 0)
                                        {
                                            gn[l - m - 1] = '\0';

                                        }
                                        else
                                        {
                                            gn[l] = '\0';
                                        }
                                        m = l;
                                        listData[line].prak[getPrakIndex(gn)-1] = 1;
                                        strcpy(gn, "");
                                        o += 1;
                                    }
                                    else
                                    {
                                        if (o == 0)
                                        {
                                            gn[l] = t;
                                        }
                                        else
                                        {
                                            gn[l-m-1] = t;
                                        }

                                    }

                                    l += 1;
                                }
                        break;
                        case 2:
                            co = strcmp(tok, " ");
                            if (co != 0)
                            {
                                l = 0;
                                o = 0;
                                m = 0;
                                strcpy(gi, "");
                                while((t = tok[l])!= '\0')
                                {
                                    if (t == ',')
                                    {

                                        if (m != l && o > 0)
                                        {
                                            gi[l - m - 1] = '\0';
                                        }
                                        else
                                        {
                                            gi[l] = '\0';
                                        }
                                        m = l;
                                        listData[line].hari[getHariIndex(1,1, gi)-1] = 1;
                                        strcpy(gi, "");
                                        o += 1;
                                    }
                                    else
                                    {
                                        if (o == 0)
                                        {
                                            gi[l] = t;
                                        }
                                        else
                                        {
                                            gi[l-m-1] = t;
                                        }

                                    }

                                    l += 1;
                                }
                            }
                        break;
                    }
                    count += 1;
                    tok = strtok(NULL, "|");
                }
                k = 0;
                line += 1;
                count = 0;
            }
            else
            {
                str[k] = c;
                k += 1;
            }
        }
    }
    else
    {
        printf("File not found");
    }
}

void ruleCheck(praktikum listPraktikum[12][5][4])
{
    int count = 0;
    int fail = 0;
    int i, j, m, h;
    char text[100], *temp;
    char c, str[12];
    FILE* filePointer;
    i = 0;
    printf("[DRC]\n");
	printf("Masukkan File DRC (dalam format .txt): ");
	scanf("%s", &text);
	getchar();

	if(access(text, F_OK ) != -1)
    {
        filePointer = fopen(text, "r");
        while ((c = fgetc(filePointer)) != EOF)
        {
            if (c == '\n')
            {
                str[i] = '\0';
                temp = strtok(str, " ");
                m = getMingguIndex(temp);
                temp = strtok(NULL, " ");
                h = getHariIndex(1, 1, temp);

                for(j=0; j<4; j++)
                {
                    if (listPraktikum[m][h-1][j].matkul != 0)
                    {
                        //listPraktikum[m][h-1][j].matkul = 0;
                        //listPraktikum[m][h-1][j].group = 0;
                        fail += 1;
                        break;
                    }
                }

                i = 0;
                count += 1;
            }
            else
            {
                str[i] = c;
                i += 1;
            }
        }
        printf("\n");
        printf("%d/%d Rule is checked",count-fail,count);
    }
    else
    {
        printf("File tidak ada.\n");
    }

}
