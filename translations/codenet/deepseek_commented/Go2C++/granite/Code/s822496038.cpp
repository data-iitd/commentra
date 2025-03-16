

#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    int appleNum = std::stoi(line);
    std::getline(std::cin, line);
    int pieceNum = std::stoi(line);
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    std::cout << totalPiece / 2 << std::endl;
    return 0;
}

