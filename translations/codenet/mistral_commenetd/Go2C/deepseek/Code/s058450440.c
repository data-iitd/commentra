#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Importing necessary packages

int a[5] = {0};
int ans = 0;

// Defining global variables

void dfs(int left, int i, int res) {
    // Function to perform Depth First Search (DFS) algorithm

    if (left == 0) {
        ans += res;
        return;
    }

    for (int j = i; j < 5; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

// Main function definition
int main() {
    // Initializing an empty map to store the frequency of each character
    int dic[128] = {0};
    int n;
    scanf("%d", &n);

    // Reading strings and updating the map
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[(int)c]++;
        }
    }

    // Converting map values to integers and appending them to the 'a' slice
    int index = 0;
    for (int i = 0; i < 128; i++) {
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
