/*
    Nama    : Moch. Avin
    NRP     : 5025221061
    Kelas   : Struktur Data G
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x) {
    /* Contoh f(x) yang mememuhi adalah f(x) = x */ 
    return x;
}

int main() {
    srand(time(NULL)); 

    int n = 1000000; /* Jumlah titik yang digunakan */
    int count = 0; /* Jumlah titik di bawah kurva */

    for (int i = 0; i < n; i++) {
        double x = (double)rand() / RAND_MAX; /* Titik acak pada sumbu x */
        double y = (double)rand() / RAND_MAX; /* Titik acak pada sumbu y */

        if (y < f(x)) {
            count++;
        }
    }

    double integral = (double)count / n;
    printf("Estimasi integral: %lf\n", integral);

    return 0;
}
