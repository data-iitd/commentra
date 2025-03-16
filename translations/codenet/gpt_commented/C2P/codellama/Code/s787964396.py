#include<stdio.h>
#include<stdlib.h>
#define I 10000 // Define a constant for the maximum range of input values

# Function prototype for CountingSort
def CountingSort(a, b, n):
    c = [0] * (I + 1)

    # Count occurrences of each element in array 'a'
    for j in range(n):
        c[a[j + 1]] += 1

    # Update the counting array 'c' to contain the actual positions of elements
    for i in range(1, I + 1):
        c[i] += c[i - 1]

    # Build the output array 'b' using the counting array 'c'
    for j in range(n - 1, -1, -1):
        b[c[a[j]]] = a[j]
        c[a[j]] -= 1

# Main function
def main():
    a, b, i, max, n = 0, 0, 0, 0, 0

    # Read the number of elements to be sorted
    n = int(input())

    # Allocate memory for the input array 'a' and output array 'b'
    a = [0] * (n + 1)
    b = [0] * (n + 1)

    # Read 'n' elements into the array 'a'
    for i in range(n):
        a[i + 1] = int(input())

    # Call the CountingSort function to sort the array 'a' and store the result in 'b'
    CountingSort(a, b, n)

    # Print the sorted elements from array 'b'
    print(b[1], end=" ")
    for i in range(2, n + 1):
        print(b[i], end=" ")
    print()

# Main function call
main()

