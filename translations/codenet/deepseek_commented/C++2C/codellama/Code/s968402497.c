#include <stdio.h> // For fast input output operations
#include <stdlib.h> // For standard I/O operations
#include <string.h> // For C-style string operations
#include <math.h> // For mathematical functions
#define mod 1000000007 // Define a constant for modular arithmetic
#define mod9 998244353 // Another constant for modular arithmetic
#define ld long double // Define long double for high precision calculations
#define ull unsigned long long // Define unsigned long long for large integers
#define db double // Define double for floating point numbers
#define ll long long // Define long long for large integers
const db eps=1e-7; // Define a small constant for precision in floating point comparisons
#define rep(i,be,en) for (ll i=be;i<=en;i++) // Define a macro for a for loop
#define per(i,be,en) for (int i=en;i>=be;i--) // Define a macro for a reverse for loop
int tc,n,m,fl=0; // Declare variables for input values and a flag

int main(){ // The main function
    scanf("%d%d%d",&tc,&n,&m); // Read three integers from standard input
    if(n>m) swap(n,m); // Swap n and m if n is greater than m
    for(int i=1;i<=m;i++){ // Iterate from 1 to m
        if(i*tc>=n&&i*tc<=m){ // Check if the product of i and tc is between n and m
            printf("OK\n"); // Print "OK" if the condition is met
            fl=1; // Set the flag to true
            break; // Exit the loop
        }
    }
    if(fl==0) puts("NG"); // Print "NG" if the flag is still false after the loop
    return 0; // Return 0 to indicate successful execution
}

