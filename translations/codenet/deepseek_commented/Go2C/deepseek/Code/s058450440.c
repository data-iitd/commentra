#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[5] = {0}; // a stores the counts of characters 'M', 'A', 'R', 'C', 'H'
int ans = 0; // ans accumulates the result of the calculations performed by the dfs function

// dfs is a recursive function that calculates the product of 3 elements from array a
void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res; // When no elements are left to multiply, add the result to ans
        return;
    }
    for (int j = i; j < 5; j++) {
        dfs(left - 1, j + 1, res * a[j]); // Recursively call dfs with updated parameters
    }
}

// main function to execute the program
int main() {
    int n;
    scanf("%d", &n); // Read the number of characters
    char dic[6] = {0}; // Dictionary to count occurrences of 'M', 'A', 'R', 'C', 'H'
    int dic_index = 0;

    // Count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c); // Read a character
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            int found = 0;
            for (int j = 0; j < dic_index; j++) {
                if (dic[j] == c) {
                    a[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                dic[dic_index] = c;
                a[dic_index]++;
                dic_index++;
            }
        }
    }

    // Call dfs with parameters 3, 0, and 1
    dfs(3, 0, 1);
    printf("%d\n", ans); // Print the final result

    return 0;
}
