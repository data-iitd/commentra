#include<stdio.h>

int main() {
    // Declare variables for iteration, maximum value, index of maximum value, and a buffer for swapping
    int i, j, max, max_j, buf;
    // Array to hold 5 integer inputs
    int io[5];

    // Read 5 integers from user input
    scanf("%d %d %d %d %d", &io[0], &io[1], &io[2], &io[3], &io[4]);

    // Outer loop to iterate through each element in the array
    for(i = 0; i < 5; i++) {
        // Assume the current element is the maximum
        max = io[i];
        max_j = i; // Store the index of the maximum element

        // Inner loop to find the maximum element in the remaining unsorted portion of the array
        for(j = i + 1; j < 5; j++) {
            // If a larger element is found, update max and max_j
            if(max < io[j]) {
                max = io[j];
                max_j = j;
            }
        }

        // Swap the found maximum element with the current element
        buf = io[i];
        io[i] = io[max_j];
        io[max_j] = buf;

        // Print the current element, ensuring proper formatting for the last element
        i < 4 ? printf("%d ", io[i]) : printf("%d\n", io[i]);
    }

    return 0; // Indicate that the program ended successfully
}
