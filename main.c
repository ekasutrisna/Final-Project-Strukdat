#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define max 200
#define clear system("cls");

// typedef char string[512];

struct tumpukan {
    int atas, harga[max];
    char data[max], tipe[max];
}T;

void awal() {
    T.atas = -1;
}

int kosong() {
    if(T.atas == -1) {
        return 1;
    } else {
        return 0;
    }
}

int penuh() {
    if(T.atas == max - 1) {
        return 1;
    } else {
        return 0;
    }
}

void input(char data[max], int harga, char tipe[max]) {
    if(kosong() == 1) {
        T.atas++;
        T.data[T.atas] = data[max];
        T.harga[T.atas] = harga;
        T.tipe[T.atas] = tipe[max];
        printf("\nData %d Tersimpan\n", T.data[T.atas]);
    } else if(penuh() == 0) {
        T.atas++;
        T.data[T.atas] = data[max];
        T.harga[T.atas] = harga;
        T.tipe[T.atas] = tipe[max];
        printf("\nData %d Tersimpan\n", T.data[T.atas]);
    } else {
        printf("Data Penuh!!");
    }
}

void tampil(int pilih) {
    int tempHrg;
    char tempDta[max];
    char tempTipe[max];

    if(kosong() == 0) {

        if(pilih == 2) {
            for(int i = 0; i <= T.atas; i++) {
                for(int j = 0; j <= T.atas - 1; j++) {
                    if(T.harga[j] > T.harga[j + 1]) {

                        // unruk memindahkan data harga
                        tempHrg = T.harga[j];
                        T.harga[j] = T.harga[j + 1];
                        T.harga[j + 1] = tempHrg;

                        // untuk memindahhkan data merek
                        tempDta[max] = T.data[j];
                        T.data[j] = T.data[j+1];
                        T.data[j + 1] = tempDta[max];

                        //untuk memindahkan data tipe hp
                        tempTipe[max] = T.tipe[j];
                        T.tipe[j] = T.tipe[j + 1];
                        T.tipe[j + 1] = tempTipe[max];
                    }
                }
            }
        } else {
            for(int i = 0; i <= T.atas; i++) {
                for(int j = 0; j <= T.atas - 1; j++) {
                    if(T.harga[j] < T.harga[j + 1]) {

                        // unruk memindahkan data harga
                        tempHrg = T.harga[j];
                        T.harga[j] = T.harga[j + 1];
                        T.harga[j + 1] = tempHrg;

                        // untuk memindahhkan data merek
                        tempDta[max] = T.data[j];
                        T.data[j] = T.data[j+1];
                        T.data[j + 1] = tempDta[max];

                        //untuk memindahkan data tipe hp
                        tempTipe[max] = T.tipe[j];
                        T.tipe[j] = T.tipe[j + 1];
                        T.tipe[j + 1] = tempTipe[max];
                    }
                }
            }
        }

        printf("=======================================\n\n");
        for(int i = 0; i <= T.atas; i++) {
            printf("%d Merek = %s\n", i + 1, T.data[i]);
            printf("Tipe = %s\n", T.tipe[i]);
            printf("Harga = Rp. %d\n", T.harga[i]);
        }

    } else {
        printf("=======================================\n");
        printf("Data Masih Kosong..\n");
        printf("=======================================\n");
    }
}

void bersih() {
    T.atas = -1;
    printf("Data Berhasil Dikosongkan");
}

void cari() {
    if(kosong() == 0) {
        char pencari[max];
        int syrt;
        printf("Masukkan Merek: ");
        gets(pencari);

        for(int i = 0; i <= T.atas; i++) {
            if(T.data[i] == pencari) {
                printf("Data %s DItemukan!!\n");
                printf("Merek   : %s\n", T.data[i]);
                printf("Tipe    : %s\n", T.tipe[i]);
                printf("Harga   : Rp. %d\n", T.harga[i]);
                syrt++;
            }
        }

        if(syrt == 0) {
            printf("\nMerek %s tidak ditemukan", pencari);
        }
    } else {
        printf("Data Masih Kosong...");
    }
}

int main() {
    int pil, harga, jum;
    char data[max], tipe[max];
    awal();

    do {
        puts("Program Pendataan Laptop\n");
        puts("1. Input Data Laptop");
        puts("2. List Laptop Dari Harga Terendah");
        puts("3. List Laptop Dari Harga Tertinggi");
        puts("4. Hapus Data");
        puts("5. Cari Data");
        puts("6. Keluar");
        printf("Masukkan Pilihan: ");
        scanf("%d", &pil);

        switch(pil) {
            case 1:
                printf("Masukkan Jumlah Data: ");
                scanf("%d", &jum);

                for(int i = 0; i < jum; i++) {
                    printf("Data ke %d\n", i + 1);
                    printf("Masukkan Merek  : "); fflush(stdin); gets(data);
                    printf("Masukkan Tipe   : "); fflush(stdin); gets(tipe);
                    printf("Masukkan Harga  : "); fflush(stdin); scanf("%d", &harga);
                    input(data, harga, tipe);
                }
                clear;
                break;

            case 2:
                printf("\nList Laptop dengan harga terendah: \n");
                tampil(pil);
                printf("\nTekan Enter Untuk Melanjutkan...");
                getch();
                clear;
                break;

            case 3:
                printf("\nList Laptop dengan harga terendah: \n");
                tampil(pil);
                printf("\nTekan Enter Untuk Melanjutkan...");
                getch();
                clear;
                break;

            case 4:
                bersih();
                printf("\nTekan Enter Untuk Melanjutkan...");
                getch();
                clear;
                break;

            case 5:
                cari();
                printf("\nTekan Enter Untuk Melanjutkan...");
                getch();
                clear;
                break;

            case 6:
                printf("Anda Telah Keluar...");
                break;

            default:
                printf("Mohpn Masukkan Angka 1-6");
                Sleep(3);
                clear;
        }
    } while(pil != 6);
    getch();
}
