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

// ---------------------------------------- FUNGSI TAMBAHAN
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

// ------------------------- FUNGSI TAMPILKAN -----------------------
int tampilkanSchedule (){
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
				printf ("\t|\t%d\t|", [i+3]);
				printf ("\t%s\t|", getHari(j));
				for (k=1 ; k=4 ; k++)
				{
					printf ("\t%s\t|", listPraktikum[i][j][k]);
				}
				printf ("\n");
			}
			printf ("\t|-----------------------------------------------------------------|\n");
		}
	}

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


/*
Program Input Asisten Manual
*/


int getIndexAsisten (char str)
{
	int index;
	if (str=='q' || str=='Q') index =-1;
	else if ( str=='A' || str =='B' || str =='C' || str =='D' || str =='E' || str =='F' || str =='G' || str =='H' || str =='I' || str =='J' )
		index = 1;
	else index = 0;
	return index;
}

int getIndexMinggu (char *str)
{
	int index;
	if (strcmp("Q",str)==0 || strcmp("q",str)==0)
		index =-1;
	else
	{
		index=-2;
		if (atoi(str)>2 && atoi(str)<15)
		{
			index = atoi(str)-3;
		}
	}
	return index;
}

int getIndexLab (char *str)
{
	int index;
	if (strcmp("Q",str)==0 || strcmp("q",str)==0)
		index =-1;
	else
	{
		index=-2;
		if (strcmp("LAB1", str)==0) index=0;
		else if (strcmp("LAB2", str)==0) index=1;
		else if (strcmp("LAB3",str)==0) index=2;
		else if (strcmp("LSS", str)==0) index=3;
	}
	return index;
}

int getIndexHari (char *str)
{
	int index;
	if (strcmp("Q",str)==0 || strcmp("q",str)==0)
		index =-1;
	else
	{
		index=-2;
		if (strcmp("Senin", str)==0) index=0;
		else if (strcmp("Selasa", str)==0) index=1;
		else if (strcmp("Rabu",str)==0) index=2;
		else if (strcmp("Kamis", str)==0) index=3;
		else if (strcmp("Jumat", str)==0) index=4;
	}
	return index;
}

void AssignAsisten(char listAsisten[12][5][4][2], praktikum listPraktikum[12][5][4])
{
	char input[8], Asis,nama[8];
	int minggu=100, hari=100, lab=100, asis; //cant untuk mengetahui hari yang berhalangan, day untuk konversi hari ke integer
	int i,j,k,l;
	for (i = 0; i < 12; ++i)
		for (j = 0; j < 5; ++j)
			for (k = 0; k < 4; ++k)
				for (l = 0; l < 2; ++l)
					listAsisten[i][j][k][l]=' ';

	printf("[Mode Assign Asisten]\n Isi 'q' atau 'Q' untuk kembali ke menu\n");
	while (minggu!=-1 && lab!=-1 && hari!= -1 && asis!= -1)
	{
		printf("Pilih Asisten (A-N): ");
		scanf("%c",&Asis);
		getchar();
		while(getIndexAsisten(Asis) == 0)
        {
            printf("Inputan salah. Inisial Asisten tidak benar, ulangi masukan\n");
            printf("Pilih Asisten (A-N): ");
            scanf("%c",&Asis);
            getchar();
        	if (getIndexAsisten(Asis)==-1) return;
        }
        asis= getIndexAsisten(Asis);
        if (asis==-1) return;
		//Masukan Minggu
		printf("Minggu: ");
		gets(input);
      while(getIndexMinggu(input) == -2)
       {
           printf("Inputan salah. Minggu dari 3-15. Ulangi masukan minggu\n");
           printf("Minggu: ");
           gets(input);
     	   if (getIndexMinggu(input)==-1) return;
       }
      minggu=getIndexMinggu(input);
      if (minggu==-1) return;
      
      //Masukan Hari
		printf("Hari: ");
		gets(input);
      while(getIndexHari(input) == -2)
       {
           printf("Inputan salah. Hari Senin-Jumat. Ulangi masukan hari\n");
           printf("Hari: ");
           gets(input);
     	   if (getIndexHari(input)==-1) return;
       }
      hari=getIndexHari(input);
      if (hari==-1) return;
      //Masukan ruang
	  printf("Ruang: ");
	  gets(input);
      while(getIndexLab(input) == -2)
       {
           printf("Inputan salah. Pilih Ruang yang benar\n");
           printf("Ruang: ");
           gets(input);
           lab=getIndexLab(input);
     	   if (lab==-1) return;
       }
       lab=getIndexLab(input);
       if (lab==-1) return;
     
     //BUAT MASUKIN CONSTRAINT
     //Validasi apakah Asisten ini memenuhi syarat di hari dan lab tersebut
      /*
      	Index 1 = EL2205
      	Index 2 = EL2208
      	Index 3 = EB2200
      */
		switch(Asis)
		{
			case 'A': ;
				strcpy(nama,"Amir");
				if (hari == 2) //Amir gabisa hari Rabu, dan dia cuma asisten EL2205
				{
					printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Rabu)\n",nama, nama);
				} else
				if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='A'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='A';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka gabakal keisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;

			case 'B': ;
				strcpy(nama,"Budi");
				if (hari == 0) //Amir gabisa hari Senin, dan dia cuma asisten EL2205
				{
					printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Rabu)\n",nama, nama);
				} else
				if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='B'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='B';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka gabakal keisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;
		
			case 'C': ;
				//Cici gabisa hari Selasa dan Rabu, dan dia cuma asisten EL2205
				nstrcpy(nama,"Cici");
				if (hari == 1) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Selasa)\n",nama, nama);
				else if (hari ==2) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Rabu)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='C'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='C';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;
		
			case 'D': ;
				strcpy(nama,"Doni");
				if (hari == 1) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Selasa)\n",nama, nama);
				else if (hari ==2) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Rabu)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='D'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='D';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;
		
			case 'E': ;
				strcpy(nama,"Endang");
				if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='E'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='E';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='E'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='E';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205 maupun EL2208)\n", nama);
			break;
			
			case 'F': ;
				strcpy(nama,"Fadel");
				if (hari == 1) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Selasa)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='F'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='F';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;
			
			case 'G': ;
				strcpy(nama,"Gilang");
				if (hari == 3) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Kamis)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='G'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='G';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='G'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='G';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205 maupun EB2200)\n", nama);
			break;

			case 'H': ;
				strcpy(nama,"Hero");
				if (hari == 3) //Amir gabisa hari Senin, dan dia cuma asisten EL2205
				{
					printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Kamis)\n",nama, nama);
				} else
				if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='H'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='H';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka gabakal keisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;
			
			case 'I': ;
				strcpy(nama,"Intan");
				if (hari == 2) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Rabu)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 1)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='I'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='I';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='I'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='I';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else if (listPraktikum[minggu][hari][lab].matkul == 3)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='I'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='I';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} 
				else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205, EL2208, maupun EB2200)\n", nama);

			break;
			
			case 'J': ;
				strcpy(nama,"Joko");
				if (hari == 4) //Amir gabisa hari Rabu, dan dia cuma asisten EL2205
				{
					printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Jumat)\n",nama, nama);
				} else
				if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='J'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='J';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka gabakal keisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2208)\n", nama);
				
			break;
			
			case 'K': ;
				strcpy(nama,"Kiki");
				if (hari == 4) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Jumat)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='K'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='K';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else if (listPraktikum[minggu][hari][lab].matkul == 3)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='K'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='K';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2208 maupun EB2200)\n", nama);

			break;
			
			case 'L': ;
				strcpy(nama,"Louis");
				if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='L'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='L';
					else printf("Sudah ada dua asisten.\n");
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2208)\n", nama);

			break;
			
			case 'M': ; //mini tidak bisa di hari rabu dan kamis, dan dia asisten kode 2
				strcpy(nama,"Mini");
				if (hari == 2) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Rabu)\n",nama, nama);
				else if (hari ==3) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Kamis)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='M'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='M';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2208)\n", nama);
			break;
			
			case 'N': ; //Nina gabisa hari selasa, dia asisten el2208 dan eb2200
				strcpy(nama,"Nina");
				if (hari == 1) printf("Jadwal Asisten Praktikum %s tidak sesuai (%s berhalangan di hari Selasa)\n",nama, nama);
				else if (listPraktikum[minggu][hari][lab].matkul == 2)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='N'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='N';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else if (listPraktikum[minggu][hari][lab].matkul == 3)
				{
					if (listAsisten[minggu][hari][lab][0]==' ') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='N'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]==' ') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='N';
					else printf("Sudah ada dua asisten.\n");
				//Kalo dua duanya nggak kosong, maka tidak akan ada yang terisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2208 maupun EB2200)\n", nama);
			break;
			
	 	}
	 	
	}
	
	//printf("Debug (ntar apus aja) :udah berhasil quit dari Q ini \n");
	return;
}
