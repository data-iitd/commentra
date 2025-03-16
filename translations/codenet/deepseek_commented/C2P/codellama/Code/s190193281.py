#include<stdio.h>

# Define constants for the maximum sizes of arrays S and T
N = 1000000
Q = 50000

# Declare variables
n = 0
S = [0] * N
T = [0] * Q

# Function to perform binary search on array S
def binarySearch(key):
    left = 0
    right = n
    while left < right:
        mid = (left + right) // 2
        if S[mid] == key:
            return 1
        elif key < S[mid]:
            right = mid
        else:
            left = mid + 1
    return 0

# Main function
def main():
    i = 0
    q = 0
    c = 0

    # Read the size of array S
    n = int(input())
    for i in range(n):
        S[i] = int(input())

    # Read the size of array T
    q = int(input())
    for i in range(q):
        T[i] = int(input())

    # Perform binary search on array S for each element of array T
    for i in range(q):
        if binarySearch(T[i]) == 1:
            c += 1

    # Print the count of elements in T that are also in S
    print(c)

# End of code
