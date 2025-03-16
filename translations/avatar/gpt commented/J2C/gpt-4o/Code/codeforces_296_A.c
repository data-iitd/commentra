#include <stdio.h>

#define MAX_INDEX 1001

void solve() {
    int n;
    scanf("%d", &n); // Read the number of elements

    int array[MAX_INDEX] = {0}; // Initialize an array to count occurrences of each index

    // Read n integers and count their occurrences
    for (int i = 0; i < n; i++) {
        int index;
        scanf("%d", &index);
        array[index]++;
    }

    // Determine the maximum count of any index
    int countMax = -1;
    for (int i = 1; i < MAX_INDEX; i++) {
        if (countMax < array[i]) {
            countMax = array[i];
        }
    }

    // Check if the maximum count is within allowed limits based on n being even or odd
    if (n % 2 == 0) {
        // For even n, check if the maximum count is less than or equal to n/2
        if (countMax <= n / 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        // For odd n, check if the maximum count is less than or equal to n/2 + 1
        if (countMax <= n / 2 + 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    solve(); // Call the solve function to process the input and produce output
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
