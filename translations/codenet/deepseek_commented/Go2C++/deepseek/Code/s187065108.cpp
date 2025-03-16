#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to read a single word from input
string readWord() {
    string word;
    cin >> word;
    return word;
}

// Function to convert a string to an integer
int readInt() {
    return stoi(readWord());
}

// Main function to execute the program
int main() {
    // Read initial values for r, D, and x
    int r = readInt();
    int D = readInt();
    int x = readInt();
    
    // Loop to calculate and print the values of x for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r * x - D;
        cout << x << endl;
    }
    
    return 0;
}
