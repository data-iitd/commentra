#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store counts and the result
int a[4]; // Array to hold counts of specific characters (M, A, R, C, H)
int ans = 0; // Variable to hold the final answer

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
    // If no more characters left to choose, add the result to ans
    if (left == 0) {
        ans += res;
        return;
    }
    // Iterate through the array starting from index i
<<<<<<< HEAD
    for (int j = i; j < 5; j++) {
=======
    for (int j = i; j < 4; j++) {
>>>>>>> 98c87cb78a (data updated)
        // Recursive call to dfs with one less character to choose
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
<<<<<<< HEAD
    // Initialize input variables
    int n;
    int dic[128] = {0}; // Map to count occurrences of specific characters

    // Read the number of characters
    scanf("%d", &n);
=======
    // Read the number of characters
    int n;
    scanf("%d", &n);
    
    // Array to count occurrences of specific characters
    int dic[256] = {0}; // ASCII size for counting characters
>>>>>>> 98c87cb78a (data updated)

    // Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c); // Read a character
        switch (c) {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                dic[(int)c]++; // Increment count for the character if it's one of the specified
                break;
        }
    }

    // Populate the array a with the counts from the dictionary
    int index = 0;
    for (char ch = 'M'; ch <= 'H'; ch++) {
<<<<<<< HEAD
        if (dic[(int)ch] > 0) {
=======
        if (ch == 'M' || ch == 'A' || ch == 'R' || ch == 'C' || ch == 'H') {
>>>>>>> 98c87cb78a (data updated)
            a[index++] = dic[(int)ch];
        }
    }

    // Start the DFS to calculate the product of combinations of 3 characters
    dfs(3, 0, 1);
    // Print the final result
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
