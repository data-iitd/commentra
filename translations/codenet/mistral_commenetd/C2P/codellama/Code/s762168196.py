
#include <stdio.h>

# Declare variables
a = [10000]
min = 0
max = 0
n = 0
i = 0
sum = 0

def main():
    # Read the number of elements in the array
    print("Enter the number of elements in the array: ")
    n = int(input())

    # Initialize a for loop to read elements into the array and calculate sum
    for i in range(n):
        # Read each element into the array
        print("Enter element %d: " % (i + 1))
        a[i] = int(input())

        # Add the current element to the sum
        sum += a[i]

    # Initialize a for loop to find minimum and maximum elements in the array
    for i in range(1, n):
        # Initialize min and max with the first element of the array
        if a[i] > max:
            max = a[i]
        if a[i] < min:
            min = a[i]

    # Print the minimum, maximum, and sum
    print("Minimum element is %d" % min)
    print("Maximum element is %d" % max)
    print("Sum of all elements is %lld" % sum)

    # Return 0 to indicate successful execution
    return 0

if __name__ == "__main__":
    main()

