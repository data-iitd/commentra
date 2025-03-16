#include <stdio.h>

int G(int a, int b) {
    // Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
    while (a % b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int L(int a, int b) {
    // Calculate the least common multiple (LCM) of a and b using the relationship between GCD and LCM
    return a * (b / G(a, b));
}

int main() {
    int x, y, a, b;
    
    // Read four integers x, y, a, and b from the input
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    // Calculate the LCM of x and y
    int lcm = L(x, y);
    
    // Compute the number of integers in the range from a to b that are divisible by lcm
    // and print the result
    printf("%d\n", b / lcm - (a - 1) / lcm);
    
    return 0;
}

// <END-OF-CODE>
