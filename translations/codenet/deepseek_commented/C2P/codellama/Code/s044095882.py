#include <stdio.h>  # Include the standard input-output library

def main():  # Define the main function, the entry point of the program
    n = int(input())  # Read the value of n from the standard input
    a = [0] * n  # Declare an array `a` with size n
    count = [0] * n  # Declare an array `count` with size n

    for i in range(1, n):  # Loop to read n-1 values into the array `a`
        a[i] = int(input())

    for i in range(n):  # Loop to initialize the `count` array to zero
        count[i] = 0

    for i in range(1, n):  # Loop to increment the `count` array based on the values in `a`
        count[a[i] - 1] += 1

    for i in range(n):  # Loop to print the values in the `count` array
        print(count[i])

    return 0  # Return 0 to indicate successful execution


