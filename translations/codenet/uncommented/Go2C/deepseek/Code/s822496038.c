#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    int appleNum = nextInt();
    int pieceNum = nextInt();
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    printf("%d\n", totalPiece / 2);
    return 0;
}
