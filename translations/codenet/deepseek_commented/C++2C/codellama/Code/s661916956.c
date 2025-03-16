#include<stdio.h>
#include<stdlib.h>
int main(){
    // Read three integers from the standard input
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Sort the integers in ascending order
    if (a > b) {
        swap(&a, &b); // Swap a and b if a is greater than b
    }
    if (b > c) {
        swap(&b, &c); // Swap b and c if b is greater than c
    }
    if (a > b) {
        swap(&a, &b); // Swap a and b again to ensure a is not greater than b after the second swap
    }

    // Print the sorted integers
    printf("%d %d %d\n", a, b, c);
}

