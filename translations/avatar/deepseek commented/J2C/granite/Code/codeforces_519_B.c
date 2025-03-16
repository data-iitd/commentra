

#include <stdio.h>

int main() {
    // Create a Scanner object to read input from the standard input stream
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);

    // Sum all n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a += x;
    }

    // Sum n-1 elements
    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);
        b += x;
    }

    // Sum n-2 elements
    for (int i = 0; i < n - 2; i++) {
        int x;
        scanf("%d", &x);
        c += x;
    }

    // Calculate the differences
    int x = a - b;
    int y = b - c;

    // Output the results
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}

