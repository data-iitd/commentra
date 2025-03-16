#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to check if an integer is in the array
int contains(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Arrays to keep track of banned rows and columns
    int bannedRows[MAX_SIZE], bannedCols[MAX_SIZE];
    int bannedRowsCount = 0, bannedColsCount = 0;

    // Read the banned rows and columns
    for (int i = 0; i < m; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        // Add to bannedRows if the row is within valid range
        if (r > 1 && r < n) {
            bannedRows[bannedRowsCount++] = r;
        }
        // Add to bannedCols if the column is within valid range
        if (c > 1 && c < n) {
            bannedCols[bannedColsCount++] = c;
        }
    }

    // Calculate the initial answer based on the grid size
    int answer = (n - 2) * 2;
    // Subtract the number of banned rows and columns from the answer
    answer -= bannedRowsCount;
    answer -= bannedColsCount;

    // If n is odd, check the middle row and column
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        // If the middle row and column are not banned, decrement the answer
        if (!contains(bannedRows, bannedRowsCount, mid) && !contains(bannedCols, bannedColsCount, mid)) {
            answer--;
        }
    }

    // Output the final answer
    printf("%d\n", answer);
    return 0;
}

// <END-OF-CODE>
