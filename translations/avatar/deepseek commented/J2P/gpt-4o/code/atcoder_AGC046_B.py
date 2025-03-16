MOD = 998244353

def solve(A, B, C, D):
    dp = [[0] * 3001 for _ in range(3001)]
    
    # Initialize the dp array for the starting point (A, B)
    dp[A][B] = 1

    # Iterate over the range from A to C and from B to D
    for c in range(A, C + 1):
        for d in range(B, D + 1):
            # Skip the starting point (A, B)
            if c == A and d == B:
                continue

            # Calculate the answer based on previous states
            ans = 0
            if c > A:
                part = dp[c - 1][d]
                ans = (part * d) % MOD
            if d > B:
                part = dp[c][d - 1]
                ans = (ans + (part * c) % MOD) % MOD
            if c > A and d > B:
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1) % MOD) + MOD) % MOD

            # Store the result in dp array
            dp[c][d] = ans

    # Output the result for the final state (C, D)
    return dp[C][D]

# Main method to set up input/output and call the solve method
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    A, B, C, D = map(int, data)
    result = solve(A, B, C, D)
    print(result)

# <END-OF-CODE>
