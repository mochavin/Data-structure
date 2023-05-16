/*
    Nama    : Moch. Avin
    NRP     : 5025221061
    Kelas   : Struktur Data G
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int all_numbers[40];
    int used_numbers[40] = {0};
    int sets_of_numbers[5][7];

    // Seed the random number generator
    srand(time(NULL));
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 7; j++) {
            int number = rand()%40;
            while(used_numbers[number]) {
                number = rand() % 40;
            }
            used_numbers[number] = 1;
            sets_of_numbers[i][j] = number+1;
        }
    }
    
    // Print the sets of numbers
    for (int i = 0; i < 5; i++) {
        printf("Set %d: ", i + 1);
        for (int j = 0; j < 7; j++) {
            printf("%d ", sets_of_numbers[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
