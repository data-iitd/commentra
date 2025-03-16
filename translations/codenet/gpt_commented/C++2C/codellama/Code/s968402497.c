#include <stdio.h> // For standard input and output functions
#include <stdlib.h> // For standard library functions
#include <string.h> // For string manipulation functions
#include <math.h> // For mathematical functions
#define mod 1000000007 // Define a large prime number for modulo operations
#define mod9 998244353 // Another large prime number for modulo operations
#define ld long double // Define long double type
#define ull unsigned long long // Define unsigned long long type
#define db double // Define double type
#define ll long long // Define long long type
const db eps=1e-7; // Define a small epsilon value for floating-point comparisons
//const db pi=acos(-1); // Uncomment to define pi
const int INF = 0x3f3f3f3f; // Define a large integer value for infinity
const ll inf=0x3f3f3f3f3f3f3f3f; // Define a large long long value for infinity
#define rep(i,be,en) for (ll i=be;i<=en;i++) // Macro for a forward loop
#define per(i,be,en) for (int i=en;i>=be;i--) // Macro for a backward loop
int tc,n,m,fl=0; // Declare variables for test cases, two integers, and a flag

int main(){
    // Read the number of test cases, and two integers n and m
    scanf("%d%d%d",&tc,&n,&m);
    
    // Ensure n is the smaller of the two integers
    if(n>m) swap(n,m);
    
    // Loop through the range from 1 to m
    for(int i=1;i<=m;i++){
        // Check if the current value multiplied by tc is within the range [n, m]
        if(i*tc>=n&&i*tc<=m){
            printf("OK\n"); // Print "OK" if the condition is satisfied
            fl=1; // Set the flag to indicate success
            break; // Exit the loop as we found a valid case
        }
    }
    
    // If no valid case was found, print "NG"
    if(fl==0) puts("NG");
    
    return 0; // Return 0 to indicate successful execution
}

