#include <stdio.h>

// Function A definition goes here
void A(void);

// Function B definition goes here
void B(void);

// Function C definition goes here
void C(void);

// Function D definition goes here
void D(void);

int main(void){
    // Call function B
    B();
}

// Function B definition
// Reads a long long integer 'x' from the standard input
void B(void){
    long long int x, sum; // Declare variables 'x' and 'sum' of type long long int
    scanf("%lld", &x); // Read a long long integer 'x' from the standard input
    int i; // Declare variable 'i' of type int
    sum = 100; // Initialize 'sum' with the value 100

    // Calculate the number of iterations required to reach or exceed 'x'
    for(i = 0; sum < x; ++i){
        sum += sum / 100; // Update 'sum' by adding the result of dividing 'sum' by 100
    }

    // Print the number of iterations required to reach or exceed 'x'
    printf("%d\n", i);
}

// Function A, C, and D definitions can be added here

