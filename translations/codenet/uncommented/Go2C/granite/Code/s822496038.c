
#include <stdio.h>
#include <stdlib.h>

int main() {
    int appleNum = 0;
    int pieceNum = 0;
    int pieceNumMadeFromApples = 0;
    int totalPiece = 0;

    scanf("%d", &appleNum);
    scanf("%d", &pieceNum);
    pieceNumMadeFromApples = appleNum * 3;
    totalPiece = pieceNumMadeFromApples + pieceNum;
    printf("%d\n", totalPiece / 2);

    return 0;
}
