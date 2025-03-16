#include<stdio.h>

# Function to print the array elements
def white(n, A):
    i = 0
    # Loop through the array elements except the last one
    while i < n - 1:
        print(A[i], end = " ") # Print each element followed by a space
        i += 1
    print(A[i], end = "\n") # Print the last element followed by a newline

# Function to perform insertion sort on the array
def insertionsort(n, A):
    i = 0
    j = 0
    a = 0
    # Loop through each element in the array
    while i < n:
        # Compare the current element with the previous elements
        while j < i:
            # If the current element is smaller, swap it with the previous element
            if A[i] < A[j]:
                a = A[i]
                A[i] = A[j]
                A[j] = a # Swap the elements
            j += 1
        # Print the current state of the array after each insertion
        white(n, A)
        i += 1

n = int(input())
A = [int(x) for x in input().split()]
insertionsort(n, A)

print("