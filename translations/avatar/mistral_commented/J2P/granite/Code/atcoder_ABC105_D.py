

import sys # Input/output stream for reading/writing input/output
from collections import defaultdict # Hashmap for storing intermediate results

def main():
    # Read input
    n, m = map(int, sys.stdin.readline().split()) # Read number of elements and modulus value
    a = list(map(int, sys.stdin.readline().split())) # Read array a

    # Initialize data structures
    dp = defaultdict(int) # Hashmap to store intermediate results
    ans = 0 # Answer variable
    base = 0 # Base value for hashmap key

    # Process each element in array a
    for i in range(n):
        # Update base value
        base = (base - a[i] % m + m) % m

        # Update hashmap with current base and its count
        dp[base + a[i] % m] += 1

        # Update answer variable
        ans += dp[base]

    # Print the answer
    print(ans)

if __name__ == "__main__":
    main() # Call the main function to start the program

