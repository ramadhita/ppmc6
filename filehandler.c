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
void loadAsisten(char listAsisten[12][5][4][2])
{
    FILE *filePointer;
    int  i, j, k, line, minggu, hari;
    char *asisten2, *asisten1;
    char c;
    char *gn, *gi;
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
                                    listAsisten[minggu][hari - 1][k][0] = 0;
                                    listAsisten[minggu][hari - 1][k][1] = 0;
                                }

                            break;
                            default:
                                gn = strtok(tok, "-");
                                asisten1 = gn;
                                //printf("%s-", gn);
                                gn = strtok(NULL, "-");
                                asisten2 = gn;
                               // printf("Debug %d% - s", prak, getGroup(prak, grup));
                                listAsisten[minggu][hari-1][j-2][0] = asisten1[0];
                                listAsisten[minggu][hari-1][j-2][1] = asisten2[0];
                                //printf("%s%s|",getMatkul(prak), getGroup(prak, grup));
                                //printf("%s", gn);
                            break;
                        }
                        j += 1;
                        tok = strtok(NULL, "|");

                    }

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
