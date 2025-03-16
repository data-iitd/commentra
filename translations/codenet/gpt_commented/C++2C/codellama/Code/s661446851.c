/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Define constants and type aliases for convenience
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  printf("%lld\n", x) 
#define   dbg(x)  printf("%s = %lld\n", #x, x) 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 

// Define necessary functions
inline void solve(){
    int n, ans = 0; // Declare variables for input and answer
    scanf("%lld", &n); // Read input value for n
    co(!n); // Output the negation of n (0 if n is non-zero, 1 if n is zero)
}

// Main function
int main()
{
    int n = 1; // Initialize n to 1 (can be modified to read input)
    while (n--) solve(); // Call the solve function n times
    return 0; // Return 0 to indicate successful execution
}

