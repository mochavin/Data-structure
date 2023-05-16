/*
 * Programmer: Moch. Avin completed: 19 Feb 2023
 * 
 *
 * Menginput data dan mengoutputkan sesuai kategori
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENTS 101
#define MAX_NRP_LENGTH 20
#define MAX_NRP_BUFFER MAX_NRP_LENGTH + 1
#define MAX_CLASSES 6
#define MAX_CLASS_LENGTH 10

typedef struct{
    char class[MAX_CLASS_LENGTH];
    char isiClass[MAX_CLASS_LENGTH][MAX_NRP_BUFFER];
    int jumlah;
} Class;

typedef struct{
    char NRP[MAX_NRP_BUFFER];
    bool class[MAX_CLASSES];
} Student;

int main(){
    Student pupil[MAX_STUDENTS];
    Class kelas[MAX_CLASSES];
    FILE * in = fopen("input.txt", "r");
    FILE * out = fopen("output.txt", "w");

    // Assign semua kelas dengan jumlah 0
    for(int i = 0; i < MAX_CLASSES; i++)
        kelas[i].jumlah = 0;

    // Assign nama kelas
    strcpy(kelas[0].class, "CS20A");
    strcpy(kelas[1].class, "CS21A");
    strcpy(kelas[2].class, "CS29A");
    strcpy(kelas[3].class, "CS30A");
    strcpy(kelas[4].class, "CS35A");
    strcpy(kelas[5].class, "CS36A");

    // Baca semua informasi dari input.txt
    int i = 0;
    while(fscanf(in, "%s", pupil[i].NRP) != EOF){

        for(int j = 0; j < MAX_CLASSES; j++){
            fscanf(in, "%d", &pupil[i].class[j]);

            if(pupil[i].class[j] == 1){
                memcpy(kelas[j].isiClass[kelas[j].jumlah], pupil[i].NRP, MAX_NRP_BUFFER);
                kelas[j].jumlah++;
            }else{
                continue;
            }
        }
        i++;
    }

    fprintf(out, "List of students:\n\n");

    // Tulis semua informasi ke output.txt
    for(int i = 0; i < MAX_CLASSES; i++){
        fprintf(out, "%s\n", kelas[i].class);
        for(int j = 0; j < kelas[i].jumlah; j++){
            fprintf(out, "%d. %s\n", j+1, kelas[i].isiClass[j]);
        }
        fprintf(out, "\n");
    }
    
    printf("Program selesai, silahkan cek file output.txt\n");
    fclose(in);
    fclose(out);
    return 0;
}