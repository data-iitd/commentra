#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 5
#define MAX_INPUT 100

// Global variables
int a[MAX_CHAR];
int ans = 0;

// Function to perform Depth First Search (DFS) algorithm
void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }

    for (int j = i; j < MAX_CHAR; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

// Main function definition
int main() {
    int n;
    int dic[256] = {0}; // Frequency map for characters

    // Reading the number of test cases
    scanf("%d", &n);

    // Reading strings and updating the frequency map
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c); // Read a single character
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[(int)c]++;
        }
    }

    // Converting map values to integers and storing them in the 'a' array
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (dic[i] > 0) {
            a[index++] = dic[i];
        }
    }

    // Calling the 'dfs' function with initial arguments
    dfs(3, 0, 1);

    // Printing the answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
