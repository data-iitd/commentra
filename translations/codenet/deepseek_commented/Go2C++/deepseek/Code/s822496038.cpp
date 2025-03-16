#include <iostream>
#include <sstream>
#include <string>

// This is the global scanner used to read input from the standard input.
std::istream& sc = std::cin;

// nextInt reads a single word from the standard input, converts it to an integer, and returns it.
// It panics if the conversion fails.
int nextInt() {
    std::string line;
    std::getline(sc, line);
    std::istringstream iss(line);
    int i;
    iss >> i;
    return i;
}

// The main function is the entry point of the program.
int main() {
    // Set the scanner to read words instead of lines.
    // (In C++, we don't need to explicitly set this as std::cin already works this way.)
    
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
