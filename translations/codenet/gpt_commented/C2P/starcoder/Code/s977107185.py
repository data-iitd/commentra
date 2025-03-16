#include<stdio.h>

def bubbleSort(A):
    count = 0
    for i in range(len(A)):
        for j in range(len(A) - 1):
            if A[j] > A[j + 1]:
                A[j], A[j + 1] = A[j + 1], A[j]
                count += 1
    return count

def main():
    # Declare variables
    N = int(input())
    A = [int(x) for x in input().split()]

    # Perform bubble sort on the array A
    count = bubbleSort(A)

    # Output the sorted array
    for i in range(len(A)):
        print(A[i], end = " ")

    # Print a newline after the sorted array
    print()

    # Print the total number of swaps made during sorting
    print(count)

if __name__ == "__main__":
    main()

