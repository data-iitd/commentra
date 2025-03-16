#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a Scanner object to read input from the console
    int n;
    scanf("%d", &n);
    
    // Initializing an array of size n
    int a[n];
    
    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sorting the array in ascending order
    qsort(a, n, sizeof(int), compare);
    
    // Loop to check the condition for adjacent elements in the sorted array
    for (int i = 0; i < n - 1; i++) {
        // Checking if the next element is less than double the current element
        // and ensuring they are not equal
        if (a[i + 1] < a[i] * 2 && a[i]!= a[i + 1]) {
            // If the condition is met, print "YES" and exit the program
            printf("YES");
            return 0;
        }
    }
    
    // If no such pair is found, print "NO"
    printf("NO");
    return 0;
}

