#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input from the user
    while (n % 2 == 0) {  // Check if the number is even and keep dividing by 2 until odd
        n /= 2;
    }
    if (n == 1) {  // Check if the number has been reduced to 1
        printf("YES\n");  // Print 'YES' if the original number was a power of 2
    } else {
        printf("NO\n");  // Print 'NO' if the original number was not a power of 2
    }
    return 0;
}

// <END-OF-CODE>
