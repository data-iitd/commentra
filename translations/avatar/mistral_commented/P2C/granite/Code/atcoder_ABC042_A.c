
#include <stdio.h>

int main() {
    // Define a tuple 'ABC' by splitting a user input by space and converting each element to integer using the atoi() function
    int ABC[3];
    scanf("%d %d %d", &ABC[0], &ABC[1], &ABC[2]);

    // Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using a for loop
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (ABC[i] == 5) {
            count++;
        }
    }
    if (count == 2) {
        // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
        int sum = ABC[0] + ABC[1] + ABC[2];
        if (sum == 17) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        // If the condition is not met, print 'NO'
        printf("NO\n");
    }

    return 0;
}
