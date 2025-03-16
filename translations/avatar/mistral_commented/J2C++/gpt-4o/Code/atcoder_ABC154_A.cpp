// Importing necessary C++ libraries
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Main method is the entry point of the C++ application
int main() {
    // Creating a string to read the first line of input
    string line;
    
    // Reading the first line of input
    getline(cin, line);
    // Splitting the first line into a vector of strings
    istringstream iss(line);
    vector<string> str;
    string token;
    while (iss >> token) {
        str.push_back(token);
    }

    // Reading the second line of input
    getline(cin, line);
    istringstream iss2(line);
    
    // Reading the first two integers as input
    int a, b;
    iss2 >> a >> b;

    // Reading the third line of input as a string
    string u;
    getline(cin, u);

    // Checking if the first string from the first line matches with the given string 'u'
    if (u == str[0]) {
        // If the condition is true, then print the result as (a-1) and b
        cout << (a - 1) << " " << b << endl;
    } else {
        // If the condition is false, then print the result as a and (b-1)
        cout << a << " " << (b - 1) << endl;
    }

    return 0;
}

// <END-OF-CODE>
