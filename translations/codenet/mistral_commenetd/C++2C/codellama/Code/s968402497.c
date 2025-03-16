#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library
#include <string.h> // String manipulation library
#include <math.h> // Mathematical functions library
#define mod 1000000007 // Modulus constant
#define mod9 998244353 // Modulus constant
#define ld long double // Long double data type
#define ull unsigned long long // Unsigned long long data type
#define db double // Double precision floating point data type
#define ll long long // Long long integer data type
const db eps=1e-7; // Small epsilon value
//const db pi=acos(-1); // Value of pi constant
const int INF = 0x3f3f3f3f; // Maximum integer constant
const ll inf=0x3f3f3f3f3f3f3f3f; // Maximum long long integer constant
#define rep(i,be,en) for (int i=be;i<=en;i++) // For loop macro for iterating from 'be' to 'en'
#define per(i,be,en) for (int i=en;i>=be;i--) // For loop macro for iterating from 'en' to 'be'
int tc, n, m, fl=0; // Declare variables

int main(){
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

