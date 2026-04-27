/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Jevan Abiellie (13224056)
 *   Nama File           : Soal1.c
 *   Deskripsi           : mencari count, sort, dan median dari suatu list
 * 
 */

#include <stdio.h>
#include <stdlib.h>


int *daftar = NULL;
int jumlah = 0;
int median;
float mediun;

void tambah(){
    int bilangan;
    scanf("%d", &bilangan);
    while (bilangan != -1){
        jumlah++;
        daftar = realloc(daftar, jumlah * sizeof(int));
        daftar[jumlah-1] = bilangan;
        scanf("%d", &bilangan);
    }
}

void hitung_median(){
    if (jumlah % 2 == 0){
        int kiri = (jumlah-1)/2;
        int kanan = (jumlah-1)/2 + 1;
        mediun = (daftar[kiri] + daftar[kanan])/2 + 0.5;
    }
    else if (jumlah % 2 == 1){
        int tengah = (jumlah-1)/2;
        median = daftar[tengah];
    }
}

void sort(){
    for (int i = 0; i < jumlah-1; i++){
        for (int j = 0; j < jumlah-1; j++){
            if (daftar[j] > daftar[j+1]){
                int temp = daftar[j+1];
                daftar[j+1] = daftar[j];
                daftar[j] = temp;
            }
        }
    }
}

void output(){
    printf("COUNT %d ", jumlah);
    printf("SORTED ");
    for (int i = 0; i < jumlah-1; i++){
        printf("%d ", daftar[i]);
    }
    printf("%d ", daftar[jumlah-1]);
    if(jumlah % 2 == 1){
        printf("MEDIAN %d", median);
    }
    else if (jumlah %2 == 0){
        printf("MEDIAN %0.1f", mediun);
    }
}

int main(){
    tambah();
    sort();
    hitung_median();
    output();
}
