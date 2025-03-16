#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to read a single integer from input
int inp() {
    int x;
    scanf("%d", &x);
    return x;
}

// Helper function to determine if a specific arrangement is possible
int help(int a, int b, int *l) {
    int tot[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    // Create sublists of length 'a' from the list 'l'
    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }

    // Check if any combination of the sublists sums to 'b'
    for (i = 0; i < a; i++) {
        int sum = 0;
        for (j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return 1; // True
        }
    }
    return 0; // False
}

// Main function to solve the problem
void solve() {
    char x[MAX_LENGTH];
    int s[MAX_LENGTH];
    int tot[MAX_LENGTH][2];
    int count = 0;

    // Read the input string
    scanf("%s", x);
    int length = strlen(x);

    // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for (int i = 0; i < length; i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) { // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s)) { // Use the helper function to check arrangements
                tot[count][0] = 12 / i; // Store valid arrangements
                tot[count][1] = i;
                count++;
            }
        }
    }

    // Print the number of valid arrangements
    printf("%d ", count);

    // Print each valid arrangement in sorted order
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (tot[i][0] > tot[j][0] || (tot[i][0] == tot[j][0] && tot[i][1] > tot[j][1])) {
                int temp0 = tot[i][0], temp1 = tot[i][1];
                tot[i][0] = tot[j][0];
                tot[i][1] = tot[j][1];
                tot[j][0] = temp0;
                tot[j][1] = temp1;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%dx%d ", tot[i][0], tot[i][1]);
    }
    printf("\n"); // Print a newline at the end
}

// Entry point of the program
int main() {
    // Read the number of test cases and solve each case
    int test_cases = inp();
    for (int i = 0; i < test_cases; i++) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
