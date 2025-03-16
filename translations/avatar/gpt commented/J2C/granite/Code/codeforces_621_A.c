
#include <stdio.h> // Include necessary header files
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the console
    // (This part is not possible in C, so we will skip it)
    
    // Reading the number of elements to be processed
    int n;
    scanf("%d", &n);
    
    // Initializing an array to store the input numbers
    long list[n];
    
    // Reading n long integers from input and storing them in the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &list[i]);
    }
    
    // Initializing a list to store odd numbers and a variable to hold the sum
    long odd[n];
    int odd_count = 0;
    long sum = 0;
    
    // Iterating through the array to separate even and odd numbers
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 0) {
            // If the number is even, add it to the sum
            sum += list[i];
        } else {
            // If the number is odd, add it to the odd list
            odd[odd_count] = list[i];
            odd_count++;
        }
    }
    
    // Sorting the list of odd numbers in ascending order
    qsort(odd, odd_count, sizeof(long), cmpfunc);
    
    // Adding all odd numbers to the sum
    for (int i = 0; i < odd_count; i++) {
        sum += odd[i];
    }
    
    // If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if (odd_count % 2!= 0) {
        sum -= odd[0];
    }
    
    // Printing the final calculated sum
    printf("%ld\n", sum);
    
    // Returning 0 to indicate successful execution
    return 0;
}

// Function to compare two long integers for sorting
int cmpfunc (const void * a, const void * b) {
   return ( *(long*)a - *(long*)b );
}

// End of code
