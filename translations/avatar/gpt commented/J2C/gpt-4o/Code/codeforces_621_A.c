#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

int main() {
    // Reading the number of elements to be processed
    int n;
    scanf("%d", &n);
    
    // Allocating memory for the input numbers
    long long *list = (long long *)malloc(n * sizeof(long long));
    
    // Reading n long integers from input and adding them to the list
    for (int i = 0; i < n; i++) {
        scanf("%lld", &list[i]);
    }
    
    // Initializing an array to store odd numbers and a variable to hold the sum
    long long *odd = (long long *)malloc(n * sizeof(long long));
    int odd_count = 0;
    long long sum = 0;
    
    // Iterating through the list to separate even and odd numbers
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 0) {
            // If the number is even, add it to the sum
            sum += list[i];
        } else {
            // If the number is odd, add it to the odd array
            odd[odd_count++] = list[i];
        }
    }
    
    // Sorting the array of odd numbers in ascending order
    qsort(odd, odd_count, sizeof(long long), compare);
    
    // Adding all odd numbers to the sum
    for (int i = 0; i < odd_count; i++) {
        sum += odd[i];
    }
    
    // If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if (odd_count % 2 != 0) {
        sum -= odd[0];
    }
    
    // Printing the final calculated sum
    printf("%lld\n", sum);
    
    // Freeing allocated memory
    free(list);
    free(odd);
    
    return 0;
}

// <END-OF-CODE>
