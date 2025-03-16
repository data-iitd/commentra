
#####
# Code
#####

# Importing necessary libraries
#include <bits/stdc++.h>

// Setting recursion limit for the program
#define MAX_RECURSION_LIMIT 100000

// Defining constants
const int inf = 100000000;
const long long eps = 1000000000LL;
const long double mod = 1000000007LL;

// Function to read a list of integers from standard input
std::vector<int> LI( ) { std::vector<int> a; int x; while (scanf("%d", &x) == 1) a.pb(x); return a; }

// Function to read a list of integers from standard input, subtracting 1 from each element
std::vector<int> LI_( ) { std::vector<int> a; int x; while (scanf("%d", &x) == 1) a.pb(x - 1); return a; }

// Function to read a list of floats from standard input
std::vector<double> LF( ) { std::vector<double> a; double x; while (scanf("%lf", &x) == 1) a.pb(x); return a; }

// Function to read a single line from standard input as a list of strings
std::vector<std::string> LS( ) { std::vector<std::string> a; std::string s; while (getline(cin, s)) a.pb(s); return a; }

// Function to read a single integer from standard input
int I( ) { int x; scanf("%d", &x); return x; }

// Function to read a single float from standard input
double F( ) { double x; scanf("%lf", &x); return x; }

// Function to read a single string from standard input
std::string S( ) { std::string s; scanf("%s", &s); return s; }

// Function to print a string with a newline character at the end
void pf(std::string s) { printf("%s\n", s.c_str()); }

// Main function
int main( ) {
    // Reading input string and number of occurrences of '1' required
    std::string s = S( );
    int k = I( );

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    for (char c : s) {
        if (c!= '1') {
            // If the length of the substring is greater than or equal to the required number of occurrences, return 1
            if (l >= k) {
                return 1;
            }
            break;
        }
        l += 1;
    }

    // If the length of the substring is less than the required number of occurrences, return the character after the substring
    return s[l];
}

// Calling the main function and printing the result
printf("%d\n", main());

Translate the above Python code to Java and end with comment "