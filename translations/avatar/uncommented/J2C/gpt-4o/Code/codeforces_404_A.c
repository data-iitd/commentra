#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char arr[n][n];
    char str[n][n + 1]; // +1 for null terminator

    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    // Fill the arr with characters from str
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[i][j];
        }
    }

    char a = arr[0][0];
    char b = arr[0][1];

    if (a == b) {
        printf("NO\n");
    } else {
        bool res = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    if (arr[i][j] != a) {
                        res = false;
                        break;
                    }
                } else {
                    if (arr[i][j] != b) {
                        res = false;
                        break;
                    }
                }
            }
            if (!res) break; // Break outer loop if result is false
        }
        if (res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
