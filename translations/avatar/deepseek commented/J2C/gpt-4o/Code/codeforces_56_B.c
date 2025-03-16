#include <stdio.h>
#include <stdbool.h>

int main() {
    int len;
    scanf("%d", &len); // Read the length of the array
    int a[len]; // Initialize the array with the length read
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]); // Read the elements of the array
    }
    
    int l = 0; // Initialize the starting index of the misplaced element
    int r = 0; // Initialize the ending index of the misplaced element
    bool flag = false; // Flag to indicate the start of the misplaced segment
    bool isTrue = false; // Flag to indicate if the segment is unsorted

    for (int i = 0; i < len; i++) {
        if (a[i] != i + 1 && !flag) { // Check for the first misplaced element
            l = i + 1; // Set the starting index
            flag = true; // Set the flag to true
            continue; // Continue to the next iteration
        }
        if (a[i] != i + 1 && flag) { // Check for the second misplaced element
            r = i + 1; // Set the ending index
            if (a[r - 1] - a[r - 2] > 0) { // Check if the segment is unsorted
                isTrue = true; // Set the flag to true
                break; // Break out of the loop
            }
        }
    }
    
    printf("%s\n", (!isTrue) ? "%d %d" : "0 0", l, r); // Print the indices or "0 0" if no such segment exists
    return 0;
}
