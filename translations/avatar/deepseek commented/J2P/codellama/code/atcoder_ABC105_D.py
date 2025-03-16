import sys
import math

def solve(testNumber, in, out):
    # Read the number of elements and the modulo value
    n, m = map(int, in.readline().split())
    
    # Read the array of elements
    a = list(map(int, in.readline().split()))
    
    # HashMap to store the frequency of remainders
    dp = {}
    
    # Initialize the answer and base variable
    ans = 0
    base = 0
    
    # Iterate through the array to calculate the answer
    for i in range(n):
        # Update the base variable
        base = (base - a[i] % m + m) % m
        
        # Update the frequency of remainders in the HashMap
        dp[base + a[i]] = dp.get(base + a[i], 0) + 1
        
        # Add the frequency of the current remainder to the answer
        ans += dp.get(base, 0)
    
    # Print the final answer
    out.write(str(ans) + '\n')

if __name__ == '__main__':
    # Read the input
    in = sys.stdin
    out = sys.stdout
    
    # Read the number of test cases
    t = int(in.readline())
    
    # Iterate through the test cases
    for testNumber in range(1, t + 1):
        solve(testNumber, in, out)

# 