#include<stdio.h>

# Function to print the array elements
def white(n, A):
    for i in range(n - 1):
        print(A[i], end=" ")
    print(A[i])

# Function to perform insertion sort on the array
def insertionsort(n, A):
    for i in range(n):
        for j in range(i):
            if A[i] < A[j]:
                # Swap A[i] and A[j]
                a = A[i]
                A[i] = A[j]
                A[j] = a
        # Print the array after each insertion
        white(n, A)

# Main function to handle input and call the sorting function
def main():
    n = int(input())
    A = list(map(int, input().split()))
    insertionsort(n, A)

if __name__ == "__main__":
    main()

