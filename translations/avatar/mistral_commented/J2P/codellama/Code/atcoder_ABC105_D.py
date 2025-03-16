
import sys
import math

def solve(testNumber, in, out):
    # Read input
    n = int(in.readline()) # Number of elements in array a
    m = int(in.readline()) # Modulus value

    # Initialize data structures
    a = [int(x) for x in in.readline().split()] # Read array a
    dp = {} # Hashmap to store intermediate results

    # Initialize variables
    ans = 0 # Answer variable
    base = 0 # Base value for hashmap key

    # Process each element in array a
    for i in range(n):
        # Update base value
        base = (base - a[i] % m + m) % m

        # Update hashmap with current base and its count
        dp[base + a[i] % m] = dp.get(base + a[i] % m, 0) + 1

        # Update answer variable
        ans += dp.get(base, 0)

    # Print the answer
    out.write(str(ans) + '\n')

if __name__ == '__main__':
    solve(1, sys.stdin, sys.stdout)

