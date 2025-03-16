#include <stdio.h>

int main() {
    // Input the string of numbers separated by spaces
    int x, t, a, b, da, db;
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);

    // Check if x is equal to zero
    if (x == 0) {
        // If yes, print "YES" and return
        printf("YES\n");
        return 0;
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = (a / da < t - 1) ? a / da : t - 1;
    int b_time = (b / db < t - 1) ? b / db : t - 1;

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x) {
                // If yes, print "YES" and return
                printf("YES\n");
                return 0;
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if ((a - da * i) + (b - db * j) == x) {
                // If yes, print "YES" and return
                printf("YES\n");
                return 0;
            }
        }
    }

    // If no result found, print "NO"
    printf("NO\n");
    return 0;
}

// <END-OF-CODE>
