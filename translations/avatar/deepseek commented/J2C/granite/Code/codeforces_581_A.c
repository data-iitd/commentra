

#include <stdio.h>

int main() {
    int a, b, count = 0;
    scanf("%d %d", &a, &b); // Read input values for a and b
    
    while (a > 0 && b > 0) { // Loop continues until the condition is met to break
        count++; // Increment count
        a--; // Decrement a
        b--; // Decrement b
    }
    
    int ans = a / 2 + b / 2; // Calculate the value of ans
    printf("%d %d", count, ans); // Print the results
    
    return 0;
}
// END-OF-CODE