#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store counts and the result
int a[5] = {0}; // Array to hold counts of specific characters
int ans = 0; // Variable to hold the final answer

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
    // If no more characters left to choose, add the result to ans
    if (left == 0) {
        ans += res;
        return;
    }
    // Iterate through the array starting from index i
    for (int j = i; j < 5; j++) {
        // Recursive call to dfs with one less character to choose
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of characters
    getchar(); // Consume the newline character after the number

    // Map to count occurrences of specific characters
    int dic[128] = {0};

    // Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c = getchar(); // Read the character
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[(int)c]++; // Increment count for the character if it's one of the specified
        }
    }

    // Populate the array a with the counts from the dictionary
    int index = 0;
    for (int i = 0; i < 128; i++) {
        if (dic[i] > 0) {
            a[index++] = dic[i];
        }
    }

    // Start the DFS to calculate the product of combinations of 3 characters
    dfs(3, 0, 1);
    // Print the final result
    printf("%d\n", ans);

    return 0;
}
