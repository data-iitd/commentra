import sys
from typing import List

def main():
    N = int(input())  # Read the number of elements from the standard input
    A = list(map(int, input().split()))  # Read the elements into a list A
    A.sort(reverse=True)  # Sort the list A in descending order

    index = 0  # Variable to store the index of the second smallest element
    max_diff = float('inf')  # Initialize the maximum difference to an infinite value

    for i in range(1, N):  # Iterate through the range [1, N)
        if max_diff > abs(A[0] - 2 * A[i]):  # Check if the current difference is greater than the maximum difference
            max_diff = abs(A[0] - 2 * A[i])  # Update the maximum difference if it is
            index = i  # Update the index of the second smallest element

    print(A[0], A[index])  # Output the largest and the second largest elements

if __name__ == "__main__":
    main()

# <END-OF-CODE>
