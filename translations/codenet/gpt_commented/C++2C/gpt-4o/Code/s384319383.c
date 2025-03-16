#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

#define REP(i,n) for(int i=0;i<(n);++i) // Macro for a loop from 0 to n-1
#define INF 1000000000 // Definition of infinity
#define MOD 1000000007 // Definition of modulus for large number calculations

typedef long long llong; // Type alias for long long

int main() {
    int n; // Variable to store the number of characters
    scanf("%d", &n); // Input the number of characters

    // Initialize an array to count occurrences of each character (a-z)
    int cnt[26] = {0}; // Start with 0 to count occurrences
<<<<<<< HEAD
    char *s = (char *)malloc(n * sizeof(char)); // Allocate memory for the input characters
=======
    char s[n]; // Array to store the input characters
>>>>>>> 98c87cb78a (data updated)

    // Read characters and count their occurrences
    REP(i, n) {
        scanf(" %c", &s[i]); // Input each character
        cnt[s[i] - 'a']++; // Increment the count for the corresponding character
    }

    llong ans = cnt[0]; // Initialize answer with the count of 'a'
    
    // Calculate the product of counts for all characters from 'b' to 'z'
    for(int i = 1; i < 26; ++i) {
        ans *= cnt[i]; // Multiply the current answer by the count of the character
        ans %= MOD; // Take modulo to prevent overflow
    }

    // Output the final result, subtracting 1 to exclude the empty product case
    printf("%lld\n", ans - 1); 
<<<<<<< HEAD

    free(s); // Free the allocated memory
=======
>>>>>>> 98c87cb78a (data updated)
    return 0; // End of the program
}

// <END-OF-CODE>
