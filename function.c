//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              :
// Module            : Tugas Besar
// Problem           : function
// File Name         : function.c
// Dependency        : "function.h"
//
// Status:
//		1.  Arief Himanto / 13217076
//		2.  Minangkara Ciandi Rengga / 13217087
//		3.  Kevin Sutardi / 13217088
//		4.  Ramadhita Umitaibatin / 18317008
//		5.  Muhammad Harun Al Rasyid / 18317009
//
//***********************************************************//

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
    char *asisten;
    // Cek apakah keduanya null
    if (list[0] == '\0' && list[1] == '\0')
    {
        asisten = malloc(2*sizeof(char));
        asisten[0] = ' ';
        asisten[1] = '\0';
    }
    else
    {
        asisten = malloc(4*sizeof(char));
        if (list[0] == '\0')
        {
            asisten[0] = ' ';
            asisten[2] = list[1];
        }
        else
        {
            asisten[0] = list[0];
            asisten[2] = ' ';
        }
        asisten[1] = ',';
        asisten[3] ='\0';
    }
    return asisten;
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
            else if (strcmp("A", str) == 0) {index = 7;}
            else if (strcmp("B", str) == 0) {index = 8;}
            else if (strcmp("C", str) == 0) {index = 9;}
            break;
        case 2:
            if (strcmp("C", str) == 0){index = 7;}
            if (strcmp("A1", str) == 0) {index = 1;}
            else if (strcmp("A2", str) == 0) {index = 2;}
            else if (strcmp("A3", str) == 0) {index = 3;}
            else if (strcmp("B1", str) == 0) {index = 4;}
            else if (strcmp("B2", str) == 0) {index = 5;}
            else if (strcmp("B3", str) == 0) {index = 6;}
            else if (strcmp("A", str) == 0) {index = 8;}
            else if (strcmp("B", str) == 0) {index = 9;}
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

// ---------------------------------------- FUNGSI TAMBAHAN

int getIndexAsisten (char str)
{
	int index = 0;
	if (str=='q' || str=='Q')
    {
        index = -1;
    }
	else if ( (int)str > 64 && (int)str < 79 )
    {
        index = ((int)str) - 64;
    }
	return index;
}



// ------------------------- FUNGSI TAMPILKAN -----------------------
void viewSchedule (praktikum listPraktikum[12][5][4])
{
    int i, j, k;
	printf ("\n\n\t|--------------------|----------|----------|----------|----------|\n");
	printf ("\t|   Ruang Praktikum   |   Lab 1  |   Lab 2  |   Lab 3  |    LSS   |\n");
	printf ("\t|---------------------|----------|----------|----------|----------|\n");
	printf ("\t|  Minggu  |   Hari   |----------|----------|----------|----------|\n");
	printf ("\t|----------|----------|----------|----------|----------|----------|\n");
	for (i = 0 ; i < 12 ; i++)
	{
        for (j = 0 ; j < 5 ; j++)
        {
            printf ("\t|\t%d\t|", i+3);
            printf ("\t%s\t|", getHari(j + 1));
            for (k = 0 ; k < 4 ; k++)
            {
                printf ("\t%s%s\t|", getMatkul(listPraktikum[i][j][k].matkul), getGroup(listPraktikum[i][j][k].matkul, listPraktikum[i][j][k].group));
            }
            printf ("\n");
        }
        printf ("\t|-----------------------------------------------------------------|\n");
    }
}

void viewAsisten (char listAsisten[12][5][4][2])
{
	int i, j, k;
	printf ("\n\n\t|--------------------|----------|----------|----------|----------|\n");
	printf ("\t|   Ruang Praktikum   |   Lab 1  |   Lab 2  |   Lab 3  |    LSS   |\n");
	printf ("\t|---------------------|----------|----------|----------|----------|\n");
	printf ("\t|  Minggu  |   Hari   |----------|----------|----------|----------|\n");
	printf ("\t|----------|----------|----------|----------|----------|----------|\n");
	for (i=0 ; i<12 ; i++)
	{
        for (j=0 ; j<5 ; j++)
        {
            printf ("\t|\t%d\t|", i+3);
            printf ("\t%s\t|", getHari(j+1));
            for (k = 0 ; k < 4 ; k++)
            {
                printf ("\t%s\t|", getAsisten(listAsisten[i][j][k]));
            }
            printf ("\n");
        }
        printf ("\t|-----------------------------------------------------------------|\n");
    }
}

void assignPraktikum(praktikum listPraktikum[12][5][4])
{
    char input[7];
    int i, size, prakIndex, groupIndex, mingguIndex, hariIndex, ruangIndex;
    printf("[Mode Schedule]\nIsi `q` atau `Q` untuk kembali ke menu\n");
    strcpy(input, "");
    while(prakIndex != -1 && groupIndex != -1 && mingguIndex != -1 && hariIndex != -1 && ruangIndex != -1)
    {
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        if ((int)input[0] != 76)
        {
            getchar();
        }
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
                    //getchar();
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

                            if (groupIndex > 6)
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
                                        listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].group = i + 1 + (groupIndex - 7)*2;
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
                        else if (prakIndex == 2)
                        {

                            if (groupIndex > 7)
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
                                        listPraktikum[mingguIndex][hariIndex - 1][ruangIndex - 1].group = i + 1 + (groupIndex - 8)*3;
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

void assignAsisten(asisten listData[14], char listAsisten[12][5][4][2], praktikum listPraktikum[12][5][4])
{
    int i, minggu, hari, lab, asis;
    char *id, input[8], matkul[8];

	printf("[Mode Assign Asisten]\n Isi 'q' atau 'Q' untuk kembali ke menu\n");
	strcpy(input, "");
	while (minggu !=-1 && lab !=-1 && hari != -1 && asis != -1)
	{
        printf("Pilih Asisten (A-N): ");
		if ((int)input[0] != 76)
        {
            getchar();
        }
		gets(input);
		asis = getIndexAsisten(input[0]);
        while(asis == 0)
        {
                printf("Inputan salah. Inisial Asisten tidak benar, ulangi masukan\n");
                printf("Pilih Asisten (A-N): ");
                gets(input);
                asis = getIndexAsisten(input[0]);
        }
        if (asis != -1)
        {
            printf("Minggu: ");
            gets(input);
            minggu = getMingguIndex(input);
            while(minggu == -2)
            {
                printf("Inputan salah. Minggu dari 3-15. Ulangi masukan minggu\n");
                printf("Minggu: ");
                gets(input);
                minggu = getMingguIndex(input);
            }
            if (minggu != -1)
            {
                printf("Hari: ");
                gets(input);
                hari = getHariIndex(1, 1, input);
                while(hari == 0)
                {
                    printf("Inputan salah. Hari Senin-Jumat. Ulangi masukan hari\n");
                    printf("Hari: ");
                    gets(input);
                    hari = getHariIndex(1, 1, input);
                }
                if (hari != -1)
                {
                    printf("Ruang: ");
                    gets(input);
                    lab = getRuangIndex(input);
                    while(lab == 0)
                    {
                        printf("Inputan salah. Pilih Ruang yang benar\n");
                        printf("Ruang: ");
                        gets(input);
                        lab = getRuangIndex(input);
                    }
                    if (lab != -1)
                    {
                        if (listData[asis - 1].hari[hari - 1] == 1)
                        {
                            printf("Jadwal Asisten Praktikum %s tidak sesuai (berhalangan di hari %s)\n\n", listData[asis - 1].nama, getHari(hari));
                        }
                        else if (listPraktikum[minggu][hari - 1][lab - 1].matkul == 0)
                        {

                            printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada praktikum pada ruangan)\n\n", listData[asis - 1].nama);
                        }
                        else if (listData[asis-1].prak[listPraktikum[minggu][hari - 1][lab - 1].matkul-1] != 1)
                        {
                            for (i = 0; i < 3; i++)
                            {
                                if (listData[asis-1].prak[i] == 1)
                                {
                                    strcpy(matkul, getMatkul(i + 1));
                                    matkul[6] = '\0';
                                    printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan %s)\n", listData[asis - 1].nama, matkul);
                                }
                            }
                            printf("\n");

                        }
                        else
                        {
                            if (listAsisten[minggu][hari - 1][lab - 1][0] == '\0')
                            {
                                listAsisten[minggu][hari - 1][lab - 1][0] = listData[asis-1].nama[0];
                            }
                            else
                            {
                                if (listAsisten[minggu][hari - 1][lab - 1][1] == '\0')
                                {
                                    listAsisten[minggu][hari - 1][lab - 1][1] = listData[asis-1].nama[0];
                                }
                                else
                                {
                                    printf("Sudah ada dua asisten.\n\n");
                                }
                            }
                        }
                    }

                }


            }
        }
	}
}
