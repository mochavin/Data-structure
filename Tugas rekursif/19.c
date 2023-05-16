#include <stdio.h>
#include <stdbool.h>

#define N 8
int board[N][N];

// fungsi untuk menampilkan solusi queen problem
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// fungsi untuk memeriksa apakah penempatan ratu pada suatu posisi aman atau tidak
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // cek kolom pada baris yang sama
    for (i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }

    // cek diagonal atas kiri
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // cek diagonal bawah kiri
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) return false;
    }

    return true;
}

bool solve(int board[N][N], int col) {
    // base case: semua ratu telah ditempatkan
    if (col == N) return true;

    // coba untuk menempatkan satu ratu pada setiap baris
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // menempatkan ratu pada posisi (i, col)
            board[i][col] = 1;

            // menempatkan ratu berikutnya secara rekursif
            if (solve(board, col+1)) return true;

            // jika tidak berhasil, hapus penempatan ratu dan coba dengan baris berikutnya
            board[i][col] = 0;
        }
    }

    return false;
}

int main() {

    if (solve(board, 0) == false) printf("Tidak ada solusi yang memenuhi\n");
    else printSolution(board);

    return 0;
}
