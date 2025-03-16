#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define MAX_LENGTH 8000
#define MAX_COORD 20000
#define OFFSET 10000

bool dpx[MAX_LENGTH][MAX_COORD];
bool dpy[MAX_LENGTH][MAX_COORD];

int main() {
    char S[20000]; // Input string
    int x, y; // Target coordinates

    // Read the input string
    scanf("%s", S);
    // Read the target coordinates
    scanf("%d %d", &x, &y);

    int F[10000]; // Array to hold the lengths of consecutive 'F's
    int cur = 0; // Current count of consecutive 'F's
    int F_count = 0; // Count of F lengths

    // Count consecutive 'F's and store in F
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            if (cur > 0) {
                F[F_count++] = cur;
                cur = 0;
            }
        }
    }
    if (cur > 0) {
        F[F_count++] = cur; // Append the last count of 'F's
    }

    int evens[10000], odds[10000]; // Arrays to separate even and odd indexed counts
    int even_count = 0, odd_count = 0;

    // Separate counts into even and odd indexed arrays
    for (int i = 0; i < F_count; i++) {
        if (i % 2 == 0) {
            evens[even_count++] = F[i];
        } else {
            odds[odd_count++] = F[i];
        }
    }

    // Initialize the dynamic programming tables for x and y
    dpx[0][OFFSET] = true;
    dpy[0][OFFSET] = true;

    // Fill the dynamic programming table for even indexed counts
    for (int i = 0; i < even_count; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }

    // Fill the dynamic programming table for odd indexed counts
    for (int i = 0; i < odd_count; i++) {
        int val = odds[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
            }
        }
    }

    // Check if the target coordinates can be reached
    if (dpx[even_count][x + OFFSET] && dpy[odd_count][y + OFFSET]) {
        printf("Yes\n"); // Output "Yes" if reachable
    } else {
        printf("No\n"); // Output "No" if not reachable
    }

    return 0;
}

/<END-OF-CODE>
