

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to read an integer from the standard input
int nextInt() {
    // Declare a string variable to store the input
    string input;
    // Read a line of input from the standard input
    getline(cin, input);
    // Create a stringstream object to parse the input
    stringstream ss(input);
    // Declare an integer variable to store the parsed integer
    int i;
    // Parse the input string as an integer
    ss >> i;
    // Return the parsed integer
    return i;
}

int main() {
    // Read the number of apples from the standard input
    int appleNum = nextInt();
    // Read the number of pieces to be made from apples from the standard input
    int pieceNum = nextInt();
    // Calculate the number of pieces made from apples
    int pieceNumMadeFromApples = appleNum * 3;
    // Calculate the total number of pieces
    int totalPiece = pieceNumMadeFromApples + pieceNum;
    // Print the total number of pieces divided by 2
    cout << totalPiece / 2 << endl;
    // End of the code


