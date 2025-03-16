#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to read an integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    // Read the dimensions of the grid
    int n = readInt();
    // Read the number of banned cells
    int m = readInt();

    // Initialize arrays to keep track of banned rows and columns
    int bannedRows[MAX_SIZE] = {0};
    int bannedCols[MAX_SIZE] = {0};

    // Read each banned cell and mark it in the appropriate array if it's not on the border
    for (int i = 0; i < m; i++) {
        int r = readInt();
        if (r > 1 && r < n) bannedRows[r] = 1;
        int c = readInt();
        if (c > 1 && c < n) bannedCols[c] = 1;
    }

    // Calculate the number of cells that can be reached, accounting for banned rows and columns
    int answer = (n - 2) * 2;
    for (int i = 1; i <= n; i++) {
        if (bannedRows[i]) answer--;
        if (bannedCols[i]) answer--;
    }

    // Adjust the answer if the grid size is odd and the center cell is not banned
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows[mid] && !bannedCols[mid]) {
            answer--;
        }
    }

    // Output the final answer
    printf("%d\n", answer);
    return 0;
}

// <END-OF-CODE>
