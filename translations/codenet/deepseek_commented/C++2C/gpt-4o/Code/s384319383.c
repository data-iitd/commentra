#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

#define REP(i,n) for(int i=0;i<(n);++i)
#define INF 1e9
#define MOD 1000000007
typedef long long llong;

int main() {
    int n;
    scanf("%d", &n); // Read the number of characters
    int cnt[26] = {0}; // Initialize a count array for occurrences of each letter
<<<<<<< HEAD
    char *s = (char *)malloc(n * sizeof(char)); // Allocate memory for the characters

=======
    char s[n]; // Array to store the characters
>>>>>>> 98c87cb78a (data updated)
    REP(i, n) {
        scanf(" %c", &s[i]); // Read each character
        cnt[s[i] - 'a']++; // Increment the count for the corresponding letter
    }

    llong ans = cnt[0]; // Initialize the answer with the count of the first letter
    for(int i = 1; i < 26; ++i) { // Loop through the counts of other letters
        ans *= cnt[i]; // Multiply the answer by the count of the current letter
        ans %= MOD; // Take the modulo to prevent overflow
    }

    printf("%lld\n", ans - 1); // Output the result, subtracting 1 because we don't count the empty set
<<<<<<< HEAD

    free(s); // Free the allocated memory
=======
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
