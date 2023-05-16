/*
 * Programmer: Moch. Avin completed: 19 Feb 2023
 * 
 *
 * Sorting data dari yang terbesar tanpa qsort
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NAME_BUFFER MAX_NAME_LEN + 1
#define MAX_ATHLETES 100

typedef struct {
    char name[MAX_NAME_BUFFER];
    double distance;
} Athlete;

typedef struct {
    Athlete athletes[MAX_ATHLETES];
    int num_athletes;
} AthleteList;

// fungsi untuk sorting
void urutData(AthleteList *athlete_list){
    int i, j;
    Athlete temp;
    for(i=0; i<MAX_ATHLETES; i++){
        for(j=0; j<MAX_ATHLETES; j++){
            if(athlete_list->athletes[i].distance > athlete_list->athletes[j].distance){
                temp = athlete_list->athletes[i];
                athlete_list->athletes[i] = athlete_list->athletes[j];
                athlete_list->athletes[j] = temp;
            }
        }
    }
}

int main() {
    // buka file 
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    // buat list athlete
    AthleteList athlete_list;
    athlete_list.num_athletes = 0;

    // baca file input
    char sTemp[MAX_NAME_BUFFER]; // untuk nampung string sementara
    double dTemp; // untuk nampung distance sementara
    while (fscanf(input, "%*[^\"]\"%[^\"]\"", sTemp) != EOF) {
        fscanf(input, "%lf", &dTemp);
        // cek apakah nama sudah ada di list
        int found = 0;
        for(int i = 0; i < athlete_list.num_athletes; i++) {
            if (strcmp(sTemp, athlete_list.athletes[i].name) == 0) {
                // jika sudah ada, cek apakah distance yang baru lebih besar
                if(athlete_list.athletes[i].distance < dTemp) {
                    athlete_list.athletes[i].distance = dTemp;
                }
                found = 1;
                break;
            }
        }
        if(!found) {
            // jika belum ada, tambahkan ke list
            strcpy(athlete_list.athletes[athlete_list.num_athletes].name, sTemp);
            athlete_list.athletes[athlete_list.num_athletes].distance = dTemp;
            athlete_list.num_athletes++;
        }
    }

    fclose(input);

    // sort dari yang terbesar
    urutData(&athlete_list);

    // Print dari yang terbesar
    printf("ditemukan %d athlete:\n\n", athlete_list.num_athletes);
    for (int i = 0; i < athlete_list.num_athletes; i++) {
        printf("%s: %.2f\n", athlete_list.athletes[i].name, athlete_list.athletes[i].distance);
        fprintf(output, "%s: %.2f\n", athlete_list.athletes[i].name, athlete_list.athletes[i].distance);

    }

    return 0;
}
