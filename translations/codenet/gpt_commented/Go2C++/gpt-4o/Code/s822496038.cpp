#include <iostream> // For input and output
using namespace std;

// Function to read the next integer from input
int nextInt() {
    int i;
    cin >> i; // Read the next integer from input
    return i; // Return the read integer
}

int main() {
    // Read the number of apples and pieces from input
    int appleNum = nextInt(); 
    int pieceNum = nextInt(); 
    
    // Calculate the number of pieces made from apples (3 pieces per apple)
    int pieceNumMadeFromApples = appleNum * 3;
    
    // Calculate the total number of pieces (pieces from apples + existing pieces)
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Output the total number of complete sets of 2 pieces
    cout << totalPiece / 2 << endl;

    return 0; // Indicate successful completion
}

// <END-OF-CODE>
