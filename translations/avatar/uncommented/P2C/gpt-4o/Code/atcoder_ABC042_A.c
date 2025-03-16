#include <stdio.h>

int main() {
    int ABC[3];
    int count5 = 0;
    int sum = 0;

    // Read input
    for (int i = 0; i < 3; i++) {
        scanf("%d", &ABC[i]);
        sum += ABC[i];
        if (ABC[i] == 5) {
            count5++;
        }
    }

    // Check conditions
    if (count5 == 2) {
        if (sum == 17) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
