#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define MAX_ROWS 8000
#define MAX_COLS 20000
#define OFFSET 10000

bool dpx[MAX_ROWS][MAX_COLS];
bool dpy[MAX_ROWS][MAX_COLS];

void updateDPX(int index, int val, int evens_count) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
        }
        if (j - val >= 2000 && index != 0) {
            dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
        }
    }
}

void updateDPY(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
        }
        if (j - val >= 2000) {
            dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
        }
    }
}

int main() {
    char S[100];
    int x, y;
    int evens[8000], odds[8000];
    int evens_count = 0, odds_count = 0;

    // Read the string
    scanf("%s", S);

    // Read x and y
    scanf("%d %d", &x, &y);

    // Initialize dpx and dpy
    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));
    dpx[0][10000] = true; // Starting point for dpx
    dpy[0][10000] = true; // Starting point for dpy

    // Process the string to fill evens and odds
    for (int i = 0; S[i] != '\0'; i++) {
        if (i % 2 == 0) {
            evens[evens_count++] = S[i] - '0'; // Convert char to int
        } else {
            odds[odds_count++] = S[i] - '0'; // Convert char to int
        }
    }

    // Update dpx for evens
    for (int i = 0; i < evens_count; i++) {
        updateDPX(i, evens[i], evens_count);
    }

    // Update dpy for odds
    for (int i = 0; i < odds_count; i++) {
        updateDPY(i, odds[i]);
    }

    // Check the conditions
    if (dpx[evens_count][x + OFFSET] && dpy[odds_count][y + OFFSET]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

/* <END-OF-CODE> */
