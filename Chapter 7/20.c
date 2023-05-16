/*
    Nama    : Moch. Avin
    NRP     : 5025221061
    Kelas   : Struktur Data G
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_simulations = 50000;

    //seed random
    srand(time(NULL));

    int total_caps = 0;

    //start simulasi
    for (int i = 0; i < num_simulations; i++) {
        int num_caps[] = {40, 10, 10, 40};
        int init_caps = 100;    
        int caps_needed[] = {1, 2, 1, 1};
        int caps_collected[] = {0, 0, 0, 0};
        int caps_total = 0;

        //start merandom hingga terpenuhi "apple"
        while (caps_collected[0] < caps_needed[0] ||
               caps_collected[1] < caps_needed[1] ||
               caps_collected[2] < caps_needed[2] ||
               caps_collected[3] < caps_needed[3]) {
            int cap_index = rand() % init_caps;
            init_caps--;
            int prob_sum = 0;
            for (int j = 0; j < 4; j++) {
                prob_sum += num_caps[j];
                if (cap_index < prob_sum) {
                    caps_collected[j]++;
                    caps_total++;
                    num_caps[j]--;
                    break;
                }
            }
        }
        total_caps += caps_total;
    }

    // Print reratanya
    float average_caps = (float)total_caps / num_simulations;
    printf("Average number of caps per simulation: %.2f\n", average_caps);

    return 0;
}
