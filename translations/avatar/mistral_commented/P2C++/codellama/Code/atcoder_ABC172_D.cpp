#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
string rs ( ) {
    string s;
    getline ( cin , s );
    return s;
}

// Function to read a single integer from standard input
int ri ( ) {
    string s = rs ( );
    return stoi ( s );
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
vector<int> ri_ ( ) {
    string s = rs ( );
    istringstream iss ( s );
    vector<int> v;
    int i;
    while ( iss >> i ) {
        v.push_back ( i );
    }
    return v;
}

int main ( ) {
    // Read the number of test cases from standard input
    int N = ri ( );

    // Initialize the answer to 0
    int ans = 0;

    // Iterate through all numbers from 1 to N
    for ( int i = 1 ; i <= N ; i++ ) {
        // Calculate the contribution of i to the answer
        // The formula is given by the problem statement
        ans += i * ( N / i ) * ( N / i + 1 ) / 2;
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

