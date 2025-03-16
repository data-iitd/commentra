
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int a[5], r[5], i, b, ans = 0;
    int *map = (int*)malloc(sizeof(int) * 10); // Dynamically allocating memory for the TreeMap

    // Initializing the TreeMap with default values
    for (i = 0; i < 10; i++) {
        map[i] = INT_MAX; // Assigning INT_MAX (maximum integer value) to all elements of the TreeMap
    }

    // Reading input elements of array 'a' and storing their remainders in array 'r'
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]); // Reading an integer value from the console and storing it in the 'i'th index of array 'a'
        r[i] = a[i] % 10; // Calculating the remainder of the 'i'th element of array 'a' and storing it in the 'i'th index of array 'r'

        if (r[i]!= 0) { // Checking if the remainder of the 'i'th element of array 'a' is not zero
            b = 10 - r[i]; // Calculating the complement of the remainder and assigning it to 'b'
            if (map[b] == INT_MAX) { // Checking if the complement is not already present in the TreeMap
                map[b] = a[i]; // Storing the complement as a key and the corresponding integer value (the 'i'th element of array 'a') in the TreeMap
            }
        }
    }

    // Checking if the TreeMap is empty
    if (map[9] == INT_MAX) {
        for (i = 0; i < 5; i++) { // Iterating through the array 'a'
            ans += a[i]; // Adding the 'i'th element of array 'a' to the sum 'ans'
        }
        printf("%d\n", ans); // Printing the sum of all elements in array 'a'
        return 0; // Exiting the program if the TreeMap is empty
    }

    int last = map[9]; // Getting the last key (complement) from the TreeMap and finding its corresponding value (the last element of array 'a')
    int idx = 0; // Initializing 'idx' to zero

    // Finding the index of the last element in array 'a'
    for (i = 0; i < 5; i++) {
        if (a[i] == last) { // Checking if the 'i'th element of array 'a' is equal to the last element
            idx = i; // If true, assigning the index to 'idx'
            break; // Exiting the loop
        }
    }

    // Calculating the sum of all elements in array 'a' except the last one
    for (i = 0; i < 5; i++) {
        if (i!= idx) { // Checking if the current index is not equal to 'idx'
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

    free(map); // Freeing the dynamically allocated memory for the TreeMap

    return 0; // Returning 0 to indicate successful execution
}

