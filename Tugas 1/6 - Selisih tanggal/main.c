/*
 * Programmer: Moch. Avin completed: 19 Feb 2023
 * 
 *
 * Menghitung selisih tanggal
 */
 

#include <stdio.h>

typedef struct {
    int d, m, y;
} Date;

const int banyakHari[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int hitungKabisat(Date d);
int selisihHari(Date, Date);

int main(){
    Date a, b;
    printf("Masukkan tanggal pertama (dd mm yyyy): ");
    scanf("%d %d %d", &a.d, &a.m, &a.y);
    printf("Masukkan tanggal kedua (dd mm yyyy): ");
    scanf("%d %d %d", &b.d, &b.m, &b.y);
    printf("Selisih hari: %d\n", selisihHari(a, b));
}

int hitungKabisat(Date d) {
    int years = d.y;

    if (d.m <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}

int selisihHari(Date a, Date b) {
    // ambil banyak hari dari setahun dan harinya
    int n = a.y * 365 + a.d;
    int m = b.y * 365 + b.d;
    
    // ambil banyak hari dari bulannya dikurang 1
    for(int i = 0; i < a.m-1; i++)
        n += banyakHari[i];
    for(int i = 0; i < b.m-1; i++)
        m += banyakHari[i];

    // tambahkan banyak hari kabisat
    n += hitungKabisat(a);
    m += hitungKabisat(b);

    return m - n;

}