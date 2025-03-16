
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line); // Reading a single line of input as a string
    stringstream ss(line); // Creating a stringstream object to tokenize the input string

    int a, b, c;
    ss >> a >> b >> c; // Extracting three integers from the input string

    if (a + b >= c) {
        cout << "Yes" << endl; // Printing "Yes" if the condition is true
    } else {
        cout << "No" << endl; // Printing "No" if the condition is false
    }

    return 0;
}

