#include <stdio.h>

int main() {
    int age;
    scanf("%d", &age);  // Taking an integer input for the variable `age`
    
    if (age == 1) {  // Checking if `age` is equal to 1
        printf("Hello World\n");  // If `age` is 1, it prints "Hello World"
    } else {  // If `age` is not 1
        int a, b;
        scanf("%d", &a);  // Taking the first integer input and assigning it to `a`
        scanf("%d", &b);  // Taking the second integer input and assigning it to `b`
        printf("%d\n", a + b);  // Printing the sum of `a` and `b`
    }
    
    return 0;
}

// <END-OF-CODE>
