

#include <stdio.h>
#include <stdlib.h>

// Define a function to apply the logic to the ArrayList
void func(int *a, int n) {
    int min = 0;

    // Iterate through the ArrayList and apply the logic to each integer
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        } else {
            if (min!= 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                a[i] = a[i] % min;
                if (a[i] == 1) { // If the result is 1, print 1 and exit the program
                    printf("1\n");
                    exit(0);
                }
            } else { // If there is no minimum value yet, assign the current integer as the minimum value
                min = a[i];
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Read the first integer from the input

    // Check if the input is 1, if so, print the only integer and exit the program
    if (n == 1) {
        int x;
        scanf("%d", &x); // Read the only integer
        printf("%d\n", x); // Print the only integer
        return 0;
    }

    int *a = (int *)malloc(n * sizeof(int)); // Allocate memory for the ArrayList

    // Read the rest of the integers and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the ArrayList in ascending order
    qsort(a, n, sizeof(int), cmpfunc);

    // Check if the last integer in the ArrayList is 0, if so, print 0 and exit the program
    if (a[n - 1] == 0) {
        printf("0\n"); // Print 0
        return 0;
    }

    // Use a while loop to keep applying the function to the ArrayList until it contains only one element
    while (true) {
        if (n == 1) {
            printf("%d\n", a[0]); // Print the only remaining integer
            break; // Exit the loop
        }
        func(a, n); // Apply the function to the ArrayList
        n = unique(a, n); // Remove duplicate elements from the ArrayList
    }

    return 0;
}

// Define a function to compare two integers for sorting
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Define a function to remove duplicate elements from the ArrayList
int unique(int *a, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]!= a[j]) {
            a[++j] = a[i];
        }
    }
    return j + 1;
}

