
#include <stdio.h>

int main() {
    int age;
    // Prompt the user to input their age and store it in the variable age
    scanf("%d", &age);

    // Check if the age is equal to 1
    if (age == 1) {
        // If age is 1, print 'Hello World'
        printf("Hello World\n");
    } else {
        // If age is not 1, prompt the user to input two integers
        int a, b;
        scanf("%d %d", &a, &b);
        // Calculate and print the sum of the two integers
        printf("%d\n", a + b);
    }

    return 0;
}
// 