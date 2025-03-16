
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, t, a, b, da, db, first, second, ok;

    // Reading the number of test cases (t) and other required values
    scanf("%d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    // Variables to store calculated values
    ok = 0;

    // Nested loop to calculate possible values of first and second
    for (int i = 0; i < t; i++) {
        first = a - (da * i);
        for (int j = 0; j < t; j++) {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                // Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }

    // Print the result based on the flag
    if (ok) printf("YES");
    else printf("NO");

    return 0;
}

// Translate the above C code to Python and end with comment "