
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int appleNum, pieceNum, pieceNumMadeFromApples, totalPiece;
    string input;
    getline(cin, input);
    stringstream ss(input);
    ss >> appleNum;
    ss >> pieceNum;
    pieceNumMadeFromApples = appleNum * 3;
    totalPiece = pieceNumMadeFromApples + pieceNum;
    cout << totalPiece / 2 << endl;
    return 0;
}

