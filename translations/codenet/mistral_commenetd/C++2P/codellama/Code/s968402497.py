#pragma GCC optimize(2) // Enable some optimizations
#include <cstdio> // Standard input/output library
#include <iostream> // Standard input/output stream library
#include <algorithm> // Standard algorithm library
#include <cstring> // String manipulation library
#include <queue> // Priority queue data structure
#include <map> // Associative array data structure
#include <set> // Set data structure
#include <vector> // Dynamic array data structure
#include <stack> // Stack data structure
#include <cmath> // Mathematical functions library
#include <utility> // Pair data structure
#include <sstream> // String stream library
#include <string> // String manipulation library
#define mod 1000000007 // Modulus constant
#define mod9 998244353 // Modulus constant
#define ld long double // Long double data type
#define ull unsigned long long // Unsigned long long data type
#define db double // Double precision floating point data type
#define ll long long // Long long integer data type
const db eps=1e-7; // Small epsilon value
#define rep(i,be,en) for (int i=be;i<=en;i++) // For loop macro for iterating from 'be' to 'en'
#define per(i,be,en) for (int i=en;i>=be;i--) // For loop macro for iterating from 'en' to 'be'
using namespace std; // Standard library namespace
const int N=1e5+7; // Maximum number of elements in the input

int tc, n, m, fl=0; // Declare variables

int main(){
    #pragma GCC optimize(2) // Enable some optimizations
    // Read input
    scanf("%d%d%d",&tc,&n,&m);
    // Check if 'n' is greater than 'm' and swap them if necessary
    if(n>m) swap(n,m);
    // Iterate through each possible value of 'i' from 1 to 'm'
    for(int i=1;i<=m;i++){
        // Check if 'i' multiplied by 'tc' is within the range of 'n' to 'm'
        if(i*tc>=n&&i*tc<=m){
            // If so, print "OK" and set the flag 'fl' to 1
            printf("OK\n");
            fl=1;
            // Break out of the loop since we have found the answer
            break;
        }
    }
    // If the flag 'fl' is still 0, print "NG"
    if(fl==0) puts("NG");
    // Return 0 to indicate successful execution
    return 0;
}

