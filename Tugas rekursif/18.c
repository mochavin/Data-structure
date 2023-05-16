#include <stdio.h>

struct point {
    int x, y;
};

typedef struct point point;

int countPath(point A, struct point B) {
    if (A.x == B.x && A.y == B.y) return 1;
    if (A.x > B.x || A.y > B.y) return 0;
    return countPath((struct point){A.x + 1, A.y}, B) + countPath((struct point){A.x, A.y + 1}, B);
}

int main() {
  struct point A, B;
  printf("Masukkan koordinat A: ");
  scanf("%d%d", &A.x, &A.y);
  printf("Masukkan koordinat B: ");
  scanf("%d%d", &B.x, &B.y);
  int banyakJalur = countPath(A, B);
  printf("Banyak jalur dari A ke B adalah %d", banyakJalur);
}