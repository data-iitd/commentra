
#include <iostream>
#include <string>
using namespace std;
// Function to parse input from either user input or a string
void parse_input ( string & c ) {
    bool debug = false;
    string line;
    if (! debug ) {
        cin >> line;
    } else {
        line = "a";
    }
    c = line.substr ( 0, 1 );
}
// Function to solve the problem by finding the next character in the alphabet
string solve ( string c ) {
    string a = "abcdefghijklmnopqrstuvwxyz";
    int i = a.find ( c );
    return a.substr ( i + 1, 1 );
}
// Main function to orchestrate the execution of the program
int main ( ) {
    string c;
    parse_input ( c );
    string result = solve ( c );
    cout << result << endl;
    return 0;
}
