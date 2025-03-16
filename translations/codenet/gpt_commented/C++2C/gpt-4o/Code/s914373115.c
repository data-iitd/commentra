#include <stdio.h>

void A(void);
void B(void);
void C(void);
void D(void);

int main(void) {
    // Call function B to execute its logic
    B();
    return 0;
}

void B(void) {
    long long int x, sum; // Declare variables for input and sum
    scanf("%lld", &x); // Read input value x from the user
    int i; // Declare a counter variable
    sum = 100; // Initialize sum to 100

    // Loop until sum is less than x
    for (i = 0; sum < x; ++i) {
        // Increase sum by 1% of its current value
        sum += sum / 100;
    }

    // Output the number of iterations needed to exceed or meet x
    printf("%d\n", i);
}

// <END-OF-CODE>
