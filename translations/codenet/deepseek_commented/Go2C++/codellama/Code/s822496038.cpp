
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int appleNum, pieceNum, pieceNumMadeFromApples, totalPiece;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> appleNum;
    getline(cin, line);
    ss.clear();
    ss.str(line);
    ss >> pieceNum;
    pieceNumMadeFromApples = appleNum * 3;
    totalPiece = pieceNumMadeFromApples + pieceNum;
    cout << totalPiece / 2 << endl;
    return 0;
}

