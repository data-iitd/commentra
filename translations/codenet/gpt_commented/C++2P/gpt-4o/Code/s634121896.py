import sys
from collections import defaultdict

# Constants
MOD = 10**9 + 7

def fast_io():
    input = sys.stdin.read
    return input().splitlines()

def solve():
    n = int(input())  # Number of elements
    nums = list(map(int, input().split()))  # Input each element
    
    # Dynamic programming array to store results
    dp = [0] * (n + 1)
    dp[0] = 1  # Base case: one way to select zero elements
    kek = defaultdict(int)  # Map to store the last occurrence of each number
    prev = {}  # Map to store the previous index of each number
    
    # Fill the dynamic programming array
    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + (kek[nums[i - 1]] if prev.get(nums[i - 1], -1) != i - 1 else 0)
        dp[i] %= MOD  # Apply modulus to avoid overflow
        kek[nums[i - 1]] = dp[i]  # Update the last occurrence
        prev[nums[i - 1]] = i  # Update the previous index
    
    print(dp[n])  # Output the result

# Main function
if __name__ == "__main__":
    input = fast_io()  # Optimize input/output
    solve()  # Solve the problem
