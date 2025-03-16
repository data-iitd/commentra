#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to read an integer as input
int readInt() {
    int num;
    cin >> num;
    return num;
}

// Function to read a string as input
string readString() {
    string str;
    cin >> str;
    return str;
}

// Function to read an array of integers as input
vector<int> readInts(int n) {
    vector<int> sl(n);
    for (int i = 0; i < n; ++i) {
        sl[i] = readInt();
    }
    return sl;
}

// Function to read an array of strings as input
vector<string> readStrings(int n) {
    vector<string> sl(n);
    for (int i = 0; i < n; ++i) {
        sl[i] = readString();
    }
    return sl;
}

// Main function to execute the program
int main() {
    // Read the first three integers as input
    int r = readInt();
    int D = readInt();
    int x = readInt();

    // Iterate through a loop 10 times
    for (int i = 1; i <= 10; i++) {
        // Calculate the new value of x using the given formula
        x = r * x - D;

        // Print the value of x to the console
        cout << x << endl;
    }

    return 0;
}
