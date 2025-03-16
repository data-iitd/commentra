#include <stdio.h>

int main() {
    int age;
    // Declare a variable named 'age' and assign it the value of an integer input from the user
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if the value of 'age' is equal to 1
    if (age == 1) {
        // If the condition is met, print 'Hello World'
        printf("Hello World\n");
    } else {
        // If the condition is not met, declare two variables 'a' and 'b' and assign them the values of two integer inputs from the user
        int a, b;
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        // Print the sum of 'a' and 'b'
        printf("%d\n", a + b);
    }

    return 0;
}

// <END-OF-CODE>
