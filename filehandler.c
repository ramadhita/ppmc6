#include <filehandler.h>

//fungsi loadFile
void loadPraktikum(praktikum listPraktikum[][][]){
	FILE *filePointer;
    int i, j, k;
    char* matkul1;
    char* matkul2;
    char* matkul3;
    char* matkul4;
    char* group1;
    char* group2;
    char* group3;
    char* group4;
    int counter = 1;
    filePointer = fopen("Jadwal_Praktikum_Semester_2_rombongan.csv", "r+");
    if(filePointer == NULL){
    	printf("File tidak tersedia");
    } else {
    	while(filePointer != NULL){
    		counter++;
    		for(i=0; i<12; i++){
    			for(j=0; j<5; j++){
    				if(counter == 1 && counter == 2){
    					fscanf(filePointer, "%*d|%*s|%s-%s|%s-%s|%s-%s|%s-%s|",
    						&matkul1, &group1,
    						&matkul2, &group2,
    						&matkul3, &group3,
    						&matkul4, &group4,);
    					listPraktikum[i][j][0].matkul = getPrakIndex(matkul1);
    					listPraktikum[i][j][1].matkul = getPrakIndex(matkul2);
    					listPraktikum[i][j][2].matkul = getPrakIndex(matkul3);
    					listPraktikum[i][j][3].matkul = getPrakIndex(matkul4);
    					listPraktikum[i][j][0].group = getGroupIndex(group1);
    					listPraktikum[i][j][1].group = getPrakIndex(group2);
    					listPraktikum[i][j][2].group = getPrakIndex(group3);
    					listPraktikum[i][j][3].group = getPrakIndex(group4);
    				}
    			}
    		}
    	}
    }
    free(matkul1);
    free(matkul2);
    free(matkul3);
    free(matkul4);
    free(group1);
    free(group2);
    free(group3);
    free(group4);
}

//load asisten
void loadAsisten(char listAsisten[12][5][4][2]){
	FILE *filePointer;
    int i, j, k;
    int counter = 1;
    filePointer = fopen("Jadwal_Praktikum_Semester_2_asisten.csv", "r+");
    if(filePointer == NULL){
    	printf("File tidak tersedia");
    } else {
    	while(filePointer != NULL){
    		counter++;
    		for(i=0; i<12; i++){
    			for(j=0; j<5; j++){
    				if(counter == 1 && counter == 2){
    					fscanf(filePointer, "%*d|%*s|%s,%s|%s,%s|%s,%s|%s,%s",
    						&listAsisten[i][j][0][1], &listAsisten[i][j][0][2],
    						&listAsisten[i][j][1][1], &listAsisten[i][j][1][2],
    						&listAsisten[i][j][2][1], &listAsisten[i][j][2][2],
    						&listAsisten[i][j][3][1], &listAsisten[i][j][3][2],);
    				}
    			}
    		}
    	}
    }
}
