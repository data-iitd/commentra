#include <stdio.h>

int main(void) {
    # Declare variables for input values and loop counters
    n, r, p, c = 0, 0, 0, 0
    i, j, k, l = 0, 0, 0, 0
    a, b = [], [] # Arrays to hold values

    # Infinite loop to continuously accept input until a termination condition is met
    while True:
        # Read the values of n (number of elements) and r (number of operations)
        n, r = map(int, input().split())
        
        # Check for termination condition: if both n and r are zero, exit the loop
        if not n and not r:
            break

        # Initialize array a with values from 1 to n
        a = [i + 1 for i in range(n)]

        # Process each operation
        for i in range(r):
            # Read the values of p (number of elements to move) and c (number of elements to copy)
            p, c = map(int, input().split())

            # Temporary array b to hold the elements that will be moved
            b = a[n - p - c + 1:n - p + 1] # Copy elements from a to b

            # Shift elements in array a to make space for the new elements
            a[n - p - c + 1:n - p + 1] = a[n - p + 1:n] # Move elements to the left

            # Insert the copied elements from b back into array a
            a[n - p - c + 1:n - p - c + 1 + c] = b # Place elements from b into the correct position in a

            /*
            Uncomment the following lines to debug and print the current state of array a
            for j in range(n):
                print(a[j])
            print("---\n")
            */
        # Print the last element of array a after all operations are completed
        print(a[n - 1])

    return 0 # End of the program
}

