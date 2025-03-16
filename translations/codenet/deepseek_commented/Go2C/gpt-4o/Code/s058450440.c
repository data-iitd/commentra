#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 5

int a[MAX_CHARS]; // Array to store counts of characters 'M', 'A', 'R', 'C', 'H'
int ans = 0; // Variable to accumulate the result

// dfs is a recursive function that calculates the product of 3 elements from array a
void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res; // When no elements are left to multiply, add the result to ans
        return;
    }
    for (int j = i; j < MAX_CHARS; j++) {
        dfs(left - 1, j + 1, res * a[j]); // Recursively call dfs with updated parameters
    }
}

// main function to execute the program
int main() {
    int n;
    scanf("%d", &n); // Read the number of characters
    int dic[256] = {0}; // Array to count occurrences of characters

    // Count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c); // Read a character
        switch (c) {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                dic[(int)c]++; // Increment the count for the character
                break;
        }
    }

    // Append the counts of 'M', 'A', 'R', 'C', 'H' to array a
<<<<<<< HEAD
    a[0] = dic[(int)'M'];
    a[1] = dic[(int)'A'];
    a[2] = dic[(int)'R'];
    a[3] = dic[(int)'C'];
    a[4] = dic[(int)'H'];
=======
    for (char c = 'M'; c <= 'H'; c++) {
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            a[c - 'M'] = dic[(int)c]; // Store the count in array a
        }
    }
>>>>>>> 98c87cb78a (data updated)

    // Call dfs with parameters 3, 0, and 1
    dfs(3, 0, 1);
    printf("%d\n", ans); // Print the final result

    return 0;
}

// <END-OF-CODE>
