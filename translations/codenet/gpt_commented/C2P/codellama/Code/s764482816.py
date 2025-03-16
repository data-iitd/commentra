#include<stdio.h>

int main() {
    # Declare variables for iteration, maximum value, index of maximum value, and a buffer for swapping
    i, j, max, max_j, buf = 0, 0, 0, 0, 0
    # Array to hold 5 integer inputs
    io = [0, 0, 0, 0, 0]

    # Read 5 integers from user input
    scanf("%d %d %d %d %d", &io[0], &io[1], &io[2], &io[3], &io[4])

    # Outer loop to iterate through each element in the array
    for i in range(5):
        # Assume the current element is the maximum
        max = io[i]
        max_j = i # Store the index of the maximum element

        # Inner loop to find the maximum element in the remaining unsorted portion of the array
        for j in range(i + 1, 5):
            # If a larger element is found, update max and max_j
            if max < io[j]:
                max = io[j]
                max_j = j

        # Swap the found maximum element with the current element
        buf = io[i]
        io[i] = io[max_j]
        io[max_j] = buf

        # Print the current element, ensuring proper formatting for the last element
        if i < 4:
            print(io[i], end=" ")
        else:
            print(io[i])

    return 0 # Indicate that the program ended successfully
}
