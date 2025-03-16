#include <iostream>  // Include the iostream library for input and output
#include <vector>    // Include the vector library for using vectors (not used in this code)
#include <string>    // Include the string library for using strings (not used in this code)
#include <algorithm> // Include the algorithm library for algorithms (not used in this code)
#include <cstdio>    // Include the cstdio library for C-style input and output (not used in this code)
#include <cstring>   // Include the cstring library for C-style string manipulation (not used in this code)
#include <cmath>     // Include the cmath library for mathematical functions (not used in this code)
using namespace std; // Use the standard namespace
using ll = long long; // Define 'll' as a shorthand for 'long long' type

int main() {
    // Declare variables to hold input values
    int a, b, c, d, e, k;

    // Read six integers from standard input
    cin >> a >> b >> c >> d >> e >> k;

    // Check if the difference between e and a is less than or equal to k
    // If true, print "Yay!", otherwise print ":("
    cout << (e - a <= k ? "Yay!" : ":(") << endl;

    return 0; // Return 0 to indicate successful execution of the program
}
