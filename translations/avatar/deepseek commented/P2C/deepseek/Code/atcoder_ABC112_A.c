#include <stdio.h>

int main() {
    int age;
    scanf("%d", &age);  // Taking an integer input for the variable `age`
    if (age == 1) {  // Checking if `age` is equal to 1
        printf("Hello World\n");  // If `age` is 1, it prints "Hello World"
    } else {  // If `age` is not 1
        int a, b;
        scanf("%d %d", &a, &b);  // Taking two integer inputs and assigning them to variables `a` and `b`
        printf("%d\n", a + b);  // Printing the sum of `a` and `b`
    }
    return 0;
}

