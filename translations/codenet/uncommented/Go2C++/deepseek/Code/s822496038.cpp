#include <iostream>
#include <sstream>
#include <string>

int nextInt() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int num;
    if (!(iss >> num)) {
        throw std::runtime_error("Failed to read an integer.");
    }
    return num;
}

int main() {
    int appleNum = nextInt();
    int pieceNum = nextInt();
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    std::cout << totalPiece / 2 << std::endl;
}

