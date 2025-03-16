#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <stdbool.h> // Including library for boolean type

#define SIZE 5 // Defining the size of the arrays

int main() {
    int a[SIZE]; // Creating an integer array 'a' of size 5
    int r[SIZE]; // Creating an integer array 'r' of size 5
    int map[SIZE]; // Creating an array to store complements
    int values[SIZE]; // Array to store corresponding values
    int mapSize = 0; // Variable to track the size of the map
    int ans = 0; // Initializing 'ans' to zero

    // Reading input elements of array 'a' and storing their remainders in array 'r'
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]); // Reading an integer value from the console and storing it in the 'i'th index of array 'a'
        r[i] = a[i] % 10; // Calculating the remainder of the 'i'th element of array 'a' and storing it in the 'i'th index of array 'r'

        int b = 10; // Initializing 'b' to 10
        if (r[i] != 0) { // Checking if the remainder of the 'i'th element of array 'a' is not zero
            b = 10 - r[i]; // Calculating the complement of the remainder and assigning it to 'b'
            // Storing the complement and the corresponding value in the map
            map[mapSize] = b; 
            values[mapSize] = a[i];
            mapSize++; // Incrementing the size of the map
        }
    }

    // Checking if the map is empty
    if (mapSize == 0) {
        for (int i = 0; i < SIZE; i++) { // Iterating through the array 'a'
            ans += a[i]; // Adding the 'i'th element of array 'a' to the sum 'ans'
        }
        printf("%d\n", ans); // Printing the sum of all elements in array 'a'
        return 0; // Exiting the program if the map is empty
    }

    // Finding the last key (complement) from the map
    int last = values[mapSize - 1]; // Getting the last value from the map
    int idx = 0; // Initializing 'idx' to zero

    // Finding the index of the last element in array 'a'
    for (int i = 0; i < SIZE; i++) {
        if (a[i] == last) { // Checking if the 'i'th element of array 'a' is equal to the last element
            idx = i; // If true, assigning the index to 'idx'
            break; // Exiting the loop
        }
    }

    // Calculating the sum of all elements in array 'a' except the last one
    for (int i = 0; i < SIZE; i++) {
        if (i != idx) { // Checking if the current index is not equal to 'idx'
            if (a[i] % 10 == 0) { // Checking if the 'i'th element of array 'a' is a multiple of 10
                ans += a[i]; // If true, adding it to the sum 'ans'
            } else { // If the 'i'th element of array 'a' is not a multiple of 10
                ans += a[i] + (10 - r[i]); // Adding the 'i'th element of array 'a' and its complement to the sum 'ans'
            }
        }
    }

    // Adding the last element of array 'a' to the sum 'ans'
    ans += last;

    printf("%d\n", ans); // Printing the final sum
    return 0; // Exiting the program
}

// <END-OF-CODE>
