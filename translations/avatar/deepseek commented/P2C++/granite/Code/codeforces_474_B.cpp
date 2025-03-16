

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ( ) {
    vector < int > L;
    // Initialize an empty vector L to store the results.
    string s;
    // Take the first input from the user and store it in the string variable s.
    int r = 1;
    // Initialize the variable r to 1.
    for ( char c : s ) {
        // Iterate over each character in the string s.
        L.insert ( L.end ( ), r, 1 );
        // Multiply the character '1' by the integer value of the character and append the result to the vector L.
        r += 1;
        // Increment r by 1 for the next iteration.
    }
    cin >> s;
    // Take the second input from the user and store it in the string variable s.
    for ( char c : s ) {
        // Iterate over each character in the string s.
        cout << L [ c - '1' ] << endl;
        // For each character, print the element at the index specified by the character minus '1' from the vector L.
    }
    return 0;
}

