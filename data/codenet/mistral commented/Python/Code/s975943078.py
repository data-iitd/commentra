# Import necessary modules
import sys
from bisect import bisect_left

# Function to solve the problem
def solve():
    # Initialize input reading and parsing
    input = sys.stdin.readline
    N, K = map(int, input().split())

    # Initialize list A and precompute sum_A
    A = [(int(a) % K) - 1 for a in input().split()]
    sum_A = [0 for _ in range(N + 1)]

    # Initialize variables and data structures
    count = 0
    modK = {}  # dictionary to store the sums of A and their indices
    modK[0] = [0]  # special case for sum_A[0]

    # Process the list A and update sum_A and modK
    for i in range(N):
        # Update sum_A[i+1]
        sum_A[i + 1] = (sum_A[i] + A[i]) % K

        # Update modK[sum_A[i+1]]
        if sum_A[i+1] not in modK:
            modK[sum_A[i+1]] = [i + 1]
        else:
            # Append i+1 to the list of indices with the same sum
            modK[sum_A[i+1]].append(i+1)

    # Compute the answer
    for key in modK:
        lenK = len(modK[key])
        for i, a in enumerate(modK[key]):
            # Compute the number of elements in modK[key] that are greater than a+K
            count += bisect_left(modK[key], a + K, i, lenK) - i - 1

    # Print the answer
    print(count)

# Run the function if the script is executed directly
if __name__ == "__main__":
    solve()
