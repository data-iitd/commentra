# Import necessary libraries
import sys
from collections import defaultdict

# Define constants
mod = 10**9 + 7

def main():
    # Input
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    # Solution
    ans1 = 0
    for i in range(N):
        for j in range(N):
            if i >= j: 
                continue  # Skip if i is not less than j
            if A[i] > A[j]: 
                ans1 += 1  # Increment ans1 if A[i] > A[j]
            ans1 %= mod  # Take modulo to prevent overflow

    # Count the frequency of each element in the array A
    count = [0] * 2005
    for i in range(N):
        count[A[i] - 1] += 1  # Store frequency of A[i]

    ans2 = 0
    remain = N
    for i in range(2005):
        remain -= count[i]  # Reduce the remaining count
        ans2 += count[i] * remain  # Calculate the number of valid pairs

    # Calculate the final answer
    tmp = K * (K - 1) // 2  # Calculate K*(K-1)/2
    tmp %= mod  # Take modulo to prevent overflow
    tmp *= ans2  # Multiply with ans2
    tmp %= mod  # Take modulo to prevent overflow
    ans = 0
    ans += ans1 * K  # Add contribution from ans1
    ans %= mod  # Take modulo to prevent overflow
    ans += tmp  # Add contribution from tmp
    ans %= mod  # Take modulo to prevent overflow

    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
