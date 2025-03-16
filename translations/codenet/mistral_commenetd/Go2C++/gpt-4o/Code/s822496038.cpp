#include <iostream>
using namespace std;

// Main function
int main() {
    // Initialize variables for the number of apples and pieces
    int appleNum, pieceNum;
    
    // Read the number of apples from the standard input
    cin >> appleNum;
    // Read the number of pieces to be made from apples from the standard input
    cin >> pieceNum;
    
    // Calculate the number of pieces made from apples
    int pieceNumMadeFromApples = appleNum * 3;
    // Calculate the total number of pieces
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print the total number of pieces divided by 2
    cout << totalPiece / 2 << endl;

    // End of the code
    return 0;
}
// <END-OF-CODE>
