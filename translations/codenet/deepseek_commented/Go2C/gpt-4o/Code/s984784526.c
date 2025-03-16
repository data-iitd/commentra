#include <stdio.h>

int main() {
    // Declare an array of 3 integers
    int a[3];

    // Read three integers from standard input and store them in the array `a`
    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    // Initialize counters for the number of 5s and 7s
    int five = 0;
    int seven = 0;

    // Loop through the array to count the number of 5s and 7s
    for (int i = 0; i < 3; i++) {
        if (a[i] == 5) {
            five++;
        }
        if (a[i] == 7) {
            seven++;
        }
    }

    // Check if there are exactly 2 fives and 1 seven
    if (five == 2 && seven == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
