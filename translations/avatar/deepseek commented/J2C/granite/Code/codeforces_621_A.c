

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    long list[n]; // Array to store the elements
    for (int i = 0; i < n; i++) {
        scanf("%ld", &list[i]); // Read the elements and store them in the array
    }
    
    long odd[n]; // Array to store odd numbers
    int odd_count = 0; // Initialize count of odd numbers
    long sum = 0; // Initialize sum of numbers
    
    for (int i = 0; i < n; i++) { // Iterate through the array
        if (list[i] % 2 == 0) {
            sum += list[i]; // Add to sum if the number is even
        } else {
            odd[odd_count] = list[i]; // Add to odd array if the number is odd
            odd_count++; // Increment count of odd numbers
        }
    }
    
    qsort(odd, odd_count, sizeof(long), cmpfunc); // Sort the array of odd numbers
    
    for (int i = 0; i < odd_count; i++) {
        sum += odd[i]; // Add all odd numbers to the sum
    }
    
    if (odd_count % 2!= 0) {
        sum -= odd[0]; // Subtract the smallest odd number if the count of odd numbers is odd
    }
    
    printf("%ld\n", sum); // Print the final sum
    
    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(long*)a - *(long*)b ); // Function to compare two long integers
}

