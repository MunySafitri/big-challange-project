#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>
#define maks 2000
extern int errno;

typedef struct urut{
    double skor;
    int panjang[5];
    int panjang1[10];
    char *kata[10];
    int jumlah=0;
}urutan;
int main(int argc, char* argv[]){ 

    urutan word[maks];

	FILE* data;
	char a[maks];
    char *b[maks];
    int pilihan;
    char nama_file[50];

    //tampilan awal
    printf("%20s","======PROJECT BIG CHALLANGE======\n");
    printf("%27s","====KELOMPOK 6====\n");
    getchar();
    printf("Masukkan nama file input (.txt): ");
    scanf("%s",nama_file);
    //menyeleksi apakah file dimasukkan adalah file dengan format .txt (?)
    char *s =strrchr(nama_file,'.');

    if(strcmp(s,".txt") != 0){//jika format file bukan txt
        printf("maaf, nama file anda bukan format .txt\n");
        return EXIT_FAILURE;
    }

    data=fopen(nama_file,"r");

    if(data == NULL){//jika isi file tidak ada
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror(nama_file);
        return EXIT_FAILURE;
    }
    
    menu:
        rewind(data);

        system("cls");
        //menampilkan pilihan
        printf("\nPilihan: \n\n");// menampilkan pilihan
        printf("1. Menyimpan file .txt ke file binary hasil.bin.\n"
            "2. Menampilkan sebanyak n buah kata dengan skor terbesar ke layar monitor\n"
            "3. Credits\n"
            "4. Keluar\n");
        printf("masukkan pilihan anda: ");
        scanf("%d",&pilihan);
        //program yang menjalankan sesuai pilihan
        if(pilihan ==1){
            rewind(data);
            fread(a,sizeof(char),sizeof(a)/sizeof(char),data);
            fclose(data);
            //memisahkan setiap kata 
            b[0] = strtok(a, " ,.!?\n\t\'\":`~;|+&0123456789()\\/'-@#$%^*<>=_][}{");  
            int i=0;
            while(b[i] !=NULL){
                ++i;
                b[i]  = strtok(NULL, " ,.!?\n\t\'\":`~;|&+0123456789()\\/'-@#$%^*<>=_][}{");
                 if(b[i] == NULL) break;
            }
                // program untuk mengubah ke huruf ke huruf kecil
            for(int j=0; b[j] != NULL ;j++){
                int k=0;
                for(int i= 0; b[j][i]!='\0' ; i++){
                    if(b[j][i]>='A' && b[j][i]<='Z'){
                        b[j][i] += 32;
                    } 
                    k++;
                }
            }
            int jumlah=0;   
            //program menghitung skor
            const char *sk[28]={"Ano","Bonaparte","Coba-coba","Dominan","Egg","Faterjonan",
                                "Golongan","Himalaya","Islam","Jagoloro","Komando","Limonade","Motor",
                                "Notes","Omono","Pertolongan","Qonokaro","Rasohe","Sahara","Ton","Unesco",
                                "Versikaro","Winoto","Xosendero","Yosimono","Zoroaster","kosong"};                        
            char sk_sm[20];
            float skor_sk[maks];
            for(i=0;b[i]!=NULL;i++){//program untuk panjang char dan memisahkan kata dengan strtok    
                skor_sk[i]=0;
                for(int j=0;b[i][j]!='\0';j++){
                    strcpy(sk_sm,sk[b[i][j]-97]);
                    int f =strlen(sk_sm);   
                    for(int k=0;k<f;k++){
                        skor_sk[i]=skor_sk[i]+sk_sm[k];
                    }
                }
                    jumlah++;//berguna untuk membatasi looping dengan mengetahui semua jumlah kata pada file
            }
            for (int step = 1; step < jumlah; step++) {//program mengurutkan skor
                int key = skor_sk[step];
                char *key1 = b[step];
                int j = step - 1;                       
                while (key > skor_sk[j] && j >= 0) { 
                    skor_sk[j+1]  = skor_sk[j] ;
                    b[j + 1] = b[j];
                    --j;
                }
                skor_sk[j+1]  = key;
                b[j + 1] = key1;
            }      

            int urut_jum=0;
            int urut_skor=0;
            int urutan1=0;    
            //program menentukan jumlah kata yang sama,panjang kata dan skor (distinct)
            for (int step = 0; step < jumlah; step++) {    
                double key = skor_sk[step+1];
                if(key == skor_sk[step] && key!= 0){
                    word[urut_jum].jumlah++;
                }else if( key != skor_sk[step-1] && key != 0) {
                    word[urut_jum].jumlah++;
                    word[urut_skor].skor = skor_sk[step];
                    for(int i=0;i<word[urut_jum].jumlah;i++){//mengurutkan panjang kata dan kata
                        word[urut_skor].kata[i]=b[urutan1];
                        word[urut_skor].panjang1[i]=strlen(b[urutan1]);
                        urutan1++;
                    }
                    urut_jum++;
                    urut_skor++;   
                }
                else if(skor_sk[step]!=0){
                    word[urut_skor].skor = skor_sk[step];
                    word[urut_jum].jumlah++;
                    urut_skor++;
                    urut_jum++;  
                }
            }
            data=fopen("\nhasil.bin","wb");
            printf("Loading");
            for(int l=0; l<=6; l++){
                for(int i=0;i<urut_skor;i++){
                    fwrite(&word[i].skor, sizeof(double), sizeof(word[i].skor)/sizeof(double), data);
                    fwrite(&word[i].jumlah, sizeof(int), sizeof(word[i].jumlah)/sizeof(int), data); 
                    for(int j=0;j<word[i].jumlah;j++){
                        fwrite(&word[i].panjang1[j], sizeof(int), sizeof(word[i].panjang1[j])/sizeof(int), data); 
                        fwrite(word[i].kata[j], sizeof(char), sizeof(word[i].kata[j])/sizeof(char), data);
                    }
                }
                for (int m=0; m<100000000;m++){//filter aja
                    continue;
                }
                printf(".");
            }
            printf("\nData sudah diconvert ke binary di hasil.bin\n");
            getchar();
            getchar();
            fclose(data);
            goto menu;
        }else if(pilihan ==2){
            system("cls");
            if(word[0].skor == '\0'){
                printf("\nAnda belum memasukkan file ke dalam binary\nMasukkan terlebih dahulu\n");
                getchar();
                getchar();
                goto menu;
            }
            rewind(data);
            int hit;
            do{ 
                system("cls");
                if(hit>25){
                    printf("\nMasukkkan input dengan benar!\n");
                }   
                printf("\nBatas maksimum adalah 25 jumlah kata yang ditampilkan");
                printf("\nmasukkan jumlah yang ingin ditampilkan:");
                scanf("%d",&hit);
            }while(hit>25);
                data=fopen("hasil.bin","rb");       
                fread(&word[maks],sizeof(char), sizeof(struct urut), data);
                    int stop=0;
                    for(int i=0;i<25;i++){
                        for(int j=0;j<word[i].jumlah;j++){
                            printf("%.f ",word[i].skor);
                            printf("%s %d \n",word[i].kata[j],word[i].panjang1[j]);
                            stop++;
                            if(stop==hit){ 
                                break;
                            }
                        }
                        if(stop==hit){
                             break;
                        } 
                    }
                    fclose(data);
                    getchar();
                    getchar();
                    goto menu;

            }else if(pilihan == 3){

                system("cls");
                printf("%20s","program disusun oleh:\n");
                printf ("1. Muny Safitri 2008107010064\n"
                        "2. Rahmi Najla 2008107010014\n");
                printf ("Semoga 100 :D\n");
                getchar();
                getchar();
                goto menu;

            }else{
                printf("\n..TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI..^^\n");
                getchar();
                return EXIT_FAILURE;
            }
    return 0;
}
