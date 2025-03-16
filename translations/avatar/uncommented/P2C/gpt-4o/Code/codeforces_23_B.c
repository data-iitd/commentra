#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of inputs
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a); // Read each input
        if (a < 2) {
            printf("0\n"); // Print 0 if a is less than 2
        } else {
            printf("%d\n", a - 2); // Print a - 2 if a is greater than or equal to 2
        }
    }
    return 0;
}

// <END-OF-CODE>
