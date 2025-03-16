#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    long long *list = (long long *)malloc(n * sizeof(long long)); // Allocate memory for the list
    for (int i = 0; i < n; i++) {
        scanf("%lld", &list[i]); // Read the elements and store them in the list
    }

    long long *odd = (long long *)malloc(n * sizeof(long long)); // Allocate memory for odd numbers
    int odd_count = 0; // Counter for odd numbers
    long long sum = 0; // Initialize sum of numbers

    for (int i = 0; i < n; i++) { // Iterate through the list
        if (list[i] % 2 == 0) {
            sum += list[i]; // Add to sum if the number is even
        } else {
            odd[odd_count++] = list[i]; // Add to odd array if the number is odd
        }
    }

    qsort(odd, odd_count, sizeof(long long), compare); // Sort the array of odd numbers

    for (int i = 0; i < odd_count; i++) {
        sum += odd[i]; // Add all odd numbers to the sum
    }

    if (odd_count % 2 != 0) {
        sum -= odd[0]; // Subtract the smallest odd number if the count of odd numbers is odd
    }

    printf("%lld\n", sum); // Print the final sum

    free(list); // Free allocated memory for list
    free(odd); // Free allocated memory for odd numbers
    return 0;
}

// <END-OF-CODE>
