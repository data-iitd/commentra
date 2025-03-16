
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    int appleNum, pieceNum;
    cin >> appleNum >> pieceNum;
    int pieceNumMadeFromApples = appleNum * 3;
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    cout << totalPiece / 2 << endl;
    return 0;
}

