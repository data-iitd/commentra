#include <stdio.h>
#include <string.h>

int main() {
    char str[4][100]; // Declare an array of strings (4 strings of max length 99 + 1 for null terminator)
    int i = -1;

    // Read input strings into the array
    while (i != 3) {
        i++;
        scanf("%s", str[i]);
    }

    int u = -1;
    i = -1;
    int yes = 0;

    // Compare characters in the array
    while (u != 2) {
        u++;
        i = -1;
        while (i != 2) {
            i++;
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = 1;
                printf("YES\n");
                break;
            }
        }
        if (yes == 1) {
            break;
        }
    }

    if (yes == 0) {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
