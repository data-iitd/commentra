#include <stdio.h>

int main() {
    int x, t, a, b, da, db;
    
    // Read input values
    scanf("%d %d %d %d %d %d", &x, &t, &a, &b, &da, &db);
    
    // Check if the value of x is 0
    if (x == 0) {
        printf("YES\n");
        return 0;
    }
    
    // Calculate the maximum number of times a and b can be decremented within the time limit t
    int a_time = (a / da < t - 1) ? a / da : t - 1;
    int b_time = (b / db < t - 1) ? b / db : t - 1;
    
    // Iterate over all possible combinations of decrements for a and b within their respective limits
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
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
    
    // If no combination results in x, print "NO"
    printf("NO\n");
    
    return 0;
}

// <END-OF-CODE>
