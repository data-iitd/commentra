#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Macro definitions for convenience
#define REP(i,n) for(int i=0;i<(n);++i) // Macro for a loop from 0 to n-1
#define ALL(v) (v).begin(),(v).end() // Macro to get the beginning and end of a vector
#define INF 1e9 // Definition of infinity
#define MOD 1e9+7 // Definition of modulus for large number calculations

typedef long long llong; // Type alias for long long

int main(){
    int n; // Variable to store the number of characters
    scanf("%d", &n); // Input the number of characters

    // Initialize a vector to count occurrences of each character (a-z)
    int cnt[26] = {1}; // Start with 1 to account for the multiplication later
    char s[n]; // Vector to store the input characters

    // Read characters and count their occurrences
    REP(i, n){
        scanf("%c", &s[i]); // Input each character
        cnt[s[i] - 'a']++; // Increment the count for the corresponding character
    }

    llong ans = cnt[0]; // Initialize answer with the count of 'a'
    
    // Calculate the product of counts for all characters from 'b' to 'z'
    for(int i = 1; i < 26; ++i){
        ans *= cnt[i]; // Multiply the current answer by the count of the character
        ans %= (int)MOD; // Take modulo to prevent overflow
    }

    // Output the final result, subtracting 1 to exclude the empty product case
    printf("%lld\n", ans - 1); 
    return 0; // End of the program
}

