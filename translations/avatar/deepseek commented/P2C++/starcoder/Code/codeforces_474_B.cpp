
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ( ) {
    vector <int> L;
    string input;
    getline ( cin, input );
    // Take the first input from the user.
    int r = 1;
    // Initialize the variable r to 1.
    for ( int i = 0; i < input.size ( ); i++ ) {
        // Iterate over each character in the input.
        L.push_back ( r );
        // Append the result to the list L.
        r += 1;
        // Increment r by 1 for the next iteration.
    }
    getline ( cin, input );
    // Take the second input from the user.
    for ( int i = 0; i < input.size ( ); i++ ) {
        // Iterate over each character in the input.
        cout << L [ stoi ( input.substr ( i, 1 ) ) - 1 ] << endl;
        // For each character, print the element at the index specified by the integer value of the character minus one from the list L.
    }
    return 0;
}
