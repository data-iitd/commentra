#include <iostream>
#include <string>

// This is the global input stream used to read input from the standard input.
std::istream& input = std::cin;

// nextInt reads a single word from the standard input, converts it to an integer, and returns it.
// It throws an exception if the conversion fails.
int nextInt() {
    int i;
    if (!(input >> i)) {
        throw std::runtime_error("Invalid input");
    }
    return i;
}

// The main function is the entry point of the program.
int main() {
    // Read the number of apples.
    int appleNum = nextInt();
    
    // Read the number of pieces.
    int pieceNum = nextInt();
    
    // Calculate the total pieces that can be made from the apples.
    int pieceNumMadeFromApples = appleNum * 3;
    
    // Add the given pieces to the pieces made from apples.
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    
    // Print half of the total pieces.
    std::cout << totalPiece / 2 << std::endl;

    return 0;
}

// <END-OF-CODE>
