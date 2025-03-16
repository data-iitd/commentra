#include <iostream>
#include <sstream>
#include <string>

int main() {
    int appleNum, pieceNum;
    std::cin >> appleNum >> pieceNum;
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    std::cout << totalPiece / 2 << std::endl;
    return 0;
}

