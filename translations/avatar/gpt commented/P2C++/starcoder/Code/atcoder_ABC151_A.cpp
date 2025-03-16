#include <iostream>
#include <string>

using namespace std;

// Function to parse input from the user or from a string
void parse_input(string &c) {
    bool debug = false;
    string line;
    getline(cin, line);
    if (line.length() > 0) {
        debug = true;
        c = line.substr(0, 1);
    }
}

// Function to solve the problem by finding the next character in the alphabet
string solve(string c) {
    string a = "abcdefghijklmnopqrstuvwxyz";
    int i = a.find(c);
    return a.substr(i + 1, 1);
}

// Main function to execute the program logic
int main() {
    string c;
    parse_input(c);
    string result = solve(c);
    cout << result << endl;
    return 0;
}

