
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the number of apples.
    int appleNum;
    cin >> appleNum;
    
    // Read the number of pieces.
    int pieceNum;
    cin >> pieceNum;
    
    // Calculate the total pieces that can be made from the apples.
    int pieceNumMadeFromApples = appleNum * 3;
    
    // Add the given pieces to the pieces made from apples.
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print half of the total pieces.
    cout << totalPiece / 2 << endl;
}

