

#include <stdio.h>
#include <stdlib.h>

int main() {
    int len, i, l, r, flag = 0, isTrue = 0;
    scanf("%d", &len); // Read the length of the array
    int a[len]; // Initialize the array with the length read
    for (i = 0; i < len; i++) {
        scanf("%d", &a[i]); // Read the elements of the array
    }
    for (i = 0; i < len; i++) {
        if (a[i]!= i + 1 &&!flag) { // Check for the first misplaced element
            l = i + 1; // Set the starting index
            flag = 1; // Set the flag to true
            continue; // Continue to the next iteration
        }
        if (a[i]!= i + 1 && flag) { // Check for the second misplaced element
            r = i + 1; // Set the ending index
            if ((a[r - 1] - a[r - 2]) > 0) { // Check if the segment is unsorted
                isTrue = 1; // Set the flag to true
                break; // Break out of the loop
            }
        }
    }
    printf("%d %d", (isTrue == 0)? l : 0, (isTrue == 0)? r : 0); // Print the indices or "0 0" if no such segment exists
    return 0;
}
