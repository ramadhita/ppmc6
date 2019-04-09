/*
Program Input Asisten Manual
*/
#include <stdio.h>
#include <string.h>

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
	char input[8], Asis,nama[8],prak1[8],prak2[8];
	int minggu=100, hari=100, lab=100, asis, gbs[3]; //cant untuk mengetahui hari yang berhalangan, day untuk konversi hari ke integer
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
					if (listAsisten[minggu][hari][lab][0]=='') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='A'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]=='') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='A';
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
					if (listAsisten[minggu][hari][lab][0]=='') //artinya dia masih null, belum ada asisten
					listAsisten[minggu][hari][lab][0]='B'; //Masukkan ke list karena memenuhi, dan masih kosong
					else if (listAsisten[minggu][hari][lab][1]=='') //Artinya udah ada satu asisten disitu, jadi ditambahnya ke array kedua
					listAsisten[minggu][hari][lab][1]='B';
				//Kalo dua duanya nggak kosong, maka gabakal keisi
				} else printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan EL2205)\n", nama);
			break;
		/*
			case 'C': ;
				strcpy(nama,"Cici");
				strcpy(prak1,"EL2205");
				gbs[0]=1;
				gbs[1]=2;
			break;
			
			case 'D': ;
				strcpy(nama,"Doni");
				strcpy(prak1,"EL2205");
				gbs[0]=0;
				gbs[1]=2;
			break;
			
			case 'E': ;
				strcpy(nama,"Endang");
				strcpy(prak1,"EL2205");
				strcpy(prak2,"EL2208");
				gbs[0]=-1;
				gbs[1]=-1;
			break;
			
			case 'F': ;
				strcpy(nama,"Fadel");
				strcpy(prak1,"EL2205");
				gbs[0]=1;
				gbs[1]=-1;
			break;
			
			case 'G': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2205");
				gbs[0]=1;
			break;

			case 'H': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2208");
				gbs[1]=1;
			break;
			
			case 'I': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2208");
				gbs[1]=1;
			break;
			
			case 'J': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2205");
				gbs[1]=1;
			break;
			
			case 'K': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2205");
				gbs[1]=1;
			break;
			
			case 'L': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2205");
				gbs[1]=1;
			break;
			
			case 'M': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2205");
				gbs[1]=1;
			break;
			
			case 'N': ;
				strcpy(nama,"Budi");
				strcpy(prak1,"EL2205");
				gbs[1]=1;
			break;
			*/	
	 	}
	 	
	}
	
	printf("Debug (ntar apus aja) :udah berhasil quit dari Q ini \n");
	return;
}
/*
int main()
{

	return 0;
}
*/