#include <stdio.h>

int rec(long x) {
    int answer = 0; // Initialize the count of bits set to 1
    for (int k = 31; k >= 0; k--) { // Iterate through each bit position
        if ((x & (1 << k)) != 0) { // Check if the k-th bit is set to 1
            answer++; // Increment the count if the bit is set
        }
    }
    return answer; // Return the count of bits set to 1
}

int main() {
    int n; // Number of elements
    scanf("%d", &n); // Read the number of elements
    int a[33] = {0}; // Initialize an array to count occurrences of bits set to 1

    // Count the number of bits set to 1 for each input number and store in array a
    for (int i = 0; i < n; i++) {
        int count = rec(0); // Initialize count for the current number
        long num;
        scanf("%ld", &num); // Read the number
        a[rec(num)]++; // Increment the count in the array based on the number of bits set to 1
    }

    double answer = 0; // Initialize the answer variable

    // Calculate the answer based on the given formula
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }

    // Print the final answer in the required format
    printf("%ld\n", (long)answer); // Print the answer as a long integer
    return 0; // Return success
}

// <END-OF-CODE>
