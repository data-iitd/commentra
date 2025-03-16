#include<stdio.h>

int main() {
    // Declare an integer variable to store user input
    int n;

    // Read an integer value from the user
    scanf("%d", &n);

    // Check if the number is even
    if (n % 2 == 0) {
        // If the number is even, print half of the number
        printf("%d\n", n / 2);
    } else {
        // If the number is odd, print half of the number plus one
        printf("%d\n", (n / 2) + 1);
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
