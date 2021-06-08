#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <errno.h>
#include<conio.h>
#include<windows.h>


extern int errno;

typedef struct berkas{
    char e[5000];
    char kata[20];
    double skor;
    int jumlah=0;
}cases;
typedef struct urut{
    double skor[2000];
    int panjang[2000];
    char *kata[2000];
}urutan;

int main(){
    char nama_file[2000];
    int k=0;

    urutan hasil;
    cases file;
    urutan word;
    cases karakter[2500];// ini akan diubah

    printf("%20s","======PROJECT BIG CHALLANGE======\n");
    printf("%27s","====KELOMPOK 6====\n");
    getchar();
    system("cls");
    system ("color 07") ;
    printf("Masukkan nama file input (.txt): ");
    scanf("%s",nama_file);
    char *s =strrchr(nama_file,'.');
    if(strcmp(s,".txt") != 0){
        printf("maaf, nama file anda bukan format .txt\n");
        return EXIT_FAILURE;
    }
    
    FILE* inp;
    inp = fopen(nama_file,"r");//program ketika file tidak ditemukan
    if(inp == NULL){
        system ("color 0c") ;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror(nama_file);
       
        return EXIT_FAILURE;
    }
    menu:
    system("cls");
    system ("color 07") ;
    printf("\nPilihan: \n\n");// menampilkan pilihan
    printf("1. Menyimpan file %s ke file binary hasil.bin.\n"
           "2. Menampilkan sebanyak n buah kata dengan skor terbesar ke layar monitor\n"
           "3. Credits\n"
           "4. Keluar\n", nama_file);
    int pilihan;
    printf("masukkan pilihan anda: ");
    scanf("%d",&pilihan);
    system("cls");

    if(pilihan == 1){
        fread(file.e,sizeof(char),sizeof(file.e)/sizeof(char),inp);
        fclose(inp);
        
        for(int i= 0; file.e[i]!='\0' ; i++){// selesai untuk mengubah ke huruf kecil
            if(file.e[i]>='A' && file.e[i]<='Z'){
                file.e[i] += 32;
            } 
        }
        //memisahkan kata dengan strtok
        word.kata[0] = strtok(file.e, " ,.!?\n\'\"123456789()");   
        int i=0;
        while(word.kata[i]!=NULL){
            word.kata[++i] = strtok(NULL, " ,.!?\n\\'\"123456789()");
            if(word.kata[i]== NULL) break;
        }
        int jumlah=0;   
        //program menghitung skor
        for(i=0;word.kata[i]!=NULL;i++){//program untuk panjang char dan memisahkan kata dengan strtok    
            strcpy(karakter[i].kata,word.kata[i]);//salin ke array of char (struct)
            word.skor[i]=0;
            word.panjang[i]=0;
            for(int j=0;karakter[i].kata[j]!='\0';j++){
                word.skor[i]=word.skor[i]+karakter[i].kata[j];
                ++word.panjang[i];//berguna menghitung panjang kata sekaligus    
            }
                jumlah++;//berguna untuk membatasi looping dengan mengetahui semua jumlah kata pada file
        }
    
        for (int step = 1; step < jumlah; step++) {//program mengurutkan skor
            int key = word.skor[step];
            char *key1 = word.kata[step];
            int key2 = word.panjang[step];
            int j = step - 1;
            
            while (key > word.skor[j] && j >= 0) { 
                word.skor[j + 1] = word.skor[j];
                word.kata[j + 1] = word.kata[j];
                word.panjang[j + 1] = word.panjang[j];
                --j;
                }
            word.skor[j + 1] = key;
            word.kata[j + 1] = key1;
            word.panjang[j + 1] = key2;
        }   
        int urut_jum=0;
        int urut_skor=0;
        //program menentukan jumlah kata yang sama dan skor (distinct)
        for (int step = 0; step < jumlah; step++) {
            double key = word.skor[step+1];
            if(key ==word.skor[step] && key!= 0){
                karakter[urut_jum].jumlah++;
            }else if( key != word.skor[step-1] && key != 0) {
                karakter[urut_jum].jumlah++;
                karakter[urut_skor].skor = word.skor[step];
                urut_jum++;
                urut_skor++;    
            }
            else if(word.skor[step]!=0){
                karakter[urut_skor].skor = word.skor[step];
                karakter[urut_jum].jumlah++;
                urut_skor++;
                urut_jum++;  
            }
        }
    
    printf("\nAkan dimasukkan ke file hasil.bin\n");
    int l,m;
    printf("%10s","Loading");
    for(l=0; l<=6; l++){//menampilkan loading (hanya filter)
        for (m=0; m<100000000;m++){
            continue;
        }
        printf(".");
    }
    int k=0;
    inp=fopen("\nhasil.bin","wb");
    for (int i = 0 ; i < urut_skor; i++) {
        fwrite(&karakter[i].skor, sizeof(char), sizeof(karakter[i].skor)/sizeof(char), inp);
        fwrite(&karakter[i].jumlah, sizeof(char), sizeof(karakter[i].jumlah)/sizeof(char), inp);   
            for(int j=0;j<karakter[i].jumlah;j++){
                fwrite(word.kata[k], sizeof(char), sizeof(word.kata[k])/sizeof(char), inp);
                fwrite(&word.panjang[i], sizeof(char), sizeof(word.panjang[i])/sizeof(char), inp);
                k++;
            }
        }
        fclose(inp);
        
        printf("\nselesai memasukkan ke file binary\n");
        printf("\n(Enter)\n");
        getche();
        goto menu;
    }else if(pilihan == 2){
        if(word.panjang[0] == '\0'){
            printf("Masukkan file %s ke file binary terlebih dahulu\n",nama_file);
            system ("color 0c") ;
            getche();
            
            goto menu;
        }
        inp=fopen("hasil.bin","rb");
        rewind(inp);
        int hit;
        do{ 
            if(hit>25){
                system("cls");
                printf("\nMasukkkan input dengan benar!\n");
            }
            printf("\nBatas maksimum adalah 25 jumlah kata yang ditampilkan");
            printf("\nmasukkan jumlah yang ingin ditampilkan:");
            scanf("%d",&hit);
        }while(hit>25);
        k=0;
        for(int i=0;i<hit;i++){
            fread(&karakter[i], sizeof(char), sizeof(karakter[i])/sizeof(char), inp);
            for(int j=0;j<karakter[i].jumlah;j++){
                fread(hasil.kata[k], sizeof(char), sizeof(hasil.kata[k])/sizeof(char), inp);
                fread(&hasil.panjang[i], sizeof(char), sizeof(word.panjang[i])/sizeof(char), inp);
                printf("%.f, %s, %.d\n",karakter[i].skor,word.kata[k],word.panjang[i]);
                k++;
            }   
        }
        getche();
        fclose(inp);
        
        goto menu;
    }
    else if(pilihan ==3){
        system ("color 03");
        printf("%20s","program disusun oleh:\n");
        printf ("1. Muny Safitri 2008107010064\n"
               "2. Rahmi Najla 2008107010014\n");
        getche();
        goto menu;
    }
    else{
        printf("\n..TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI..^^\n");
        system ("color 0a");
        getchar();
       
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
