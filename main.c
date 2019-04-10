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
	int pilihan1;
	int pilihan2;
	while((pilihan1 != 3))
	{
		printf("Menu : \n");
		printf("	1.  Buat Proyek Baru \n");
		printf("	2.  Muat Proyek Dari Berkas \n");
		printf("	3.  Keluar \n");
		printf("Masukan :");scanf("%d", &pilihan1);
		if((pilihan1 < 1) || (pilihan1 >3))
		{
			printf("\n");
			printf("Input Salah !\n");
			printf("Pilihan Menu Hanya 1,2, Dan 3 \n");
			printf("\n");
		}
		if((pilihan1 == 1) || (pilihan1 == 2))
		{
			if(pilihan1 == 1)
			{
				printf("Fungsi new_project \n");
				buatProyek();
			}
			else if(pilihan1 == 2)
			{
				printf("Fungsi load_project \n");
				loadPraktikum(listPraktikum);
				loadAsisten(listAsisten);
			}
			printf("\n");
			while(pilihan2 != 8)
			{
				printf("[Menu Utama]\n");
				printf("Pilih Mode :\n");
				printf("	1.  Tampilkan Schedule\n");
				printf("	2.  Scehdule Manual\n");
				printf("	3.  Tampilkan Status Assignment Asisten\n");
				printf("	4.  Assign Asisten Manual\n");
				printf("	5.  Schedule Otomatis\n");
				printf("	6.  Assign Otomatis\n");
				printf("	7.  Rule Checker\n");
				printf("	8.  Simpan Proyek dan Keluar\n");
				printf("Pilih Mode :");scanf("%d", &pilihan2);
				if(pilihan2 == 1)
				{
					printf("Fungsi print_jadwal \n");
					tampilkanSchedule();
				}
				else if(pilihan2 == 2)
				{
					printf("Fungsi jadwal_manual \n");
					assignPraktikum(praktikum listPraktikum[12][5][4]);
				}
				else if(pilihan2 == 3)
				{
					printf("Fungsi print_asisten \n");
					tampilkanAsisten();
				}
				else if(pilihan2 == 4)
				{
					printf("Fungsi asisten_manual \n");
					AssignAsisten(char listAsisten[12][5][4][2], praktikum listPraktikum[12][5][4]);
				}
				else if(pilihan2 == 5)
				{
					printf("Fungsi jadwal_auto \n");
					printf("Belum Tersedia\n");
				}
				else if(pilihan2 == 6)
				{
					printf("Fungsi asisten_auto \n");
					printf("Belum Tersedia\n");
				}
				else if(pilihan2 == 7)
				{
					printf("Fungsi rule_check \n");
				}
				else if(pilihan2 == 8)
				{
					printf("Fungsi save \n");
					savePraktikum(listPraktikum);
					saveAsisten(listAsisten);
				}
				else
				{
					printf("Input Salah ! \n");
				}
			}
			pilihan2 = 0;
		}
	}
	return 0;
}
