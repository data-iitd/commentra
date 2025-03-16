#include <stdio.h>

int main()
{
    # Declare an array to hold up to 1000 integers and variables for size and counters
    a = [0] * 1000
    n = 0
    i = 0
    j = 0
    d = 0

    # Read the number of elements to be sorted
    n = int(input())

    # Read the elements into the array
    for i in range(n):
        a[i] = int(input())

    # Perform a bubble sort on the array
    for i in range(n):
        # Inner loop for comparing adjacent elements
        for j in range(n - 1, i, -1):
            # If the current element is less than the previous one, swap them
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                d += 1 # Increment the swap counter

    # Print the sorted array
    print(a[0], end="") # Print the first element
    for i in range(1, n):
        print(" ", a[i], end="") # Print the remaining elements
    
    # Print the total number of swaps made during sorting
    print("\n", d)
    
    return 0 # Return success
}

