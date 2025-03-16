#include <stdio.h>

#define REP(i,n) for(int i=0;i<(n);++i) // Define a macro for repetition
#define INF 1e9 // Define a constant for large number
#define MOD 1000000007 // Define a constant for modulo operation
typedef long long llong; // Define a type alias for long long

int main() {
    int n; // Declare an integer variable 'n' to store the number of strings
    scanf("%d", &n); // Read the number of strings from the standard input

    // Declare an array: 'cnt' to store the count of each character
    int cnt[26] = {0}; // Initialize the count array to 0
    char s[n]; // Declare an array to store the strings

    // Read the strings from the standard input and update the count array accordingly
    REP(i, n) {
        scanf(" %c", &s[i]); // Read a character from the standard input and store it in the 's' array
        cnt[s[i] - 'a']++; // Increment the count of the character in the 'cnt' array
    }

    // Calculate the answer using the count array
    llong ans = 1; // Initialize the answer to 1
    for(int i = 0; i < 26; ++i) { // Iterate through all the characters from 'a' to 'z'
        ans *= (cnt[i] + 1); // Multiply the answer with the count of the current character + 1
    }

    // Calculate the final answer by subtracting 1 from the initial answer
    ans--;

    // Print the final answer to the standard output
    printf("%lld\n", ans);

    return 0; // Indicate the successful termination of the program
}

// <END-OF-CODE>
