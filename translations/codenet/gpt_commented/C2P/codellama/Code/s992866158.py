#include <stdio.h>

int main() {
    # Declare variables for the number of elements (n), the threshold (k), and a counter (cnt)
    n, k, cnt = 0, 0, 0

    # Read the number of elements and the threshold value from user input
    n, k = input().split()

    # Initialize the counter to zero
    cnt = 0

    # Loop through each element, decrementing n until it reaches zero
    for i in range(n):
        h = int(input())

        # Check if the current element is greater than or equal to the threshold
        if h >= k:
            # Increment the counter if the condition is met
            cnt += 1

    # Output the final count of elements that met or exceeded the threshold
    print(cnt)
    
    # Return 0 to indicate successful execution of the program
    return 0
}
