
#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation
#include <string.h> // Include the string library for string manipulation

int main() {
    // Creating a Scanner object to read input from the console
    // (Scanner is not available in C, so we can't use it)
    
    // Reading the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initializing an array of size n
    int a[n];
    
    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sorting the array in ascending order
    // (We can't use the Arrays class in C, so we'll have to implement our own sorting algorithm)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swapping the elements if they are in the wrong order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    // Loop to check the condition for adjacent elements in the sorted array
    for (int i = 0; i < n - 1; i++) {
        // Checking if the next element is less than double the current element
        // and ensuring they are not equal
        if (a[i + 1] < a[i] * 2 && a[i]!= a[i + 1]) {
            // If the condition is met, print "YES" and exit the program
            printf("YES\n");
            return 0;
        }
    }
    
    // If no such pair is found, print "NO"
    printf("NO\n");
    
    return 0;
}
