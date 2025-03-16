# Import necessary libraries
import sys
from collections import defaultdict

# Define constants
mod = 10**9 + 7

def main():
    # Input: Read the values of N and K
    N, K = map(int, sys.stdin.readline().split())  # N is the size of the array, K is a parameter
    A = list(map(int, sys.stdin.readline().split()))  # Read N elements into array A

    # Solution: Calculate the number of inversions in the array
    ans1 = 0  # Initialize the count of inversions
    for i in range(N):  # Iterate through each element
        for j in range(i + 1, N):  # Compare with every other element
            if A[i] > A[j]:  # Count inversion if A[i] > A[j]
                ans1 += 1  # Increment inversion count
                ans1 %= mod  # Take modulo to prevent overflow

    # Count occurrences of each element in the array
    count = [0] * 2005  # Initialize a count array to store frequencies
    for i in range(N):  # Iterate through the array
        count[A[i] - 1] += 1  # Increment the count for the corresponding value

    # Calculate the second part of the answer based on the counts
    ans2 = 0  # Initialize the second answer
    remain = N  # Remaining elements to consider
    for i in range(2005):  # Iterate through the count array
        remain -= count[i]  # Decrease the remaining count by the current count
        ans2 += count[i] * remain  # Calculate pairs of inversions
        ans2 %= mod  # Take modulo

    # Calculate the final answer based on ans1 and ans2
    ans = 0  # Initialize the final answer
    tmp = K * (K - 1) // 2  # Calculate the number of ways to choose 2 from K
    tmp %= mod  # Take modulo
    tmp *= ans2  # Multiply by the second answer
    tmp %= mod  # Take modulo again
    ans += ans1 * K  # Add the contribution from ans1
    ans %= mod  # Take modulo
    ans += tmp  # Add the contribution from tmp
    ans %= mod  # Take modulo

    # Output: Print the final answer
    print(ans)  # Output the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
