#include <stdio.h>
#include <stdlib.h>

int main() {
    int appleNum, pieceNum, pieceNumMadeFromApples, totalPiece;
    scanf("%d %d", &appleNum, &pieceNum);
    pieceNumMadeFromApples = appleNum * 3;
    totalPiece = pieceNumMadeFromApples + pieceNum;
    printf("%d\n", totalPiece / 2);
    return 0;
}
