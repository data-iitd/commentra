
#####
# Code
#####

# Include necessary libraries
#include <bits/stdc++.h>

// Define constants
const int inf = 1001001001;
const int mod = 100000007;
const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

// Define a function to read an integer from standard input
int I( ) {
    int n;
    scanf("%d", &n);
    return n;
}

// Define a function to read a string from standard input
std::string S( ) {
    std::string s;
    std::cin >> s;
    return s;
}

// Main function
int main( ) {
    // Read input values
    int a = I(), b = I(), c = I(), d = I();

    // Calculate the maximum product of pairs of numbers
    int result = std::max({ a*c, b*d, a*d, b*c });

    // Print the result
    printf("%d\n", result);

    return 0;
}

