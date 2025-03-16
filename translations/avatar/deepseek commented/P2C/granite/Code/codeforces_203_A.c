

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char xxs[1000];
    fgets(xxs, 1000, stdin);

    char* xxs_token = strtok(xxs, " ");
    char* endptr;
    int x = strtol(xxs_token, &endptr, 10);

    int t, a, b, da, db;
    int i, j;
    char* token;

    token = strtok(NULL, " ");
    t = strtol(token, &endptr, 10);

    token = strtok(NULL, " ");
    a = strtol(token, &endptr, 10);

    token = strtok(NULL, " ");
    b = strtol(token, &endptr, 10);

    token = strtok(NULL, " ");
    da = strtol(token, &endptr, 10);

    token = strtok(NULL, " ");
    db = strtol(token, &endptr, 10);

    // Check if the value of x is 0
    if (x == 0) {
        printf("YES\n");
        return 0;
    }

    // Calculate the maximum number of times a and b can be decremented within the time limit t
    int a_time = (a / da) < t? (a / da) : (t - 1);
    int b_time = (b / db) < t? (b / db) : (t - 1);

    // Iterate over all possible combinations of decrements for a and b within their respective limits
    for (i = 0; i <= a_time; i++) {
        for (j = 0; j <= b_time; j++) {
            // Check if either a or b (or their sum) equals x
            if (a - da * i == x || b - db * j == x) {
                printf("YES\n");
                return 0;
            }
            if ((a - da * i) + (b - db * j) == x) {
                printf("YES\n");
                return 0;
            }
        }
    }

    // Print "NO" if no combination results in x
    printf("NO\n");

    return 0;
}
