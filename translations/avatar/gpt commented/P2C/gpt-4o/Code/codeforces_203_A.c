#include <stdio.h>

int main() {
    // Read input values
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    // Check if the target value x is zero
    if (x == 0) {
        printf("YES\n");  // If x is zero, print "YES"
        return 0;
    }

    // Calculate the maximum time available for a and b, constrained by t
    int a_time = (a / da < t - 1) ? (a / da) : (t - 1);
    int b_time = (b / db < t - 1) ? (b / db) : (t - 1);

    // Iterate through all possible values of i and j within the calculated time limits
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if (a - da * i == x || b - db * j == x) {
                printf("YES\n");  // If found, print "YES"
                return 0;
            }
            // Check if the sum of the remaining values of a and b equals x
            if ((a - da * i) + (b - db * j) == x) {
                printf("YES\n");  // If found, print "YES"
                return 0;
            }
        }
    }

    // If no valid combination is found, print "NO"
    printf("NO\n");
    return 0;
}

// <END-OF-CODE>
