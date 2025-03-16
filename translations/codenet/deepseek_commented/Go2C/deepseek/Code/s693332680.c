#include <stdio.h>

int main() {
    // Declare three integer variables x, a, and b to store input values.
    int x, a, b;
    
    // Read three integers from the standard input and assign them to x, a, and b.
    scanf("%d %d %d", &x, &a, &b);
    
    // Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
    if (b - a <= 0) {
        printf("delicious\n");
    } else if (b - a <= x) {
        printf("safe\n");
    } else {
        printf("dangerous\n");
    }
    
    return 0;
}
