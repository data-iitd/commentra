#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <stdbool.h> // Including library for boolean type
#include <string.h> // Including string library for sorting

// Function to compare two long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() { // Defining the main function
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements from standard input

    long *list = (long *)malloc(n * sizeof(long)); // Dynamically allocating memory for n long integers
    long *odd = (long *)malloc(n * sizeof(long)); // Dynamically allocating memory for odd numbers
    long sum = 0; // Initializing the sum variable to 0
    int odd_count = 0; // Counter for odd numbers

    for (int i = 0; i < n; i++) { // Iterating through the input to add each element to the array
        scanf("%ld", &list[i]); // Reading each long integer
    }

    for (int i = 0; i < n; i++) { // Iterating through each element in the array
        if (list[i] % 2 == 0) { // Checking if the current element is even
            sum += list[i]; // Adding the even number to the sum
        } else {
            odd[odd_count++] = list[i]; // Adding the odd number to the odd array and incrementing the count
        }
    }

    qsort(odd, odd_count, sizeof(long), compare); // Sorting the odd array in ascending order

    for (int i = 0; i < odd_count; i++) { // Iterating through each odd number in the sorted odd array
        sum += odd[i]; // Adding the odd number to the sum
    }

    if (odd_count % 2 != 0) { // Checking if the count of odd numbers is odd
        sum -= odd[0]; // Subtracting the first odd number if the count is odd
    }

    printf("%ld\n", sum); // Printing the final sum to the standard output

    free(list); // Freeing the allocated memory for list
    free(odd); // Freeing the allocated memory for odd numbers

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
