#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);  // Read an integer from the user

    while (n % 2 == 0) {  // While n is even
        n /= 2;  // Divide n by 2 to remove the last even factor
    }

    if (n == 1) {  // If n is now 1
        printf("YES\n");  // Print 'YES'
    } else {  // Otherwise
        printf("NO\n");  // Print 'NO'
    }

    return 0;
}

