#include "function.h"

char* getGroup(int matkul, int index)
{
    char *group;
    group = malloc(3 * sizeof(char));
    group[0] = '\0';
    group[1] = '\0';
    group[2] = '\0';
    switch(matkul)
    {
        case 1:
            group[0] = (char)(64 + (int)(ceil((double)index / 2)));
            //printf("Letter: %c *", group[0]);
            group[1] = (char)(50 - index % 2);
            break;
        case 2:
            if (index == 7)
            {
                group[0] = 'C';
            }
            else
            {
                group[0] = (char)(64 + (int)ceil((double)index / 3));
                if(index % 3 == 0)
                {
                    group[1] = '3';
                }
                else
                {
                    group[1] = (char)(51 - index % 3);
                }

            }
            break;
        case 3:
            group[0] = index + 64;
            break;
        default:
            break;
    }
    return group;
}

char* getAsisten(char list[2])
{
    if ((int)list[0] < 65 || (int)list[0]>73)
    {
        return "";
    }
    else
    {
        char *asisten;
        asisten = malloc(3*sizeof(char));
        asisten[0] = list[0];
        asisten[1] = ',';
        asisten[2] = list[1];
        asisten[3] ='\0';
        return asisten;
    }
}

char* getMatkul(int index)
{
    switch (index)
    {
    case 1:
        return "EL2205-";
        break;
    case 2:
        return "EL2208-";
        break;
    case 3:
        return "EB2200-";
        break;
    default:
        return " ";
        break;
    }
}

char* getHari(int index)
{
    switch (index)
    {
    case 1:
        return "Senin";
        break;
    case 2:
        return "Selasa";
        break;
    case 3:
        return "Rabu";
        break;
    case 4:
        return "Kamis";
        break;
    case 5:
        return "Jumat";
        break;
    default:
        return "";
        break;
    }
}
void assignPraktikum(praktikum listPraktikum[12][5][4])
{
    char input[7];
    int i, size, prakIndex, groupIndex, mingguIndex, hariIndex, ruangIndex;
    printf("[Mode Schedule]\nIsi `q` atau `Q` untuk kembali ke menu\n");
    while(prakIndex != -1 && groupIndex != -1 && mingguIndex != -1 && hariIndex != -1 && ruangIndex != -1)
    {
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        gets(input);
        while(getPrakIndex(input) == 0)
        {
            printf("Inputan salah. Pastikan kode matkul sesuai daftar.\n");
            printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
            gets(input);
        }
        prakIndex = getPrakIndex(input);
        if (prakIndex != -1)
        {
            switch(prakIndex)
            {
                case 1:
                    printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
                    break;
                case 2:
                    printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
                    break;
                case 3:
                    printf("Rombongan (A atau B): ");
                    break;
            }
            gets(input);
            while(getGroupIndex(prakIndex, input) == 0)
            {
                printf("Inputan salah. Pastikan rombongan sesuai daftar.\n");
                switch(prakIndex)
                {
                case 1:
                    printf("Rombongan (A1,A2,B1,B2,C1, atau C2): ");
                    break;
                case 2:
                    printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");
                    break;
                case 3:
                    printf("Rombongan (A atau B): ");
                    break;
                }
                gets(input);
            }
            groupIndex = getGroupIndex(prakIndex, input);

            if (groupIndex != -1)
            {
                printf("Minggu ke: ");
                gets(input);
                while(getMingguIndex(input) == -2)
                {
                    printf("Inputan salah. Pastikan minggu sesuai rentang.\n");
                    printf("Minggu ke: ");
                    gets(input);
                }
                mingguIndex = getMingguIndex(input);
                if (mingguIndex != -1)
                {
                    printf("Hari: ");
                    gets(input);
                    while(getHariIndex(prakIndex, groupIndex, input) == 0)
                    {
                        printf("Inputan salah. Pastikan hari sesuai rentang.\n");
                        printf("Hari: ");
                        gets(input);
                    }
                    hariIndex = getHariIndex(prakIndex, groupIndex, input);
                    if (hariIndex != -1)
                    {
                        if (prakIndex == 1)
                        {
                            size = 2;
                            for (i = 0; i < size; i++)
                            {
                                printf("Ruangan %d: ", i + 1);
                                gets(input);
                                while(getRuangIndex(input) == 0)
                                {
                                    printf("Input salah. Pastikan lab terdaftar.\n");
                                    printf("Ruangan %d: ", i + 1);
                                    gets(input);
                                }
                                ruangIndex =  getRuangIndex(input);
                                if (ruangIndex != -1)
                                {
                                    listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].matkul = prakIndex;
                                    listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].group = groupIndex;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else if (prakIndex == 2)
                        {

                            size = 3;
                            for (i = 0; i < size; i++)
                            {
                                printf("Ruangan %d: ", i + 1);
                                gets(input);
                                while(getRuangIndex(input) == 0)
                                {
                                    printf("Input salah. Pastikan lab terdaftar.\n");
                                    printf("Ruangan %d: ", i + 1);
                                    gets(input);
                                }
                                ruangIndex =  getRuangIndex(input);
                                if (ruangIndex != -1)
                                {
                                    listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].matkul = prakIndex;
                                    listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].group = groupIndex;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }

                        else
                        {
                            printf("Ruangan: ");
                            gets(input);
                            while(getRuangIndex(input) == 0)
                            {
                                printf("Input salah. Pastikan lab terdaftar.\n");
                                printf("Ruangan: ");
                                gets(input);
                            }
                            ruangIndex =  getRuangIndex(input);
                            if (ruangIndex != -1)
                            {
                                listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].matkul = prakIndex;
                                listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].group = groupIndex;
                            }
                        }
                    }
                }
            }
        }
    }
}

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
        index = -2;
        if (atoi(str) > 2 && atoi(str) < 16)
        {
            index = atoi(str) - 3;
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

//FUNGSI TAMBAHAN
int getHariIndex2(char* str){
  switch (str)
    {
    case "Senin":
        return 0;
        break;
    case "Selasa":
        return 1;
        break;
    case "Rabu":
        return 2;
        break;
    case "Kamis":
        return 3;
        break;
    case "Jumat":
        return 4;
        break;
    default:
        return -1;
        break;
    }
}
