#include <stdio.h>

int main(void) {
    # Declare variables for loop index, input values, and a product variable
    i, a, b, s = 0, 0, 0, 0
    # Array to count occurrences of each number (1 to 4)
    count = [0] * 4

    # Initialize the count array to zero
    for i in range(4):
        count[i] = 0

    # Read pairs of integers and update their counts
    for i in range(3):
        # Read two integers from input
        a, b = map(int, input().split())
        # Increment the count for each integer read
        count[a - 1] += 1
        count[b - 1] += 1

    # Initialize the product variable
    s = 1
    # Calculate the product of counts
    for i in range(4):
        s *= count[i]

    # Check if the product equals 4, indicating each number appears at least once
    if s == 4:
        print("YES") # Output YES if all numbers are present
    else:
        print("NO")  # Output NO if any number is missing

    return 0 # End of the program
}
