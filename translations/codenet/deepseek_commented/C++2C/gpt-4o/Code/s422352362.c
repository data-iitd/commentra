#include <stdio.h> // Include the C standard input/output library for scanf and printf functions.
#include <stdlib.h> // Include the standard library for using abs function.

long long a[200005]; // Declare an array to store the input values.
long long pre[200005]; // Declare an array to store the prefix sums.
long long last[200005]; // Declare an array to store the suffix sums.

int main() { // The main function where the execution of the program begins.
    int n; // Declare a variable to store the number of elements.
    scanf("%d", &n); // Read the value of n from the standard input.
<<<<<<< HEAD
    
    for (int i = 1; i <= n; i++) { // Loop to read n integers into the array a.
        scanf("%lld", &a[i]); // Read the i-th integer and store it in a[i].
    }
    
    long long sumpre = 0, sumlast = 0; // Declare variables to store the cumulative sums of prefix and suffix.
    
    for (int i = 1; i < n; i++) { // Loop to calculate the prefix sums.
        sumpre = sumpre + a[i]; // Add the current element to the cumulative sum.
        pre[i] = sumpre; // Store the cumulative sum in the pre array.
    }
    
    for (int i = n; i > 1; i--) { // Loop to calculate the suffix sums.
        sumlast = sumlast + a[i]; // Add the current element to the cumulative sum.
        last[i] = sumlast; // Store the cumulative sum in the last array.
    }
    
    long long d = (1ll << 60); // Declare a variable to store the minimum difference and initialize it to a large number.
    
    for (int i = 1; i < n; i++) { // Loop to find the minimum absolute difference between prefix and suffix sums.
        d = (d < abs(pre[i] - last[i + 1])) ? d : abs(pre[i] - last[i + 1]); // Update the minimum difference if a smaller one is found.
    }
    
    printf("%lld\n", d); // Print the minimum difference found.
    
    return 0; // Return 0 to indicate successful completion of the program.
=======
    for (int i = 1; i <= n; i++) { // Loop to read n integers into the array a.
        scanf("%lld", &a[i]); // Read the i-th integer and store it in a[i].
    }
    long long sumpre = 0, sumlast = 0; // Declare variables to store the cumulative sums of prefix and suffix.
    for (int i = 1; i < n; i++) { // Loop to calculate the prefix sums.
        sumpre = sumpre + a[i]; // Add the current element to the cumulative sum.
        pre[i] = sumpre; // Store the cumulative sum in the pre array.
        // printf("%lld++\n", pre[i]); // Uncommented code to print the prefix sums (for debugging purposes).
    }
    for (int i = n; i > 1; i--) { // Loop to calculate the suffix sums.
        sumlast = sumlast + a[i]; // Add the current element to the cumulative sum.
        last[i] = sumlast; // Store the cumulative sum in the last array.
        // printf("%lld+++\n", last[i]); // Uncommented code to print the suffix sums (for debugging purposes).
    }
    long long d = (1ll << 60); // Declare a variable to store the minimum difference and initialize it to a large number.
    for (int i = 1; i < n; i++) { // Loop to find the minimum absolute difference between prefix and suffix sums.
        // printf("%lld\n", pre[i] - last[i + 1]); // Uncommented code to print the difference between prefix and suffix sums (for debugging purposes).
        d = (d < abs(pre[i] - last[i + 1])) ? d : abs(pre[i] - last[i + 1]); // Update the minimum difference if a smaller one is found.
    }
    printf("%lld\n", d); // Print the minimum difference found.
    return 0; // Return 0 to indicate successful execution.
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
