/*
    Nama    : Moch. Avin
    NRP     : 5025221061
    Kelas   : Struktur Data G
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    int dadu1 = rand() % 6 + 1;
    int dadu2 = rand() % 6 + 1;
    return dadu1 + dadu2;
}

int draw_card() {
    int kartu = rand() % 13 + 1;
    return kartu;
}

int main() {
    srand(time(NULL));  // menentukan seed generator bilangan acak berdasarkan waktu saat ini

    int num_games = 20;
    int total_winnings = 0;

    for (int i = 0; i < num_games; i++) {
        int dice_sum = roll_dice();
        int winnings = 0;
        if (dice_sum % 2 == 0) {
            // pemain kalah, asumsi dihitung tidak rugi, jika dihitung rugi maka harus total_winning harus dikurangi 5
        } else {
            int card_value = draw_card();
            if (card_value == 1 || card_value == 3 || card_value == 5 || card_value == 7 || card_value == 9) {
                winnings = card_value + 5;
            } else {
            // pemain kalah, asumsi dihitung tidak rugi, jika dihitung rugi maka harus total_winning harus dikurangi 5
            }
        }
        total_winnings += winnings;
    }

    double avg_winnings = (double) total_winnings / num_games;
    printf("Rata-rata jumlah kemenangan per game: $%.2f\n", avg_winnings);

    return 0;
}
