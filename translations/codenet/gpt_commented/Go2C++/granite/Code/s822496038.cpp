
#include <iostream> // Importing iostream for input/output
#include <string> // Importing string for string manipulation
#include <sstream> // Importing stringstream for string stream operations

using namespace std;

int main() {
    string input; // Declare a string variable to store input
    getline(cin, input); // Read the entire line of input
    
    stringstream ss(input); // Create a stringstream object to tokenize the input
    
    int appleNum, pieceNum; // Declare integer variables to store the input values
    
    ss >> appleNum; // Extract the first integer from the input
    ss >> pieceNum; // Extract the second integer from the input
    
    int pieceNumMadeFromApples = appleNum * 3; // Calculate the number of pieces made from apples
    
    int totalPiece = pieceNumMadeFromApples + pieceNum; // Calculate the total number of pieces
    
    cout << totalPiece / 2 << endl; // Output the total number of complete sets of 2 pieces
    
    return 0;
}

