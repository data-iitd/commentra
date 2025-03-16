#include <stdio.h>

int main() {
    int ABC[3]; // Array to store the input integers
    int count5 = 0; // Counter for the number of 5s
    int sum = 0; // Variable to store the sum of the elements

    // Take input from user
    printf("Enter three integers: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &ABC[i]);
        sum += ABC[i]; // Calculate the sum
        if (ABC[i] == 5) {
            count5++; // Count the number of 5s
        }
    }

    // Check if the array contains exactly two 5s
    if (count5 == 2) {
        // Check if the sum of the elements in ABC is 17
        printf("%s\n", (sum == 17) ? "YES" : "NO");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
