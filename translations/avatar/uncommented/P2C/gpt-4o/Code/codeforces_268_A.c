#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char q[n][100]; // Assuming each input string can be up to 99 characters + 1 for null terminator
    int count = 0;

    // Read input strings
    for (int i = 0; i < n; i++) {
        scanf("%s", q[i]);
    }

    // Compare strings
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (k == j) {
                continue;
            } else if (q[j][0] == q[k][strlen(q[k]) - 1]) {
                count++;
            } else {
                continue;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

// <END-OF-CODE>
