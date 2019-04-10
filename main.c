//***********************************************************//
//                      [ Source Code ]
//
// Institution       : Institut Teknologi Bandung
// Name              :
// Module            : Tugas Besar
// Problem           : Main Program
// File Name         : main.c
// Dependency        : stdio.h, stdlib.h, "filehandler.h", "function.h"
//
// Status:
//		1.  Arief Himanto / 13217076
//		2.  Minangkara Ciandi Rengga / 13217087
//		3.  Kevin Sutardi / 13217088
//		4.  Ramadhita Umitaibatin / 18317008
//		5.  Muhammad Harun Al Rasyid / 18317009
//
//***********************************************************//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filehandler.h"
#include "function.h"

int main()
{
    char listAsisten[12][5][4][2];
    praktikum listPraktikum[12][5][4];
    asisten listData[14];


    int pilihan1, pilihan2;
    pilihan1 = 0;
    pilihan2 = 0;

	while((pilihan1 != 3))
	{
	    pilihan2 = 0;
		printf("Menu : \n");
		printf("	1.  Buat Proyek Baru \n");
		printf("	2.  Muat Proyek Dari Berkas \n");
		printf("	3.  Keluar \n");
		printf("Masukan: ");
		scanf("%d", &pilihan1);
        while((pilihan1 < 1) || (pilihan1 > 3))
		{
		    pilihan2 = 0;
			printf("\n");
			printf("Input Salah !\n");
			printf("Pilihan Menu Hanya 1,2, Dan 3 \n");
			printf("\n");
			printf("Menu : \n");
            printf("	1.  Buat Proyek Baru \n");
            printf("	2.  Muat Proyek Dari Berkas \n");
            printf("	3.  Keluar \n");
            printf("Masukan: ");
            scanf("%d", &pilihan1);
		}
		if (pilihan1 != 3)
		{
			if(pilihan1 == 1)
			{
				printf("Projek baru telah dibuat. \n");
				newProject(listAsisten,listPraktikum);
				loadAsistenFile(listData);
			}
			else if(pilihan1 == 2)
			{
				printf("Me-load projek yang telah dibuat. \n");
				loadPraktikum(listPraktikum);
				loadAsisten(listAsisten);
				loadAsistenFile(listData);
			}
            while(pilihan2 != 8)
            {
                printf("[Menu Utama]\n");
                printf("Pilih Mode :\n");
                printf("	1.  Tampilkan Schedule\n");
                printf("	2.  Schedule Manual\n");
                printf("	3.  Tampilkan Status Assignment Asisten\n");
                printf("	4.  Assign Asisten Manual\n");
                printf("	5.  Schedule Otomatis\n");
                printf("	6.  Assign Otomatis\n");
                printf("	7.  Rule Checker\n");
                printf("	8.  Simpan Proyek dan Keluar\n");
                printf("Pilih Mode: ");
                scanf("%d", &pilihan2);
                while((pilihan2 < 1 || pilihan2 > 7) && pilihan2 != 8)
                {
                    printf("Input Salah ! \n");
                    printf("[Menu Utama]\n");
                    printf("Pilih Mode :\n");
                    printf("	1.  Tampilkan Schedule\n");
                    printf("	2.  Schedule Manual\n");
                    printf("	3.  Tampilkan Status Assignment Asisten\n");
                    printf("	4.  Assign Asisten Manual\n");
                    printf("	5.  Schedule Otomatis\n");
                    printf("	6.  Assign Otomatis\n");
                    printf("	7.  Rule Checker\n");
                    printf("	8.  Simpan Proyek dan Keluar\n");
                    printf("Pilih Mode: ");
                    scanf("%d", &pilihan2);
                }
                if (pilihan2 != 8)
                {
                    switch(pilihan2)
                    {
                        case 1:
                            viewSchedule(listPraktikum);
                        break;
                        case 2:
                            assignPraktikum(listPraktikum);
                        break;
                        case 3:
                            viewAsisten(listAsisten);
                        break;
                        case 4:
                            assignAsisten(listData, listAsisten, listPraktikum);
                        break;
                        case 5:
                        break;
                        case 6:
                        break;
                        case 7:
                            ruleCheck(listPraktikum);
                        break;
                    }
                }
                else
                {
                    savePraktikum(listPraktikum);
                    saveAsisten(listAsisten);
                    printf("Schedule disimpan dalam berkas Jadwal_Praktikum_Semester_2_rombongan.csv\n");
                    printf("Asisten disimpan dalam berkas Jadwal_Praktikum_Semester_2_asisten.csv\n");

                }

            }

		}
	}


	return 0;
}
