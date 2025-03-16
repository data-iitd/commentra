#include <stdio.h>
#include <stdlib.h>

int main() {
    # Declare variables for the number of elements and a pointer for dynamic array allocation
    n = int(input())
    data = (int*)malloc(sizeof(int) * n)

    # Read 'n' integers from user input into the allocated array
    for i in range(n):
        data[i] = int(input())

    # Initialize variables to find the maximum value and its index
    max = 0
    index = 0

    # Find the maximum value in the array and its index
    for i in range(n):
        if data[i] > max:
            max = data[i]
            index = i

    # Initialize a variable to calculate the sum of all elements except the maximum
    a = 0

    # Calculate the sum of all elements excluding the maximum value
    for i in range(n):
        if i != index:
            a += data[i]

    # Compare the sum of the other elements with the maximum value and print the result
    if a > max:
        print("Yes")
    else:
        print("No")

    # Free the allocated memory
    free(data)

    return 0
}

