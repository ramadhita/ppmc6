#include <filehandler.h>

//fungsi loadFile
void loadPraktikum(praktikum* listPraktikum[12][5][4]){
    FILE *filePointer;
    int i, j, k;
    char ch;
    char str[MAX];
    hapusHeader(); //hapus bagian 2 line awal (header)
    filePointer = fopen("tes.csv", "r+");
    //validasi file eksternal
    if(feof(filePointer)){
        printf("File tidak tersedia");
    } else { 
        while(!feof(filePointer)){
	    //copy ke string utk displit
            fgets(str, MAX, filePointer);
        }
    }
    // ----- split string ke list --- //
    i = 0;
    j = 0;
    k = 0;
    char* strtemp = str; //variabel penampung supaya string asli tidak rusak
    char* token = strtok(strtemp, "|"); //memisahkan per bagian |
    for (i=0; i<12; i++){ //iterasi dari minggu
        while (token != NULL && j<5) { //iterasi dari hari
            char* token2 = strtok(token, "-"); //memisahkan matkul dan grup
            while(token2 != NULL && k<4){ //iterasi dari lab
                 = token2
            } 
            token = strtok(NULL, "-"); 
        }
    } 
    //
    // ch = fgetc(filePointer);
    // while(ch!=EOF) 
    //     { 
    //         printf("%c",ch); 
    //         ch=fgetc(filePointer); 
    //     }
    fclose(filePointer);
}

//load asisten
//masih belum bener, belum didebug kayak bagian praktikum
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

void hapusHeader(){
    int ctr = 0;
    // char ch; hanya utk ngecek isi file aja
    int lineRemove1 = 1;
    int lineRemove2 = 2;
    FILE *fptr1, *fptr2;
    char* fname = "tes.csv";
    char str[MAX], temp[] = "temp.csv";      
    fptr1 = fopen(fname, "r");
    if (!fptr1) 
    {
            printf(" File not found or unable to open the input file!!\n");
    }
    fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
    if (!fptr2) 
        {
            printf("Unable to open a temporary file to write!!\n");
            fclose(fptr1);
        }
    // copy all contents to the temporary file except the specific line
    while (!feof(fptr1)) {
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1)) 
        {
            ctr++;
                /* skip the line at given line number */
            if (ctr != 1 && ctr != 2) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);          // remove file asli 
        rename(temp, fname);    // rename file temp menjadi file asli
/*------ cek isi file dengan tampilkan ke layar ----------------*/
        // fptr1=fopen(fname,"r"); 
        // ch=fgetc(fptr1); 
        // printf(" Now the content of the file %s is : \n",fname); 
        // while(ch!=EOF) 
        // { 
        //     printf("%c",ch); 
        //     ch=fgetc(fptr1); 
        // }
        // fclose(fptr1);
/*------- End of cek isi ---------------*/
} 
