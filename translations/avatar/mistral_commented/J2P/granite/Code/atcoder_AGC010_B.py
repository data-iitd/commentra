

import sys

def main():
    # Read the number of elements in the array from standard input
    N = int(input())

    # Allocate memory for the array A of size N
    A = []

    # Read each element of the array A from standard input
    for i in range(N):
        A.append(int(input()))

    # Check if the conditions for a possible solution are met
    if possible(N, A):
        # Print "YES" if the conditions are met
        print("YES")
    else:
        # Print "NO" if the conditions are not met
        print("NO")

# Check if the given conditions for a possible solution are met
def possible(N, A):
    sum = 0 # Initialize sum to 0

    # Calculate the sum of all elements in the array A
    for i in range(N):
        sum += A[i]

    # Calculate the expected sum based on the number of elements in the array
    NS = N * (N + 1) // 2

    # Check if the sum of all elements is equal to the expected sum
    if sum % NS!= 0:
        return False

    # Calculate the common difference between consecutive elements
    K = sum // NS

    # Check each pair of consecutive elements to see if their difference is valid
    for i in range(N):
        j = (i - 1) % N
        d = K - (A[i] - A[j]) # Calculate the difference

        # Check if the difference is valid
        if d < 0 or d % N!= 0:
            return False

    # If all checks pass, return true
    return True

# Call the main function
if __name__ == "__main__":
    main()

