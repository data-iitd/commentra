#include <stdio.h>
#include <stdlib.h>

double harmonic_mean(int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        sum += 1.0 / value; // Calculate the reciprocal and accumulate the sum
    }
    return 1.0 / sum; // Return the harmonic mean
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers to process
    double result = harmonic_mean(n); // Calculate the harmonic mean
    printf("%lf\n", result); // Print the result
<<<<<<< HEAD
    return 0; // Return success
=======
    return 0; // Exit the program
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
