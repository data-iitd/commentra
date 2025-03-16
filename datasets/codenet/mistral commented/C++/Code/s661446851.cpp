/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <functional>
// Header files for standard libraries and custom libraries

#define   mod  998244353 // Define a constant for modulo arithmetic
#define   int  long long  // Define int as long long for large input
#define   ld   long double // Define ld for long double precision
#define   pb   push_back // Define pb for pushing back elements in a vector
#define   vi   vector<int>  // Define vi as a vector of integers
#define   co(x)  cout << x << '\n' // Define co for printing output
#define   dbg(x)  cerr << #x << " = " << x << '\n' // Define dbg for debugging purpose
#define   bitcount(x)  (int)__builtin_popcount(x) // Define bitcount for counting set bits
#define   sz(x)  (int)x.size() // Define sz for getting size of a container
#define   all(a) a.begin(),a.end() // Define all for getting iterator to the beginning and end of a container
#define   ff   first // Define ff for getting first element of a pair
#define   ss   second // Define ss for getting second element of a pair
#define   pii  pair<int,int> // Define pii as a pair of integers
#define   lcm(a,b) (a*b)/__gcd(a,b) // Define lcm for finding least common multiple of two numbers
// Define constants, macros, and aliases

using namespace std; // Use standard library

inline void solve(){ // Function declaration for solving the problem
    int n,ans = 0; // Declare variables for taking input and storing answer
    cin>>n; // Read input for n
    co(!n); // Print output if n is not positive
}

signed main()
{ // Main function declaration
    int n=1; // Initialize a variable for number of test cases
    while (n--) solve(); // Call the solve function for each test case
    return 0; // Return 0 to indicate successful execution
}