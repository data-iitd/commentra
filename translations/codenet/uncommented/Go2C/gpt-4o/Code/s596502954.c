#include <stdio.h>

int main() {
    int a, b, c;
    
    // Read three integers from input
    scanf("%d %d %d", &a, &b, &c);
    
    // Check if the sum of the first two integers is greater than or equal to the third
    if (a + b >= c) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}

// <END-OF-CODE>
