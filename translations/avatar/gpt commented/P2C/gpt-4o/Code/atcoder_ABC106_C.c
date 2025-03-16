#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 10000000000000000000ULL
#define EPS 1e-10
#define MOD 1000000007

// Function to read a single integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a string from input
void readString(char *s, int size) {
    scanf("%s", s);
}

// Main function to process the input and return the result
int main() {
    char s[1000001]; // Assuming the maximum length of the string is 1,000,000
    readString(s, sizeof(s));
    int k = readInt();
    int l = 0; // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    while (s[l] == '1') {
        l++;
    }

    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        printf("1\n");
    } else {
        // Otherwise, return the character at position l in the string
        printf("%c\n", s[l]);
    }

    return 0;
}

// <END-OF-CODE>
