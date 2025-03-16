# Define types and macros for convenience
from typing import List, Tuple, Dict, Set

# Define a function to calculate the number of inversions
def count_inversions(A: List[int], mod: int) -> int:
    N = len(A)
    ans1 = 0
    for i in range(N):
        for j in range(N):
            if i >= j:
                continue
            if A[i] > A[j]:
                ans1 += 1
                ans1 %= mod
    return ans1

# Main function
def main():
    # Input: Read the values of N and K
    N, K = map(int, input().split())  # N is the size of the array, K is a parameter
    A = list(map(int, input().split()))  # Read N elements into array A

    # Solution: Calculate the number of inversions in the array
    mod = 10**9 + 7  # Define a modulus value for calculations
    ans1 = count_inversions(A, mod)  # Calculate the number of inversions

    # Count occurrences of each element in the array
    count = [0] * 2005  # Initialize a count array to store frequencies
    for a in A:
        count[a - 1] += 1

    # Calculate the second part of the answer based on the counts
    ans2 = 0
    remain = N
    for i in range(2005):
        remain -= count[i]
        ans2 += count[i] * remain

    # Calculate the final answer based on ans1 and ans2
    ans = 0
    tmp = K * (K - 1) // 2
    tmp %= mod
    tmp *= ans2
    tmp %= mod
    ans += ans1 * K
    ans %= mod
    ans += tmp
    ans %= mod

    # Output: Print the final answer
    print(ans)  # Output the result

# Call the main function
main()
