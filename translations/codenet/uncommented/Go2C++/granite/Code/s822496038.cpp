
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int appleNum, pieceNum;
    cin >> appleNum >> pieceNum;
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    cout << totalPiece / 2 << endl;
    return 0;
}
// END-OF-CODE