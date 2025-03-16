#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 5
#define MAX_N 100

int a[MAX_CHAR];
int ans = 0;

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < MAX_CHAR; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int dic[256] = {0}; // To count occurrences of 'M', 'A', 'R', 'C', 'H'

    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c); // Read a single character
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[(int)c]++;
        }
    }

    for (char c = 'M'; c <= 'H'; c++) {
        if (c == 'A' || c == 'C' || c == 'H' || c == 'M' || c == 'R') {
            a[c - 'A'] = dic[(int)c]; // Store counts in array a
        }
    }

    dfs(3, 0, 1);
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
