#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the console
    FILE *f = fopen("input.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    long *list = (long *) malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        fscanf(f, "%ld", &list[i]);
    }
    fclose(f);
    
    // Initializing a list to store odd numbers and a variable to hold the sum
    long *odd = (long *) malloc(n * sizeof(long));
    long sum = 0;
    
    // Iterating through the list to separate even and odd numbers
    for (int i = 0; i < n; i++) {
        if (list[i] % 2 == 0) {
            // If the number is even, add it to the sum
            sum += list[i];
        } else {
            // If the number is odd, add it to the odd list
            odd[i] = list[i];
        }
    }
    
    // Sorting the list of odd numbers in ascending order
    qsort(odd, n, sizeof(long), compare);
    
    // Adding all odd numbers to the sum
    for (int i = 0; i < n; i++) {
        sum += odd[i];
    }
    
    // If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if (n % 2!= 0) {
        sum -= odd[0];
    }
    
    // Printing the final calculated sum
    printf("%ld\n", sum);
    return 0;
}

